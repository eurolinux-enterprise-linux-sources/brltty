/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2009 by The BRLTTY Developers.
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any
 * later version. Please see the file LICENSE-GPL for details.
 *
 * Web Page: http://mielke.cc/brltty/
 *
 * This software is maintained by Dave Mielke <dave@mielke.cc>.
 */

#include "prologue.h"

#include <string.h>
#include <errno.h>

#include "misc.h"

#include "brl_driver.h"

typedef enum {
  IPT_identity,
  IPT_keys,
  IPT_routing
} InputPacketType;

typedef enum {
  KEY_K1 = 0X0001,
  KEY_K7 = 0X0002,
  KEY_K8 = 0X0004,
  KEY_K6 = 0X0008,
  KEY_K5 = 0X0010,
  KEY_K2 = 0X0200,
  KEY_K3 = 0X0800,
  KEY_K4 = 0X1000,
} BrailleKeys;

typedef struct {
  unsigned char bytes[24];
  unsigned char type;

  union {
    BrailleKeys keys;
    const unsigned char *routing;

    struct {
      unsigned int version;
      unsigned char model;
      unsigned char size;
    } identity;
  } fields;
} InputPacket;

typedef struct {
  const char *name;
  int (*readPacket) (BrailleDisplay *brl, InputPacket *packet);
  int (*probeDisplay) (BrailleDisplay *brl, InputPacket *response);
  int (*writeCells) (BrailleDisplay *brl);
} ProtocolOperations;
static const ProtocolOperations *protocol;

typedef struct {
  const ProtocolOperations *const *protocols;
  int (*openPort) (const char *device);
  void (*closePort) ();
  int (*awaitInput) (int milliseconds);
  int (*readBytes) (unsigned char *buffer, int length, int wait);
  int (*writeBytes) (const unsigned char *buffer, int length);
} InputOutputOperations;
static const InputOutputOperations *io;

static const int logInputPackets = 0;
static const int logOutputPackets = 0;

#define SERIAL_BAUD 9600
static const int charactersPerSecond = SERIAL_BAUD / 10;

static int routingCommand;
static TranslationTable outputTable;
static unsigned char textCells[40];

static int
readByte (unsigned char *byte, int wait) {
  int count = io->readBytes(byte, 1, wait);
  if (count > 0) return 1;

  if (count == 0) errno = EAGAIN;
  return 0;
}

static int
writeBytes (BrailleDisplay *brl, const unsigned char *buffer, size_t length) {
  if (logOutputPackets) LogBytes(LOG_DEBUG, "Output Packet", buffer, length);
  if (io->writeBytes(buffer, length) == -1) return 0;
  brl->writeDelay += (length * 1000 / charactersPerSecond) + 1;
  return 1;
}

static int
probeDisplay (
  BrailleDisplay *brl, InputPacket *response,
  const unsigned char *requestAddress, size_t requestSize
) {
  int probeCount = 0;

  do {
    if (!writeBytes(brl, requestAddress, requestSize)) break;

    while (io->awaitInput(200)) {
      if (!protocol->readPacket(NULL, response)) break;
      if (response->type == IPT_identity) return 1;
    }
    if (errno != EAGAIN) break;
  } while (++probeCount < 3);

  return 0;
}

typedef enum {
  TBT_ANY = 0X80,
  TBT_DECIMAL,
  TBT_KEYS
} TemplateByteType;

typedef struct {
  const unsigned char *bytes;
  unsigned char length;
  unsigned char type;
} TemplateEntry;

#define TEMPLATE_ENTRY(name) { \
  .bytes=templateString_##name, \
  .length=sizeof(templateString_##name), \
  .type=IPT_##name \
}

static const unsigned char templateString_keys[] = {
  TBT_KEYS, TBT_KEYS
};
static const TemplateEntry templateEntry_keys = TEMPLATE_ENTRY(keys);

static const unsigned char templateString_routing[] = {
  0X00, 0X08, 0X09, 0X00, 0X00, 0X00, 0X00,
  TBT_ANY, TBT_ANY, TBT_ANY, TBT_ANY, TBT_ANY,
  0X00, 0X08, 0X09, 0X00, 0X00, 0X00, 0X00,
  0X00, 0X00, 0X00, 0X00, 0X00
};
static const TemplateEntry templateEntry_routing = TEMPLATE_ENTRY(routing);

static int
readPacket_old (
  InputPacket *packet,
  const TemplateEntry *identityTemplate,
  const TemplateEntry *alternateTemplate,
  void (*interpretIdentity) (InputPacket *packet)
) {
  const TemplateEntry *const templateTable[] = {
    identityTemplate,
    &templateEntry_routing,
    NULL
  };

  const TemplateEntry *template = NULL;
  int offset = 0;

  while (1) {
    unsigned char byte;

    {
      int started = offset > 0;
      if (!readByte(&byte, started)) {
        if (started) LogBytes(LOG_WARNING, "Partial Packet", packet->bytes, offset);
        return 0;
      }
    }

  gotByte:
    if (!offset) {
      const TemplateEntry *const *templateAddress = templateTable;

      while ((template = *templateAddress++))
        if (byte == *template->bytes)
          break;

      if (!template) {
        if ((byte & 0XE0) == 0X60) {
          template = &templateEntry_keys;
        } else {
          LogBytes(LOG_WARNING, "Ignored Byte", &byte, 1);
          template = NULL;
          continue;
        }
      }
    } else {
      int unexpected = 0;

      switch (template->bytes[offset]) {
        case TBT_ANY:
          break;

        case TBT_DECIMAL:
          if ((byte < '0') || (byte > '9')) unexpected = 1;
          break;

        case TBT_KEYS:
          if ((byte & 0XE0) != 0XE0) unexpected = 1;
          break;

        default:
          if (byte != template->bytes[offset]) unexpected = 1;
          break;
      }

      if (unexpected) {
        if ((offset == 1) && (template->type == IPT_identity)) {
          template = alternateTemplate;
        } else {
          LogBytes(LOG_WARNING, "Short Packet", packet->bytes, offset);
          offset = 0;
          template = NULL;
        }

        goto gotByte;
      }
    }

    packet->bytes[offset++] = byte;
    if (template && (offset == template->length)) {
      if (logInputPackets) LogBytes(LOG_DEBUG, "Input Packet", packet->bytes, offset);

      switch ((packet->type = template->type)) {
        case IPT_identity:
          interpretIdentity(packet);
          break;

        case IPT_keys: {
          const unsigned char *byte = packet->bytes + offset;
          packet->fields.keys = 0;

          do {
            packet->fields.keys <<= 8;
            packet->fields.keys |= *--byte & 0X1F;
          } while (byte != packet->bytes);

          break;
        }

        case IPT_routing:
          packet->fields.routing = &packet->bytes[7];
          break;
      }

      return offset;
    }
  }
}

static void
interpretIdentity_330 (InputPacket *packet) {
  packet->fields.identity.version = ((packet->bytes[5] - '0') << (4 * 2)) |
                                    ((packet->bytes[7] - '0') << (4 * 1));
  packet->fields.identity.model = 0;
  packet->fields.identity.size = packet->bytes[2];
}

static int
readPacket_330 (BrailleDisplay *brl, InputPacket *packet) {
  static const unsigned char templateString_identity[] = {
    0X00, 0X05, 0X28, 0X08,
    0X76, TBT_DECIMAL, 0X2E, TBT_DECIMAL,
    0X01, 0X01, 0X01, 0X01
  };
  static const TemplateEntry identityTemplate = TEMPLATE_ENTRY(identity);

  return readPacket_old(packet, &identityTemplate, &templateEntry_routing, interpretIdentity_330);
}

static int
probeDisplay_330 (BrailleDisplay *brl, InputPacket *response) {
  static const unsigned char request[] = {0XFF, 0XFF, 0X0A};
  return probeDisplay(brl, response, request, sizeof(request));
}

static int
writeCells_330 (BrailleDisplay *brl) {
  static const unsigned char header[] = {
    0XFF, 0XFF, 0X04,
    0X00, 0X63, 0X00
  };

  unsigned char packet[sizeof(header) + 2 + (brl->textColumns * 2)];
  unsigned char *byte = packet;

  memcpy(byte, header, sizeof(header));
  byte += sizeof(header);

  *byte++ = brl->textColumns * 2;
  *byte++ = 0;

  {
    int i;
    for (i=0; i<brl->textColumns; i+=1) {
      *byte++ = 0;
      *byte++ = outputTable[textCells[i]];
    }
  }

  return writeBytes(brl, packet, byte-packet);
}

static const ProtocolOperations protocolOperations_330 = {
  "V3.30",
  readPacket_330,
  probeDisplay_330,
  writeCells_330
};

static void
interpretIdentity_331 (InputPacket *packet) {
  packet->fields.identity.version = ((packet->bytes[8] - '0') << (4 * 2)) |
                                    ((packet->bytes[10] - '0') << (4 * 1)) |
                                    ((packet->bytes[11] - '0') << (4 * 0));
  packet->fields.identity.model = packet->bytes[5] - '0';
  packet->fields.identity.size = 40;
}

static int
readPacket_331 (BrailleDisplay *brl, InputPacket *packet) {
  static const unsigned char templateString_identity[] = {
    0X73, 0X65, 0X69, 0X6B, 0X61, TBT_DECIMAL,
    0X20, 0X76, TBT_DECIMAL, 0X2E, TBT_DECIMAL, TBT_DECIMAL
  };
  static const TemplateEntry identityTemplate = TEMPLATE_ENTRY(identity);

  return readPacket_old(packet, &identityTemplate, &templateEntry_keys, interpretIdentity_331);
}

static int
probeDisplay_331 (BrailleDisplay *brl, InputPacket *response) {
  static const unsigned char request[] = {0XFF, 0XFF, 0X1C};
  return probeDisplay(brl, response, request, sizeof(request));
}

static int
writeCells_331 (BrailleDisplay *brl) {
  static const unsigned char header[] = {
    0XFF, 0XFF,
    0X73, 0X65, 0X69, 0X6B, 0X61,
    0X00
  };

  unsigned char packet[sizeof(header) + (brl->textColumns * 2)];
  unsigned char *byte = packet;

  memcpy(byte, header, sizeof(header));
  byte += sizeof(header);

  {
    int i;
    for (i=0; i<brl->textColumns; i+=1) {
      *byte++ = 0;
      *byte++ = outputTable[textCells[i]];
    }
  }

  return writeBytes(brl, packet, byte-packet);
}

static const ProtocolOperations protocolOperations_331 = {
  "V3.31",
  readPacket_331,
  probeDisplay_331,
  writeCells_331
};

static inline int
routingBytes_332 (BrailleDisplay *brl) {
  return (brl->textColumns + 7) / 8;
}

static int
readPacket_332 (BrailleDisplay *brl, InputPacket *packet) {
  int offset = 0;
  int length = 0;

  while (1) {
    unsigned char byte;

    {
      int started = offset > 0;
      if (!readByte(&byte, started)) {
        if (started) LogBytes(LOG_WARNING, "Partial Packet", packet->bytes, offset);
        return 0;
      }
    }

  gotByte:
    if (!offset) {
      switch (byte) {
        case 0X1D:
          length = 2;
          break;

        default:
          LogBytes(LOG_WARNING, "Ignored Byte", &byte, 1);
          continue;
      }
    } else {
      int unexpected = 0;

      if (offset == 1) {
        switch (byte) {
          case 0X02:
            packet->type = IPT_identity;
            length = 10;
            break;

          case 0X04:
            packet->type = IPT_routing;
            length = 2;
            if (brl) length += routingBytes_332(brl);
            break;

          case 0X05:
            packet->type = IPT_keys;
            length = 4;
            break;

          default:
            unexpected = 1;
            break;
        }
      }

      if (unexpected) {
        LogBytes(LOG_WARNING, "Short Packet", packet->bytes, offset);
        offset = 0;
        length = 0;
        goto gotByte;
      }
    }

    packet->bytes[offset++] = byte;
    if (offset == length) {
      if (logInputPackets) LogBytes(LOG_DEBUG, "Input Packet", packet->bytes, offset);

      switch (packet->type) {
        case IPT_identity:
          packet->fields.identity.version = 0;
          packet->fields.identity.model = packet->bytes[9] - '0';
          packet->fields.identity.size = packet->bytes[3];
          break;

        case IPT_keys: {
          const unsigned char *byte = packet->bytes + offset;
          packet->fields.keys = 0;

          do {
            packet->fields.keys <<= 8;
            packet->fields.keys |= *--byte;
          } while (byte != packet->bytes);

          break;
        }

        case IPT_routing:
          packet->fields.routing = &packet->bytes[2];
          break;
      }

      return offset;
    }
  }
}

static int
probeDisplay_332 (BrailleDisplay *brl, InputPacket *response) {
  static const unsigned char request[] = {0XFF, 0XFF, 0X1D, 0X01};
  return probeDisplay(brl, response, request, sizeof(request));
}

static int
writeCells_332 (BrailleDisplay *brl) {
  static const unsigned char header[] = {0XFF, 0XFF, 0X1D, 0X03};
  unsigned char packet[sizeof(header) + 1 + brl->textColumns];
  unsigned char *byte = packet;

  memcpy(byte, header, sizeof(header));
  byte += sizeof(header);

  *byte++ = brl->textColumns;

  {
    int i;
    for (i=0; i<brl->textColumns; i+=1) *byte++ = outputTable[textCells[i]];
  }

  return writeBytes(brl, packet, byte-packet);
}

static const ProtocolOperations protocolOperations_332 = {
  "V3.32",
  readPacket_332,
  probeDisplay_332,
  writeCells_332
};

static const ProtocolOperations *const allProtocols[] = {
  &protocolOperations_332,
  &protocolOperations_331,
  &protocolOperations_330,
  NULL
};

static const ProtocolOperations *const nativeProtocols[] = {
  &protocolOperations_332,
  &protocolOperations_331,
  NULL
};

/* Serial IO */
#include "io_serial.h"

static SerialDevice *serialDevice = NULL;

static int
openSerialPort (const char *device) {
  if ((serialDevice = serialOpenDevice(device))) {
    if (serialRestartDevice(serialDevice, SERIAL_BAUD)) return 1;

    serialCloseDevice(serialDevice);
    serialDevice = NULL;
  }

  return 0;
}

static void
closeSerialPort (void) {
  if (serialDevice) {
    serialCloseDevice(serialDevice);
    serialDevice = NULL;
  }
}

static int
awaitSerialInput (int milliseconds) {
  return serialAwaitInput(serialDevice, milliseconds);
}

static int
readSerialBytes (unsigned char *buffer, int count, int wait) {
  const int timeout = 100;
  return serialReadData(serialDevice, buffer, count,
                        (wait? timeout: 0), timeout);
}

static int
writeSerialBytes (const unsigned char *buffer, int length) {
  return serialWriteData(serialDevice, buffer, length);
}

static const InputOutputOperations serialOperations = {
  nativeProtocols,
  openSerialPort, closeSerialPort,
  awaitSerialInput, readSerialBytes, writeSerialBytes
};

#ifdef ENABLE_USB_SUPPORT
/* USB IO */
#include "io_usb.h"

static UsbChannel *usbChannel = NULL;

static int
openUsbPort (const char *device) {
  static const SerialParameters serial = {
    .baud = SERIAL_BAUD,
    .flow = SERIAL_FLOW_NONE,
    .data = 8,
    .stop = 1,
    .parity = SERIAL_PARITY_NONE
  };

  static const UsbChannelDefinition definitions[] = {
    { /* Seika */
      .vendor=0X10C4, .product=0XEA60,
      .configuration=1, .interface=0, .alternative=0,
      .inputEndpoint=1, .outputEndpoint=1,
      .serial=&serial
    }
    ,
    { .vendor=0 }
  };

  if ((usbChannel = usbFindChannel(definitions, (void *)device))) {
    return 1;
  }
  return 0;
}

static void
closeUsbPort (void) {
  if (usbChannel) {
    usbCloseChannel(usbChannel);
    usbChannel = NULL;
  }
}

static int
awaitUsbInput (int milliseconds) {
  return usbAwaitInput(usbChannel->device,
                       usbChannel->definition.inputEndpoint,
                       milliseconds);
}

static int
readUsbBytes (unsigned char *buffer, int length, int wait) {
  const int timeout = 100;
  int count = usbReapInput(usbChannel->device,
                           usbChannel->definition.inputEndpoint,
                           buffer, length,
                           (wait? timeout: 0), timeout);
  if (count != -1) return count;
  if (errno == EAGAIN) return 0;
  return -1;
}

static int
writeUsbBytes (const unsigned char *buffer, int length) {
  return usbWriteEndpoint(usbChannel->device,
                          usbChannel->definition.outputEndpoint,
                          buffer, length, 1000);
}

static const InputOutputOperations usbOperations = {
  allProtocols,
  openUsbPort, closeUsbPort,
  awaitUsbInput, readUsbBytes, writeUsbBytes
};
#endif /* ENABLE_USB_SUPPORT */

#ifdef ENABLE_BLUETOOTH_SUPPORT
/* Bluetooth IO */
#include "io_bluetooth.h"
#include "io_misc.h"

static int bluetoothConnection = -1;

static int
openBluetoothPort (const char *device) {
  if ((bluetoothConnection = btOpenConnection(device, 1, 0)) == -1) return 0;
  return 1;
}

static void
closeBluetoothPort (void) {
  if (bluetoothConnection != -1) {
    close(bluetoothConnection);
    bluetoothConnection = -1;
  }
}

static int
awaitBluetoothInput (int milliseconds) {
  return awaitInput(bluetoothConnection, milliseconds);
}

static int
readBluetoothBytes (unsigned char *buffer, int length, int wait) {
  const int timeout = 100;
  size_t offset = 0;
  return readChunk(bluetoothConnection,
                   buffer, &offset, length,
                   (wait? timeout: 0), timeout);
}

static int
writeBluetoothBytes (const unsigned char *buffer, int length) {
  int count = writeData(bluetoothConnection, buffer, length);
  if (count != length) {
    if (count == -1) {
      LogError("Bluetooth write");
    } else {
      LogPrint(LOG_WARNING, "Trunccated bluetooth write: %d < %d", count, length);
    }
  }
  return count;
}

static const InputOutputOperations bluetoothOperations = {
  nativeProtocols,
  openBluetoothPort, closeBluetoothPort,
  awaitBluetoothInput, readBluetoothBytes, writeBluetoothBytes
};
#endif /* ENABLE_BLUETOOTH_SUPPORT */

static int
brl_construct (BrailleDisplay *brl, char **parameters, const char *device) {
  {
    static const DotsTable dots = {0X01, 0X02, 0X04, 0X08, 0X10, 0X20, 0X40, 0X80};
    makeOutputTable(dots, outputTable);
  }
  
  if (isSerialDevice(&device)) {
    io = &serialOperations;
  } else

#ifdef ENABLE_USB_SUPPORT
  if (isUsbDevice(&device)) {
    io = &usbOperations;
  } else
#endif /* ENABLE_USB_SUPPORT */

#ifdef ENABLE_BLUETOOTH_SUPPORT
  if (isBluetoothDevice(&device)) {
    io = &bluetoothOperations;
  } else
#endif /* ENABLE_BLUETOOTH_SUPPORT */

  {
    unsupportedDevice(device);
    return 0;
  }

  if (io->openPort(device)) {
    const ProtocolOperations *const *protocolAddress = io->protocols;

    while ((protocol = *protocolAddress++)) {
      InputPacket response;

      LogPrint(LOG_DEBUG, "trying protocol %s", protocol->name);
      if (protocol->probeDisplay(brl, &response)) {
        LogPrint(LOG_DEBUG, "Seika Protocol: %s", protocol->name);
        LogPrint(LOG_DEBUG, "Seika Model: %u", response.fields.identity.model);
        LogPrint(LOG_DEBUG, "Seika Size: %u", response.fields.identity.size);

        brl->textColumns = response.fields.identity.size;
        brl->textRows = 1;
        brl->helpPage = 0;

        routingCommand = BRL_BLK_ROUTE;
        memset(textCells, 0XFF, brl->textColumns);

        return 1;
      }
    }

    io->closePort();
  }

  return 0;
}

static void
brl_destruct (BrailleDisplay *brl) {
  io->closePort();
}

static int
brl_writeWindow (BrailleDisplay *brl, const wchar_t *text) {
  if (memcmp(textCells, brl->buffer, brl->textColumns) != 0) {
    memcpy(textCells, brl->buffer, brl->textColumns);
    if (!protocol->writeCells(brl)) return 0;
  }

  return 1;
}

static int
brl_readCommand (BrailleDisplay *brl, BRL_DriverCommandContext context) {
  InputPacket packet;
  size_t length;

  while ((length = protocol->readPacket(brl, &packet))) {
    int routing = routingCommand;
    routingCommand = BRL_BLK_ROUTE;

    switch (packet.type) {
      case IPT_keys:
#define CMD(keys,cmd) case (keys): return (cmd)
#define BLK(keys,blk) case (keys): routingCommand = (blk); return BRL_CMD_NOOP
        switch (packet.fields.keys) {
          CMD(KEY_K1, BRL_CMD_FWINLT);
          CMD(KEY_K8, BRL_CMD_FWINRT);

          CMD(KEY_K2, BRL_CMD_LNUP);
          CMD(KEY_K3, BRL_CMD_LNDN);
          CMD(KEY_K2 | KEY_K3, BRL_CMD_LNBEG);

          CMD(KEY_K6, BRL_CMD_FWINLTSKIP);
          CMD(KEY_K7, BRL_CMD_FWINRTSKIP);
          CMD(KEY_K6 | KEY_K7, BRL_CMD_PASTE);

          CMD(KEY_K4, BRL_CMD_CSRTRK);
          CMD(KEY_K5, BRL_CMD_RETURN);
          CMD(KEY_K4 | KEY_K5, BRL_CMD_CSRJMP_VERT);

          CMD(KEY_K6 | KEY_K2, BRL_CMD_TOP_LEFT);
          CMD(KEY_K6 | KEY_K3, BRL_CMD_BOT_LEFT);
          CMD(KEY_K7 | KEY_K2, BRL_CMD_TOP);
          CMD(KEY_K7 | KEY_K3, BRL_CMD_BOT);

          CMD(KEY_K4 | KEY_K2, BRL_CMD_ATTRUP);
          CMD(KEY_K4 | KEY_K3, BRL_CMD_ATTRDN);
          CMD(KEY_K5 | KEY_K2, BRL_CMD_PRDIFLN);
          CMD(KEY_K5 | KEY_K3, BRL_CMD_NXDIFLN);
          CMD(KEY_K4 | KEY_K6, BRL_CMD_PRPROMPT);
          CMD(KEY_K4 | KEY_K7, BRL_CMD_NXPROMPT);
          CMD(KEY_K5 | KEY_K6, BRL_CMD_PRPGRPH);
          CMD(KEY_K5 | KEY_K7, BRL_CMD_NXPGRPH);

          BLK(KEY_K1 | KEY_K8 | KEY_K2, BRL_BLK_PRINDENT);
          BLK(KEY_K1 | KEY_K8 | KEY_K3, BRL_BLK_NXINDENT);
          BLK(KEY_K1 | KEY_K8 | KEY_K4, BRL_BLK_SETLEFT);
          BLK(KEY_K1 | KEY_K8 | KEY_K5, BRL_BLK_DESCCHAR);
          BLK(KEY_K1 | KEY_K8 | KEY_K6, BRL_BLK_PRDIFCHAR);
          BLK(KEY_K1 | KEY_K8 | KEY_K7, BRL_BLK_NXDIFCHAR);

          BLK(KEY_K1 | KEY_K8 | KEY_K2 | KEY_K6, BRL_BLK_CUTBEGIN);
          BLK(KEY_K1 | KEY_K8 | KEY_K2 | KEY_K7, BRL_BLK_CUTAPPEND);
          BLK(KEY_K1 | KEY_K8 | KEY_K3 | KEY_K6, BRL_BLK_CUTLINE);
          BLK(KEY_K1 | KEY_K8 | KEY_K3 | KEY_K7, BRL_BLK_CUTRECT);

          CMD(KEY_K1 | KEY_K2, BRL_CMD_HELP);
          CMD(KEY_K1 | KEY_K3, BRL_CMD_LEARN);
          CMD(KEY_K1 | KEY_K4, BRL_CMD_PREFLOAD);
          CMD(KEY_K1 | KEY_K5, BRL_CMD_PREFSAVE);
          CMD(KEY_K1 | KEY_K6, BRL_CMD_PREFMENU);
          CMD(KEY_K1 | KEY_K7, BRL_CMD_INFO);

          CMD(KEY_K8 | KEY_K2, BRL_CMD_DISPMD);
          CMD(KEY_K8 | KEY_K3, BRL_CMD_FREEZE);
          CMD(KEY_K8 | KEY_K6, BRL_CMD_SIXDOTS);
          CMD(KEY_K8 | KEY_K7, BRL_CMD_SKPIDLNS);

          default:
            break;
        }
#undef BLK
#undef CMD
        break;

      case IPT_routing: {
        const unsigned char *byte = packet.fields.routing;
        unsigned char bit = 0X1;
        unsigned char key;

        for (key=0; key<brl->textColumns; key+=1) {
          if (*byte & bit) return routing + key;

          if (!(bit <<= 1)) {
            bit = 0X1;
            byte += 1;
          }
        }

        break;
      }
    }

    LogBytes(LOG_WARNING, "Unexpected Packet", packet.bytes, length);
  }
  if (errno != EAGAIN) return BRL_CMD_RESTARTBRL;

  return EOF;
}

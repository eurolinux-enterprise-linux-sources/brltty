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

#include "scancodes.h"
#include "brldefs.h"

const unsigned char at2Xt[0X80] = {
  [0X76] = 0X01,
  [0X16] = 0X02,
  [0X1E] = 0X03,
  [0X26] = 0X04,
  [0X25] = 0X05,
  [0X2E] = 0X06,
  [0X36] = 0X07,
  [0X3D] = 0X08,
  [0X3E] = 0X09,
  [0X46] = 0X0A,
  [0X45] = 0X0B,
  [0X4E] = 0X0C,
  [0X55] = 0X0D,
  [0X66] = 0X0E,
  [0X0D] = 0X0F,
  [0X15] = 0X10,
  [0X1D] = 0X11,
  [0X24] = 0X12,
  [0X2D] = 0X13,
  [0X2C] = 0X14,
  [0X35] = 0X15,
  [0X3C] = 0X16,
  [0X43] = 0X17,
  [0X44] = 0X18,
  [0X4D] = 0X19,
  [0X54] = 0X1A,
  [0X5B] = 0X1B,
  [0X5A] = 0X1C,
  [0X14] = 0X1D,
  [0X1C] = 0X1E,
  [0X1B] = 0X1F,
  [0X23] = 0X20,
  [0X2B] = 0X21,
  [0X34] = 0X22,
  [0X33] = 0X23,
  [0X3B] = 0X24,
  [0X42] = 0X25,
  [0X4B] = 0X26,
  [0X4C] = 0X27,
  [0X52] = 0X28,
  [0X0E] = 0X29,
  [0X12] = 0X2A,
  [0X5D] = 0X2B,
  [0X1A] = 0X2C,
  [0X22] = 0X2D,
  [0X21] = 0X2E,
  [0X2A] = 0X2F,
  [0X32] = 0X30,
  [0X31] = 0X31,
  [0X3A] = 0X32,
  [0X41] = 0X33,
  [0X49] = 0X34,
  [0X4A] = 0X35,
  [0X59] = 0X36,
  [0X7C] = 0X37,
  [0X11] = 0X38,
  [0X29] = 0X39,
  [0X58] = 0X3A,
  [0X05] = 0X3B,
  [0X06] = 0X3C,
  [0X04] = 0X3D,
  [0X0C] = 0X3E,
  [0X03] = 0X3F,
  [0X0B] = 0X40,
  [0X02] = 0X41,
  [0X0A] = 0X42,
  [0X01] = 0X43,
  [0X09] = 0X44,
  [0X77] = 0X45,
  [0X7E] = 0X46,
  [0X6C] = 0X47,
  [0X75] = 0X48,
  [0X7D] = 0X49,
  [0X7B] = 0X4A,
  [0X6B] = 0X4B,
  [0X73] = 0X4C,
  [0X74] = 0X4D,
  [0X79] = 0X4E,
  [0X69] = 0X4F,
  [0X72] = 0X50,
  [0X7A] = 0X51,
  [0X70] = 0X52,
  [0X71] = 0X53,
  [0X7F] = 0X54,
  [0X60] = 0X55,
  [0X61] = 0X56,
  [0X78] = 0X57,
  [0X07] = 0X58,
  [0X0F] = 0X59,
  [0X17] = 0X5A,
  [0X1F] = 0X5B,
  [0X27] = 0X5C,
  [0X2F] = 0X5D,
  [0X37] = 0X5E,
  [0X3F] = 0X5F,
  [0X47] = 0X60,
  [0X4F] = 0X61,
  [0X56] = 0X62,
  [0X5E] = 0X63,
  [0X08] = 0X64,
  [0X10] = 0X65,
  [0X18] = 0X66,
  [0X20] = 0X67,
  [0X28] = 0X68,
  [0X30] = 0X69,
  [0X38] = 0X6A,
  [0X40] = 0X6B,
  [0X48] = 0X6C,
  [0X50] = 0X6D,
  [0X57] = 0X6E,
  [0X6F] = 0X6F,
  [0X13] = 0X70,
  [0X19] = 0X71,
  [0X39] = 0X72,
  [0X51] = 0X73,
  [0X53] = 0X74,
  [0X5C] = 0X75,
  [0X5F] = 0X76,
  [0X62] = 0X77,
  [0X63] = 0X78,
  [0X64] = 0X79,
  [0X65] = 0X7A,
  [0X67] = 0X7B,
  [0X68] = 0X7C,
  [0X6A] = 0X7D,
  [0X6D] = 0X7E,
  [0X6E] = 0X7F
};

typedef enum {
  MOD_RELEASE = 0, /* must be first */
  MOD_WINDOWS_LEFT,
  MOD_WINDOWS_RIGHT,
  MOD_MENU,
  MOD_CAPS_LOCK,
  MOD_SCROLL_LOCK,
  MOD_NUMBER_LOCK,
  MOD_NUMBER_SHIFT,
  MOD_SHIFT_LEFT,
  MOD_SHIFT_RIGHT,
  MOD_CONTROL_LEFT,
  MOD_CONTROL_RIGHT,
  MOD_ALT_LEFT,
  MOD_ALT_RIGHT
} Modifier;

#define MOD_BIT(number) (1 << (number))
#define MOD_SET(number, bits) ((bits) |= MOD_BIT((number)))
#define MOD_CLR(number, bits) ((bits) &= ~MOD_BIT((number)))
#define MOD_TST(number, bits) ((bits) & MOD_BIT((number)))

#define USE_SCAN_CODES(mode,type) (mode##_scanCodesSize = (mode##_scanCodes = mode##_##type##ScanCodes)? (sizeof(mode##_##type##ScanCodes) / sizeof(*mode##_scanCodes)): 0)

typedef struct {
  uint16_t command;
  uint16_t alternate;
} KeyEntry;

static int
interpretKey (int *command, const KeyEntry *key, int release, unsigned int *modifiers) {
  int cmd = key->command;
  int blk = cmd & BRL_MSK_BLK;

  if (key->alternate) {
    int alternate = 0;

    if (blk == BRL_BLK_PASSCHAR) {
      if (MOD_TST(MOD_SHIFT_LEFT, *modifiers) || MOD_TST(MOD_SHIFT_RIGHT, *modifiers)) alternate = 1;
    } else {
      if (MOD_TST(MOD_NUMBER_LOCK, *modifiers) || MOD_TST(MOD_NUMBER_SHIFT, *modifiers)) alternate = 1;
    }

    if (alternate) {
      cmd = key->alternate;
      blk = cmd & BRL_MSK_BLK;
    }
  }

  if (cmd) {
    if (blk) {
      if (!release) {
        if (blk == BRL_BLK_PASSCHAR) {
          if (MOD_TST(MOD_CAPS_LOCK, *modifiers)) cmd |= BRL_FLG_CHAR_UPPER;
          if (MOD_TST(MOD_ALT_LEFT, *modifiers)) cmd |= BRL_FLG_CHAR_META;
          if (MOD_TST(MOD_CONTROL_LEFT, *modifiers) || MOD_TST(MOD_CONTROL_RIGHT, *modifiers)) cmd |= BRL_FLG_CHAR_CONTROL;
        }

        if ((blk == BRL_BLK_PASSKEY) && MOD_TST(MOD_ALT_LEFT, *modifiers)) {
          int arg = cmd & BRL_MSK_ARG;
          switch (arg) {
            case BRL_KEY_CURSOR_LEFT:
              cmd = BRL_CMD_SWITCHVT_PREV;
              break;

            case BRL_KEY_CURSOR_RIGHT:
              cmd = BRL_CMD_SWITCHVT_NEXT;
              break;

            default:
              if (arg >= BRL_KEY_FUNCTION) {
                cmd = BRL_BLK_SWITCHVT + (arg - BRL_KEY_FUNCTION);
              }
              break;
          }
        }

        *command = cmd;
        return 1;
      }
    } else {
      switch (cmd) {
        case MOD_SCROLL_LOCK:
        case MOD_NUMBER_LOCK:
        case MOD_CAPS_LOCK:
          if (!release) {
            if (MOD_TST(cmd, *modifiers)) {
              MOD_CLR(cmd, *modifiers);
            } else {
              MOD_SET(cmd, *modifiers);
            }
          }
          break;

        case MOD_NUMBER_SHIFT:
        case MOD_SHIFT_LEFT:
        case MOD_SHIFT_RIGHT:
        case MOD_CONTROL_LEFT:
        case MOD_CONTROL_RIGHT:
        case MOD_ALT_LEFT:
        case MOD_ALT_RIGHT:
          if (release) {
            MOD_CLR(cmd, *modifiers);
          } else {
            MOD_SET(cmd, *modifiers);
          }
          break;
      }
    }
  }
  return 0;
}

static const KeyEntry AT_basicScanCodes[] = {
  [0X76] = {BRL_BLK_PASSKEY+BRL_KEY_ESCAPE},
  [0X05] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+0},
  [0X06] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+1},
  [0X04] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+2},
  [0X0C] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+3},
  [0X03] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+4},
  [0X0B] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+5},
  [0X83] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+6},
  [0X0A] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+7},
  [0X01] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+8},
  [0X09] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+9},
  [0X78] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+10},
  [0X07] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+11},
  [0X7E] = {MOD_SCROLL_LOCK},

  [0X0E] = {BRL_BLK_PASSCHAR+'`', BRL_BLK_PASSCHAR+'~'},
  [0X16] = {BRL_BLK_PASSCHAR+'1', BRL_BLK_PASSCHAR+'!'},
  [0X1E] = {BRL_BLK_PASSCHAR+'2', BRL_BLK_PASSCHAR+'@'},
  [0X26] = {BRL_BLK_PASSCHAR+'3', BRL_BLK_PASSCHAR+'#'},
  [0X25] = {BRL_BLK_PASSCHAR+'4', BRL_BLK_PASSCHAR+'$'},
  [0X2E] = {BRL_BLK_PASSCHAR+'5', BRL_BLK_PASSCHAR+'%'},
  [0X36] = {BRL_BLK_PASSCHAR+'6', BRL_BLK_PASSCHAR+'^'},
  [0X3D] = {BRL_BLK_PASSCHAR+'7', BRL_BLK_PASSCHAR+'&'},
  [0X3E] = {BRL_BLK_PASSCHAR+'8', BRL_BLK_PASSCHAR+'*'},
  [0X46] = {BRL_BLK_PASSCHAR+'9', BRL_BLK_PASSCHAR+'('},
  [0X45] = {BRL_BLK_PASSCHAR+'0', BRL_BLK_PASSCHAR+')'},
  [0X4E] = {BRL_BLK_PASSCHAR+'-', BRL_BLK_PASSCHAR+'_'},
  [0X55] = {BRL_BLK_PASSCHAR+'=', BRL_BLK_PASSCHAR+'+'},
  [0X66] = {BRL_BLK_PASSKEY+BRL_KEY_BACKSPACE},

  [0X0D] = {BRL_BLK_PASSKEY+BRL_KEY_TAB},
  [0X15] = {BRL_BLK_PASSCHAR+'q', BRL_BLK_PASSCHAR+'Q'},
  [0X1D] = {BRL_BLK_PASSCHAR+'w', BRL_BLK_PASSCHAR+'W'},
  [0X24] = {BRL_BLK_PASSCHAR+'e', BRL_BLK_PASSCHAR+'E'},
  [0X2D] = {BRL_BLK_PASSCHAR+'r', BRL_BLK_PASSCHAR+'R'},
  [0X2C] = {BRL_BLK_PASSCHAR+'t', BRL_BLK_PASSCHAR+'T'},
  [0X35] = {BRL_BLK_PASSCHAR+'y', BRL_BLK_PASSCHAR+'Y'},
  [0X3C] = {BRL_BLK_PASSCHAR+'u', BRL_BLK_PASSCHAR+'U'},
  [0X43] = {BRL_BLK_PASSCHAR+'i', BRL_BLK_PASSCHAR+'I'},
  [0X44] = {BRL_BLK_PASSCHAR+'o', BRL_BLK_PASSCHAR+'O'},
  [0X4D] = {BRL_BLK_PASSCHAR+'p', BRL_BLK_PASSCHAR+'P'},
  [0X54] = {BRL_BLK_PASSCHAR+'[', BRL_BLK_PASSCHAR+'{'},
  [0X5B] = {BRL_BLK_PASSCHAR+']', BRL_BLK_PASSCHAR+'}'},
  [0X5D] = {BRL_BLK_PASSCHAR+'\\', BRL_BLK_PASSCHAR+'|'},

  [0X58] = {MOD_CAPS_LOCK},
  [0X61] = {BRL_BLK_PASSCHAR+'<', BRL_BLK_PASSCHAR+'>'},
  [0X1C] = {BRL_BLK_PASSCHAR+'a', BRL_BLK_PASSCHAR+'A'},
  [0X1B] = {BRL_BLK_PASSCHAR+'s', BRL_BLK_PASSCHAR+'S'},
  [0X23] = {BRL_BLK_PASSCHAR+'d', BRL_BLK_PASSCHAR+'D'},
  [0X2B] = {BRL_BLK_PASSCHAR+'f', BRL_BLK_PASSCHAR+'F'},
  [0X34] = {BRL_BLK_PASSCHAR+'g', BRL_BLK_PASSCHAR+'G'},
  [0X33] = {BRL_BLK_PASSCHAR+'h', BRL_BLK_PASSCHAR+'H'},
  [0X3B] = {BRL_BLK_PASSCHAR+'j', BRL_BLK_PASSCHAR+'J'},
  [0X42] = {BRL_BLK_PASSCHAR+'k', BRL_BLK_PASSCHAR+'K'},
  [0X4B] = {BRL_BLK_PASSCHAR+'l', BRL_BLK_PASSCHAR+'L'},
  [0X4C] = {BRL_BLK_PASSCHAR+';', BRL_BLK_PASSCHAR+':'},
  [0X52] = {BRL_BLK_PASSCHAR+'\'', BRL_BLK_PASSCHAR+'"'},
  [0X5A] = {BRL_BLK_PASSKEY+BRL_KEY_ENTER},

  [0X12] = {MOD_SHIFT_LEFT},
  [0X1A] = {BRL_BLK_PASSCHAR+'z', BRL_BLK_PASSCHAR+'Z'},
  [0X22] = {BRL_BLK_PASSCHAR+'x', BRL_BLK_PASSCHAR+'X'},
  [0X21] = {BRL_BLK_PASSCHAR+'c', BRL_BLK_PASSCHAR+'C'},
  [0X2A] = {BRL_BLK_PASSCHAR+'v', BRL_BLK_PASSCHAR+'V'},
  [0X32] = {BRL_BLK_PASSCHAR+'b', BRL_BLK_PASSCHAR+'B'},
  [0X31] = {BRL_BLK_PASSCHAR+'n', BRL_BLK_PASSCHAR+'N'},
  [0X3A] = {BRL_BLK_PASSCHAR+'m', BRL_BLK_PASSCHAR+'M'},
  [0X41] = {BRL_BLK_PASSCHAR+',', BRL_BLK_PASSCHAR+'<'},
  [0X49] = {BRL_BLK_PASSCHAR+'.', BRL_BLK_PASSCHAR+'>'},
  [0X4A] = {BRL_BLK_PASSCHAR+'/', BRL_BLK_PASSCHAR+'?'},
  [0X59] = {MOD_SHIFT_RIGHT},

  [0X14] = {MOD_CONTROL_LEFT},
  [0X11] = {MOD_ALT_LEFT},
  [0X29] = {BRL_BLK_PASSCHAR+' '},

  [0X77] = {MOD_NUMBER_LOCK},
  [0X7C] = {BRL_BLK_PASSCHAR+'*'},
  [0X7B] = {BRL_BLK_PASSCHAR+'-'},
  [0X79] = {BRL_BLK_PASSCHAR+'+'},
  [0X71] = {BRL_BLK_PASSKEY+BRL_KEY_DELETE, BRL_BLK_PASSCHAR+'.'},
  [0X70] = {BRL_BLK_PASSKEY+BRL_KEY_INSERT, BRL_BLK_PASSCHAR+'0'},
  [0X69] = {BRL_BLK_PASSKEY+BRL_KEY_END, BRL_BLK_PASSCHAR+'1'},
  [0X72] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_DOWN, BRL_BLK_PASSCHAR+'2'},
  [0X7A] = {BRL_BLK_PASSKEY+BRL_KEY_PAGE_DOWN, BRL_BLK_PASSCHAR+'3'},
  [0X6B] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_LEFT, BRL_BLK_PASSCHAR+'4'},
  [0X73] = {BRL_BLK_PASSCHAR+'5'},
  [0X74] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_RIGHT, BRL_BLK_PASSCHAR+'6'},
  [0X6C] = {BRL_BLK_PASSKEY+BRL_KEY_HOME, BRL_BLK_PASSCHAR+'7'},
  [0X75] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_UP, BRL_BLK_PASSCHAR+'8'},
  [0X7D] = {BRL_BLK_PASSKEY+BRL_KEY_PAGE_UP, BRL_BLK_PASSCHAR+'9'}
};

static const KeyEntry AT_emul0ScanCodes[] = {
  [0X12] = {MOD_NUMBER_SHIFT},
  [0X1F] = {MOD_WINDOWS_LEFT},
  [0X11] = {MOD_ALT_RIGHT},
  [0X27] = {MOD_WINDOWS_RIGHT},
  [0X2F] = {MOD_MENU},
  [0X14] = {MOD_CONTROL_RIGHT},
  [0X70] = {BRL_BLK_PASSKEY+BRL_KEY_INSERT},
  [0X71] = {BRL_BLK_PASSKEY+BRL_KEY_DELETE},
  [0X6C] = {BRL_BLK_PASSKEY+BRL_KEY_HOME},
  [0X69] = {BRL_BLK_PASSKEY+BRL_KEY_END},
  [0X7D] = {BRL_BLK_PASSKEY+BRL_KEY_PAGE_UP},
  [0X7A] = {BRL_BLK_PASSKEY+BRL_KEY_PAGE_DOWN},
  [0X75] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_UP},
  [0X6B] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_LEFT},
  [0X72] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_DOWN},
  [0X74] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_RIGHT},
  [0X4A] = {BRL_BLK_PASSCHAR+'/'},
  [0X5A] = {BRL_BLK_PASSKEY+BRL_KEY_ENTER}
};

#define AT_emul1ScanCodes NULL

static const KeyEntry *AT_scanCodes;
static size_t AT_scanCodesSize;
static unsigned int AT_scanCodeModifiers;

int
atInterpretScanCode (int *command, unsigned char byte) {
  if (byte == 0XF0) {
    MOD_SET(MOD_RELEASE, AT_scanCodeModifiers);
  } else if (byte == 0XE0) {
    USE_SCAN_CODES(AT, emul0);
  } else if (byte == 0XE1) {
    USE_SCAN_CODES(AT, emul1);
  } else if (byte < AT_scanCodesSize) {
    const KeyEntry *key = &AT_scanCodes[byte];
    int release = MOD_TST(MOD_RELEASE, AT_scanCodeModifiers);

    MOD_CLR(MOD_RELEASE, AT_scanCodeModifiers);
    USE_SCAN_CODES(AT, basic);

    return interpretKey(command, key, release, &AT_scanCodeModifiers);
  }
  return 0;
}

static const KeyEntry XT_basicScanCodes[] = {
  [0X01] = {BRL_BLK_PASSKEY+BRL_KEY_ESCAPE},
  [0X02] = {BRL_BLK_PASSCHAR+'1', BRL_BLK_PASSCHAR+'!'},
  [0X03] = {BRL_BLK_PASSCHAR+'2', BRL_BLK_PASSCHAR+'@'},
  [0X04] = {BRL_BLK_PASSCHAR+'3', BRL_BLK_PASSCHAR+'#'},
  [0X05] = {BRL_BLK_PASSCHAR+'4', BRL_BLK_PASSCHAR+'$'},
  [0X06] = {BRL_BLK_PASSCHAR+'5', BRL_BLK_PASSCHAR+'%'},
  [0X07] = {BRL_BLK_PASSCHAR+'6', BRL_BLK_PASSCHAR+'^'},
  [0X08] = {BRL_BLK_PASSCHAR+'7', BRL_BLK_PASSCHAR+'&'},
  [0X09] = {BRL_BLK_PASSCHAR+'8', BRL_BLK_PASSCHAR+'*'},
  [0X0A] = {BRL_BLK_PASSCHAR+'9', BRL_BLK_PASSCHAR+'('},
  [0X0B] = {BRL_BLK_PASSCHAR+'0', BRL_BLK_PASSCHAR+')'},
  [0X0C] = {BRL_BLK_PASSCHAR+'-', BRL_BLK_PASSCHAR+'_'},
  [0X0D] = {BRL_BLK_PASSCHAR+'=', BRL_BLK_PASSCHAR+'+'},
  [0X0E] = {BRL_BLK_PASSKEY+BRL_KEY_BACKSPACE},

  [0X0F] = {BRL_BLK_PASSKEY+BRL_KEY_TAB},
  [0X10] = {BRL_BLK_PASSCHAR+'q', BRL_BLK_PASSCHAR+'Q'},
  [0X11] = {BRL_BLK_PASSCHAR+'w', BRL_BLK_PASSCHAR+'W'},
  [0X12] = {BRL_BLK_PASSCHAR+'e', BRL_BLK_PASSCHAR+'E'},
  [0X13] = {BRL_BLK_PASSCHAR+'r', BRL_BLK_PASSCHAR+'R'},
  [0X14] = {BRL_BLK_PASSCHAR+'t', BRL_BLK_PASSCHAR+'T'},
  [0X15] = {BRL_BLK_PASSCHAR+'y', BRL_BLK_PASSCHAR+'Y'},
  [0X16] = {BRL_BLK_PASSCHAR+'u', BRL_BLK_PASSCHAR+'U'},
  [0X17] = {BRL_BLK_PASSCHAR+'i', BRL_BLK_PASSCHAR+'I'},
  [0X18] = {BRL_BLK_PASSCHAR+'o', BRL_BLK_PASSCHAR+'O'},
  [0X19] = {BRL_BLK_PASSCHAR+'p', BRL_BLK_PASSCHAR+'P'},
  [0X1A] = {BRL_BLK_PASSCHAR+'[', BRL_BLK_PASSCHAR+'{'},
  [0X1B] = {BRL_BLK_PASSCHAR+']', BRL_BLK_PASSCHAR+'}'},
  [0X1C] = {BRL_BLK_PASSKEY+BRL_KEY_ENTER},

  [0X1D] = {MOD_CONTROL_LEFT},
  [0X1E] = {BRL_BLK_PASSCHAR+'a', BRL_BLK_PASSCHAR+'A'},
  [0X1F] = {BRL_BLK_PASSCHAR+'s', BRL_BLK_PASSCHAR+'S'},
  [0X20] = {BRL_BLK_PASSCHAR+'d', BRL_BLK_PASSCHAR+'D'},
  [0X21] = {BRL_BLK_PASSCHAR+'f', BRL_BLK_PASSCHAR+'F'},
  [0X22] = {BRL_BLK_PASSCHAR+'g', BRL_BLK_PASSCHAR+'G'},
  [0X23] = {BRL_BLK_PASSCHAR+'h', BRL_BLK_PASSCHAR+'H'},
  [0X24] = {BRL_BLK_PASSCHAR+'j', BRL_BLK_PASSCHAR+'J'},
  [0X25] = {BRL_BLK_PASSCHAR+'k', BRL_BLK_PASSCHAR+'K'},
  [0X26] = {BRL_BLK_PASSCHAR+'l', BRL_BLK_PASSCHAR+'L'},
  [0X27] = {BRL_BLK_PASSCHAR+';', BRL_BLK_PASSCHAR+':'},
  [0X28] = {BRL_BLK_PASSCHAR+'\'', BRL_BLK_PASSCHAR+'"'},
  [0X29] = {BRL_BLK_PASSCHAR+'`', BRL_BLK_PASSCHAR+'~'},

  [0X2A] = {MOD_SHIFT_LEFT},
  [0X2B] = {BRL_BLK_PASSCHAR+'\\', BRL_BLK_PASSCHAR+'|'},
  [0X2C] = {BRL_BLK_PASSCHAR+'z', BRL_BLK_PASSCHAR+'Z'},
  [0X2D] = {BRL_BLK_PASSCHAR+'x', BRL_BLK_PASSCHAR+'X'},
  [0X2E] = {BRL_BLK_PASSCHAR+'c', BRL_BLK_PASSCHAR+'C'},
  [0X2F] = {BRL_BLK_PASSCHAR+'v', BRL_BLK_PASSCHAR+'V'},
  [0X30] = {BRL_BLK_PASSCHAR+'b', BRL_BLK_PASSCHAR+'B'},
  [0X31] = {BRL_BLK_PASSCHAR+'n', BRL_BLK_PASSCHAR+'N'},
  [0X32] = {BRL_BLK_PASSCHAR+'m', BRL_BLK_PASSCHAR+'M'},
  [0X33] = {BRL_BLK_PASSCHAR+',', BRL_BLK_PASSCHAR+'<'},
  [0X34] = {BRL_BLK_PASSCHAR+'.', BRL_BLK_PASSCHAR+'>'},
  [0X35] = {BRL_BLK_PASSCHAR+'/', BRL_BLK_PASSCHAR+'?'},
  [0X36] = {MOD_SHIFT_RIGHT},

  [0X37] = {BRL_BLK_PASSCHAR+'*'},
  [0X38] = {MOD_ALT_LEFT},
  [0X39] = {BRL_BLK_PASSCHAR+' '},
  [0X3A] = {MOD_CAPS_LOCK},

  [0X3B] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+0},
  [0X3C] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+1},
  [0X3D] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+2},
  [0X3E] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+3},
  [0X3F] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+4},
  [0X40] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+5},
  [0X41] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+6},
  [0X42] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+7},
  [0X43] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+8},
  [0X44] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+9},

  [0X45] = {MOD_NUMBER_LOCK},
  [0X46] = {MOD_SCROLL_LOCK},

  [0X47] = {BRL_BLK_PASSCHAR+'7'},
  [0X48] = {BRL_BLK_PASSCHAR+'8'},
  [0X49] = {BRL_BLK_PASSCHAR+'9'},
  [0X4A] = {BRL_BLK_PASSCHAR+'-'},
  [0X4B] = {BRL_BLK_PASSCHAR+'4'},
  [0X4C] = {BRL_BLK_PASSCHAR+'5'},
  [0X4D] = {BRL_BLK_PASSCHAR+'6'},
  [0X4E] = {BRL_BLK_PASSCHAR+'+'},
  [0X4F] = {BRL_BLK_PASSCHAR+'1'},
  [0X50] = {BRL_BLK_PASSCHAR+'2'},
  [0X51] = {BRL_BLK_PASSCHAR+'3'},
  [0X52] = {BRL_BLK_PASSCHAR+'0'},
  [0X53] = {BRL_BLK_PASSCHAR+'.'},

  [0X57] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+10},
  [0X58] = {BRL_BLK_PASSKEY+BRL_KEY_FUNCTION+11},
};

static const KeyEntry XT_emul0ScanCodes[] = {
  [0X1C] = {BRL_BLK_PASSKEY+BRL_KEY_ENTER},
  [0X1D] = {MOD_CONTROL_RIGHT},
  [0X35] = {BRL_BLK_PASSCHAR+'/'},
  [0X38] = {MOD_ALT_RIGHT},

  [0X47] = {BRL_BLK_PASSKEY+BRL_KEY_HOME},
  [0X48] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_UP},
  [0X49] = {BRL_BLK_PASSKEY+BRL_KEY_PAGE_UP},
  [0X4B] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_LEFT},
  [0X4D] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_RIGHT},
  [0X4F] = {BRL_BLK_PASSKEY+BRL_KEY_END},
  [0X50] = {BRL_BLK_PASSKEY+BRL_KEY_CURSOR_DOWN},
  [0X51] = {BRL_BLK_PASSKEY+BRL_KEY_PAGE_DOWN},
  [0X52] = {BRL_BLK_PASSKEY+BRL_KEY_INSERT},
  [0X53] = {BRL_BLK_PASSKEY+BRL_KEY_DELETE},

  [0X5B] = {MOD_WINDOWS_LEFT},
  [0X5C] = {MOD_WINDOWS_RIGHT},
  [0X5D] = {MOD_MENU}
};

#define XT_emul1ScanCodes NULL

static const KeyEntry *XT_scanCodes;
static size_t XT_scanCodesSize;
static unsigned int XT_scanCodeModifiers;

int
xtInterpretScanCode (int *command, unsigned char byte) {
  if (byte == 0XE0) {
    USE_SCAN_CODES(XT, emul0);
  } else if (byte == 0XE1) {
    USE_SCAN_CODES(XT, emul1);
  } else if (byte < XT_scanCodesSize) {
    const KeyEntry *key = &XT_scanCodes[byte & 0X7F];
    int release = (byte & 0X80) != 0;

    USE_SCAN_CODES(XT, basic);

    return interpretKey(command, key, release, &XT_scanCodeModifiers);
  }
  return 0;
}

void
resetScanCodes (void) {
  USE_SCAN_CODES(AT, basic);
  AT_scanCodeModifiers = 0;

  USE_SCAN_CODES(XT, basic);
  XT_scanCodeModifiers = 0;
}

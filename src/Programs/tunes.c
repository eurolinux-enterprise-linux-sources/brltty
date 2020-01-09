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

#include "misc.h"
#include "system.h"
#include "message.h"
#include "brl.h"
#include "brltty.h"
#include "tunes.h"
#include "notes.h"

static TuneElement elements_braille_on[] = {
  TUNE_NOTE( 60,  64),
  TUNE_NOTE(100,  69),
  TUNE_STOP()
};
TuneDefinition tune_braille_on = {
  NULL, 0, elements_braille_on
};

static TuneElement elements_braille_off[] = {
  TUNE_NOTE( 60,  64),
  TUNE_NOTE( 60,  57),
  TUNE_STOP()
};
TuneDefinition tune_braille_off = {
  NULL, 0, elements_braille_off
};

static TuneElement elements_command_done[] = {
  TUNE_NOTE( 40,  74),
  TUNE_REST( 30),
  TUNE_NOTE( 40,  74),
  TUNE_REST( 40),
  TUNE_NOTE(140,  74),
  TUNE_REST( 20),
  TUNE_NOTE( 50,  79),
  TUNE_STOP()
};
TuneDefinition tune_command_done = {
  "Done", 0, elements_command_done
};

static TuneElement elements_command_rejected[] = {
  TUNE_NOTE(100,  78),
  TUNE_STOP()
};
TuneDefinition tune_command_rejected = {
  NULL, TUNE_TACTILE(50,BRL_DOT1|BRL_DOT2|BRL_DOT3|BRL_DOT4|BRL_DOT5|BRL_DOT6|BRL_DOT7|BRL_DOT8), elements_command_rejected
};

static TuneElement elements_mark_set[] = {
  TUNE_NOTE( 20,  83),
  TUNE_NOTE( 15,  81),
  TUNE_NOTE( 15,  79),
  TUNE_NOTE( 25,  84),
  TUNE_STOP()
};
TuneDefinition tune_mark_set = {
  NULL, 0, elements_mark_set
};

static TuneElement elements_cut_begin[] = {
  TUNE_NOTE( 40,  74),
  TUNE_NOTE( 20,  86),
  TUNE_STOP()
};
TuneDefinition tune_cut_begin = {
  NULL, 0, elements_cut_begin
};

static TuneElement elements_cut_end[] = {
  TUNE_NOTE( 50,  86),
  TUNE_NOTE( 30,  74),
  TUNE_STOP()
};
TuneDefinition tune_cut_end = {
  NULL, 0, elements_cut_end
};

static TuneElement elements_toggle_on[] = {
  TUNE_NOTE( 30,  74),
  TUNE_REST( 30),
  TUNE_NOTE( 30,  79),
  TUNE_REST( 30),
  TUNE_NOTE( 40,  86),
  TUNE_STOP()
};
TuneDefinition tune_toggle_on = {
  NULL, TUNE_TACTILE(30,BRL_DOT1|BRL_DOT2|BRL_DOT4|BRL_DOT5), elements_toggle_on
};

static TuneElement elements_toggle_off[] = {
  TUNE_NOTE( 30,  86),
  TUNE_REST( 30),
  TUNE_NOTE( 30,  79),
  TUNE_REST( 30),
  TUNE_NOTE( 30,  74),
  TUNE_STOP()
};
TuneDefinition tune_toggle_off = {
  NULL, TUNE_TACTILE(30,BRL_DOT3|BRL_DOT7|BRL_DOT6|BRL_DOT8), elements_toggle_off
};

static TuneElement elements_cursor_linked[] = {
  TUNE_NOTE(  7,  80),
  TUNE_NOTE(  7,  79),
  TUNE_NOTE( 12,  76),
  TUNE_STOP()
};
TuneDefinition tune_cursor_linked = {
  NULL, 0, elements_cursor_linked
};

static TuneElement elements_cursor_unlinked[] = {
  TUNE_NOTE(  7,  78),
  TUNE_NOTE(  7,  79),
  TUNE_NOTE( 20,  83),
  TUNE_STOP()
};
TuneDefinition tune_cursor_unlinked = {
  NULL, 0, elements_cursor_unlinked
};

static TuneElement elements_screen_frozen[] = {
  TUNE_NOTE(  5,  58),
  TUNE_NOTE(  5,  59),
  TUNE_NOTE(  5,  60),
  TUNE_NOTE(  5,  61),
  TUNE_NOTE(  5,  62),
  TUNE_NOTE(  5,  63),
  TUNE_NOTE(  5,  64),
  TUNE_NOTE(  5,  65),
  TUNE_NOTE(  5,  66),
  TUNE_NOTE(  5,  67),
  TUNE_NOTE(  5,  68),
  TUNE_NOTE(  5,  69),
  TUNE_NOTE(  5,  70),
  TUNE_NOTE(  5,  71),
  TUNE_NOTE(  5,  72),
  TUNE_NOTE(  5,  73),
  TUNE_NOTE(  5,  74),
  TUNE_NOTE(  5,  76),
  TUNE_NOTE(  5,  78),
  TUNE_NOTE(  5,  80),
  TUNE_NOTE(  5,  83),
  TUNE_NOTE(  5,  86),
  TUNE_NOTE(  5,  90),
  TUNE_NOTE(  5,  95),
  TUNE_STOP()
};
TuneDefinition tune_screen_frozen = {
  "Frozen", 0, elements_screen_frozen
};

static TuneElement elements_screen_unfrozen[] = {
  TUNE_NOTE(  5,  95),
  TUNE_NOTE(  5,  90),
  TUNE_NOTE(  5,  86),
  TUNE_NOTE(  5,  83),
  TUNE_NOTE(  5,  80),
  TUNE_NOTE(  5,  78),
  TUNE_NOTE(  5,  76),
  TUNE_NOTE(  5,  74),
  TUNE_NOTE(  5,  73),
  TUNE_NOTE(  5,  72),
  TUNE_NOTE(  5,  71),
  TUNE_NOTE(  5,  70),
  TUNE_NOTE(  5,  69),
  TUNE_NOTE(  5,  68),
  TUNE_NOTE(  5,  67),
  TUNE_NOTE(  5,  66),
  TUNE_NOTE(  5,  65),
  TUNE_NOTE(  5,  64),
  TUNE_NOTE(  5,  63),
  TUNE_NOTE(  5,  62),
  TUNE_NOTE(  5,  61),
  TUNE_NOTE(  5,  60),
  TUNE_NOTE(  5,  59),
  TUNE_NOTE(  5,  58),
  TUNE_STOP()
};
TuneDefinition tune_screen_unfrozen = {
  "Unfrozen", 0, elements_screen_unfrozen
};

static TuneElement elements_wrap_down[] = {
  TUNE_NOTE(  6,  86),
  TUNE_NOTE(  6,  74),
  TUNE_NOTE(  6,  62),
  TUNE_NOTE( 10,  50),
  TUNE_STOP()
};
TuneDefinition tune_wrap_down = {
  NULL, TUNE_TACTILE(20,BRL_DOT1|BRL_DOT2|BRL_DOT3|BRL_DOT7), elements_wrap_down
};

static TuneElement elements_wrap_up[] = {
  TUNE_NOTE(  6,  50),
  TUNE_NOTE(  6,  62),
  TUNE_NOTE(  6,  74),
  TUNE_NOTE( 10,  86),
  TUNE_STOP()
};
TuneDefinition tune_wrap_up = {
  NULL, TUNE_TACTILE(20,BRL_DOT4|BRL_DOT5|BRL_DOT6|BRL_DOT8), elements_wrap_up
};

static TuneElement elements_skip_first[] = {
  TUNE_REST( 40),
  TUNE_NOTE(  4,  62),
  TUNE_NOTE(  6,  67),
  TUNE_NOTE(  8,  74),
  TUNE_REST( 25),
  TUNE_STOP()
};
TuneDefinition tune_skip_first = {
  NULL, TUNE_TACTILE(30,BRL_DOT1|BRL_DOT4|BRL_DOT7|BRL_DOT8), elements_skip_first
};

static TuneElement elements_skip[] = {
  TUNE_NOTE( 10,  74),
  TUNE_REST( 18),
  TUNE_STOP()
};
TuneDefinition tune_skip = {
  NULL, 0, elements_skip
};

static TuneElement elements_skip_more[] = {
  TUNE_NOTE( 20,  73),
  TUNE_REST(  1),
  TUNE_STOP()
};
TuneDefinition tune_skip_more = {
  NULL, 0, elements_skip_more
};

static TuneElement elements_bounce[] = {
  TUNE_NOTE(  6,  98),
  TUNE_NOTE(  6,  86),
  TUNE_NOTE(  6,  74),
  TUNE_NOTE(  6,  62),
  TUNE_NOTE( 10,  50),
  TUNE_STOP()
};
TuneDefinition tune_bounce = {
  NULL, TUNE_TACTILE(50,BRL_DOT1|BRL_DOT2|BRL_DOT3|BRL_DOT4|BRL_DOT5|BRL_DOT6|BRL_DOT7|BRL_DOT8), elements_bounce
};

static TuneElement elements_routing_started[] = {
  TUNE_NOTE( 10,  55),
  TUNE_REST( 60),
  TUNE_NOTE( 15,  60),
  TUNE_STOP()
};
TuneDefinition tune_routing_started = {
  NULL, 0, elements_routing_started
};

static TuneElement elements_routing_succeeded[] = {
  TUNE_NOTE( 60,  64),
  TUNE_NOTE( 20,  76),
  TUNE_STOP()
};
TuneDefinition tune_routing_succeeded = {
  NULL, 0, elements_routing_succeeded
};

static TuneElement elements_routing_failed[] = {
  TUNE_NOTE( 80,  80),
  TUNE_NOTE( 90,  79),
  TUNE_NOTE(100,  78),
  TUNE_NOTE(100,  77),
  TUNE_REST( 20),
  TUNE_NOTE(100,  77),
  TUNE_REST( 20),
  TUNE_NOTE(150,  77),
  TUNE_STOP()
};
TuneDefinition tune_routing_failed = {
  NULL, 0, elements_routing_failed
};

const float noteFrequencies[] = {
  /*   0 -5C  */     8.176,
  /*   1 -5C# */     8.662,
  /*   2 -5D  */     9.177,
  /*   3 -5D# */     9.723,
  /*   4 -5E  */    10.301,
  /*   5 -5F  */    10.913,
  /*   6 -5F# */    11.562,
  /*   7 -5G  */    12.250,
  /*   8 -5G# */    12.978,
  /*   9 -5A  */    13.750,
  /*  10 -5A# */    14.568,
  /*  11 -5B  */    15.434,
  /*  12 -4C  */    16.352,
  /*  13 -4C# */    17.324,
  /*  14 -4D  */    18.354,
  /*  15 -4D# */    19.445,
  /*  16 -4E  */    20.602,
  /*  17 -4F  */    21.827,
  /*  18 -4F# */    23.125,
  /*  19 -4G  */    24.500,
  /*  20 -4G# */    25.957,
  /*  21 -4A  */    27.500,
  /*  22 -4A# */    29.135,
  /*  23 -4B  */    30.868,
  /*  24 -3C  */    32.703,
  /*  25 -3C# */    34.648,
  /*  26 -3D  */    36.708,
  /*  27 -3D# */    38.891,
  /*  28 -3E  */    41.203,
  /*  29 -3F  */    43.654,
  /*  30 -3F# */    46.249,
  /*  31 -3G  */    48.999,
  /*  32 -3G# */    51.913,
  /*  33 -3A  */    55.000,
  /*  34 -3A# */    58.270,
  /*  35 -3B  */    61.735,
  /*  36 -2C  */    65.406,
  /*  37 -2C# */    69.296,
  /*  38 -2D  */    73.416,
  /*  39 -2D# */    77.782,
  /*  40 -2E  */    82.407,
  /*  41 -2F  */    87.307,
  /*  42 -2F# */    92.499,
  /*  43 -2G  */    97.999,
  /*  44 -2G# */   103.826,
  /*  45 -2A  */   110.000,
  /*  46 -2A# */   116.541,
  /*  47 -2B  */   123.471,
  /*  48 -1C  */   130.813,
  /*  49 -1C# */   138.591,
  /*  50 -1D  */   146.832,
  /*  51 -1D# */   155.563,
  /*  52 -1E  */   164.814,
  /*  53 -1F  */   174.614,
  /*  54 -1F# */   184.997,
  /*  55 -1G  */   195.998,
  /*  56 -1G# */   207.652,
  /*  57 -1A  */   220.000,
  /*  58 -1A# */   233.082,
  /*  59 -1B  */   246.942,
  /*  60  0C  */   261.626,
  /*  61  0C# */   277.183,
  /*  62  0D  */   293.665,
  /*  63  0D# */   311.127,
  /*  64  0E  */   329.628,
  /*  65  0F  */   349.228,
  /*  66  0F# */   369.994,
  /*  67  0G  */   391.995,
  /*  68  0G# */   415.305,
  /*  69  0A  */   440.000,
  /*  70  0A# */   466.164,
  /*  71  0B  */   493.883,
  /*  72 +1C  */   523.251,
  /*  73 +1C# */   554.365,
  /*  74 +1D  */   587.330,
  /*  75 +1D# */   622.254,
  /*  76 +1E  */   659.255,
  /*  77 +1F  */   698.456,
  /*  78 +1F# */   739.989,
  /*  79 +1G  */   783.991,
  /*  80 +1G# */   830.609,
  /*  81 +1A  */   880.000,
  /*  82 +1A# */   932.328,
  /*  83 +1B  */   987.767,
  /*  84 +2C  */  1046.502,
  /*  85 +2C# */  1108.731,
  /*  86 +2D  */  1174.659,
  /*  87 +2D# */  1244.508,
  /*  88 +2E  */  1318.510,
  /*  89 +2F  */  1396.913,
  /*  90 +2F# */  1479.978,
  /*  91 +2G  */  1567.982,
  /*  92 +2G# */  1661.219,
  /*  93 +2A  */  1760.000,
  /*  94 +2A# */  1864.655,
  /*  95 +2B  */  1975.533,
  /*  96 +3C  */  2093.005,
  /*  97 +3C# */  2217.461,
  /*  98 +3D  */  2349.318,
  /*  99 +3D# */  2489.016,
  /* 100 +3E  */  2637.020,
  /* 101 +3F  */  2793.826,
  /* 102 +3F# */  2959.955,
  /* 103 +3G  */  3135.963,
  /* 104 +3G# */  3322.438,
  /* 105 +3A  */  3520.000,
  /* 106 +3A# */  3729.310,
  /* 107 +3B  */  3951.066,
  /* 108 +4C  */  4186.009,
  /* 109 +4C# */  4434.922,
  /* 110 +4D  */  4698.636,
  /* 111 +4D# */  4978.032,
  /* 112 +4E  */  5274.041,
  /* 113 +4F  */  5587.652,
  /* 114 +4F# */  5919.911,
  /* 115 +4G  */  6271.927,
  /* 116 +4G# */  6644.875,
  /* 117 +4A  */  7040.000,
  /* 118 +4A# */  7458.620,
  /* 119 +4B  */  7902.133,
  /* 120 +5C  */  8372.018,
  /* 121 +5C# */  8869.844,
  /* 122 +5D  */  9397.273,
  /* 123 +5D# */  9956.063,
  /* 124 +5E  */ 10548.082,
  /* 125 +5F  */ 11175.303,
  /* 126 +5F# */ 11839.822,
  /* 127 +5G  */ 12543.854
};
const unsigned int noteCount = ARRAY_COUNT(noteFrequencies);

static const NoteMethods *noteMethods = NULL;
static NoteDevice *noteDevice = NULL;
static unsigned int closeTimer = 0;
static int openErrorLevel = LOG_ERR;

TuneDevice
getDefaultTuneDevice (void) {
  return canBeep()? tdBeeper: tdPcm;
}

void
suppressTuneDeviceOpenErrors (void) {
  openErrorLevel = LOG_DEBUG;
}

static int
openTuneDevice (void) {
  if (noteDevice) return 1;
  if (!noteMethods) return 0;
  return (noteDevice = noteMethods->construct(openErrorLevel)) != NULL;
}

void
closeTuneDevice (int force) {
  if (force) {
    closeTimer = 0;
  } else if (closeTimer) {
    closeTimer--;
  }

  if (!closeTimer) {
    if (noteDevice) {
      noteMethods->destruct(noteDevice);
      noteDevice = NULL;
    }
  }
}
 
int
setTuneDevice (TuneDevice device) {
  const NoteMethods *methods;

  switch (device) {
    default:
      methods = NULL;
      break;

#ifdef ENABLE_BEEPER_SUPPORT
    case tdBeeper:
      methods = &beeperMethods;
      break;
#endif /* ENABLE_BEEPER_SUPPORT */

#ifdef ENABLE_PCM_SUPPORT
    case tdPcm:
      methods = &pcmMethods;
      break;
#endif /* ENABLE_PCM_SUPPORT */

#ifdef ENABLE_MIDI_SUPPORT
    case tdMidi:
      methods = &midiMethods;
      break;
#endif /* ENABLE_MIDI_SUPPORT */

#ifdef ENABLE_FM_SUPPORT
    case tdFm:
      methods = &fmMethods;
      break;
#endif /* ENABLE_FM_SUPPORT */
  }
  if (!methods) return 0;

  if (methods != noteMethods) {
    closeTuneDevice(1);
    noteMethods = methods;
  }

  return 1;
}

void
playTune (const TuneDefinition *tune) {
  int tunePlayed = 0;

  if (prefs.alertTunes && tune->elements) {
    if (openTuneDevice()) {
      TuneElement *element = tune->elements;

      tunePlayed = 1;
      closeTimer = 2000 / updateInterval;

      while (element->duration) {
        if (!noteMethods->play(noteDevice, element->note, element->duration)) {
          tunePlayed = 0;
          break;
        }

        ++element;
      }

      noteMethods->flush(noteDevice);
    }
  }

  if (!tunePlayed) {
    if (prefs.alertDots && tune->tactile) {
      unsigned char dots = tune->tactile & 0XFF;
      unsigned char duration = tune->tactile >> 8;
      showDotPattern(dots, duration);
    } else if (prefs.alertMessages && tune->message) {
      message(NULL, tune->message, 0);
    }
  }
}

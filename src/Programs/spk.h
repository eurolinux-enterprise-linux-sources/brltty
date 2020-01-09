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

#ifndef BRLTTY_INCLUDED_SPK
#define BRLTTY_INCLUDED_SPK

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "driver.h"

typedef struct SpeechDataStruct SpeechData;

typedef struct {
  SpeechData *data;
} SpeechSynthesizer;

extern void initializeSpeechSynthesizer (SpeechSynthesizer *spk);

extern void sayCharacters (SpeechSynthesizer *spk, const char *characters, size_t count, int mute);
extern void sayString (SpeechSynthesizer *spk, const char *string, int mute);

#define SPK_RATE_DEFAULT 10
#define SPK_RATE_MAXIMUM (SPK_RATE_DEFAULT * 2)
extern void setSpeechRate (SpeechSynthesizer *spk, int setting, int say);
extern unsigned int getIntegerSpeechRate (unsigned char setting, unsigned int normal);
extern float getFloatSpeechRate (unsigned char setting);

#define SPK_VOLUME_DEFAULT 10
#define SPK_VOLUME_MAXIMUM (SPK_VOLUME_DEFAULT * 2)
extern void setSpeechVolume (SpeechSynthesizer *spk, int setting, int say);
extern unsigned int getIntegerSpeechVolume (unsigned char setting, unsigned int normal);
extern float getFloatSpeechVolume (unsigned char setting);

#define SPK_PITCH_DEFAULT 10
#define SPK_PITCH_MAXIMUM (SPK_PITCH_DEFAULT * 2)
extern void setSpeechPitch (SpeechSynthesizer *spk, int setting, int say);
extern unsigned int getIntegerSpeechPitch (unsigned char setting, unsigned int normal);
extern float getFloatSpeechPitch (unsigned char setting);

typedef enum {
  SPK_PUNCTUATION_NONE,
  SPK_PUNCTUATION_SOME,
  SPK_PUNCTUATION_ALL
} SpeechPunctuation;
extern void setSpeechPunctuation (SpeechSynthesizer *spk, SpeechPunctuation setting, int say);

typedef struct {
  DRIVER_DEFINITION_DECLARATION;
  const char *const *parameters;

  int (*construct) (SpeechSynthesizer *spk, char **parameters);
  void (*destruct) (SpeechSynthesizer *spk);
  void (*say) (SpeechSynthesizer *spk, const unsigned char *text, size_t length, size_t count, const unsigned char *attributes);
  void (*mute) (SpeechSynthesizer *spk);

  /* These require SPK_HAVE_TRACK. */
  void (*doTrack) (SpeechSynthesizer *spk);
  int (*getTrack) (SpeechSynthesizer *spk);
  int (*isSpeaking) (SpeechSynthesizer *spk);

  /* These require SPK_HAVE_RATE. */
  void (*rate) (SpeechSynthesizer *spk, unsigned char setting);

  /* These require SPK_HAVE_VOLUME. */
  void (*volume) (SpeechSynthesizer *spk, unsigned char setting);

  /* These require SPK_HAVE_PITCH. */
  void (*pitch) (SpeechSynthesizer *spk, unsigned char setting);

  /* These require SPK_HAVE_PUNCTUATION. */
  void (*punctuation) (SpeechSynthesizer *spk, SpeechPunctuation setting);
} SpeechDriver;

extern int haveSpeechDriver (const char *code);
extern const char *getDefaultSpeechDriver (void);
extern const SpeechDriver *loadSpeechDriver (const char *code, void **driverObject, const char *driverDirectory);
extern void identifySpeechDriver (const SpeechDriver *driver, int full);
extern void identifySpeechDrivers (int full);
extern const SpeechDriver *speech;
extern const SpeechDriver noSpeech;

extern int openSpeechFifo (const char *directory, const char *path);
extern void processSpeechFifo (SpeechSynthesizer *spk);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BRLTTY_INCLUDED_SPK */

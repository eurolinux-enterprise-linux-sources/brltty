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

#include <stdio.h>

#include "charset.h"
#include "ttb.h"
#include "ttb_internal.h"
#include "brldots.h"

static const unsigned char internalTextTableBytes[] = {
#include "text.auto.h"
};

static TextTable internalTextTable = {
  .header.bytes = internalTextTableBytes,
  .size = 0
};

TextTable *textTable = &internalTextTable;

static const void *
getTextTableItem (TextTable *table, TextTableOffset offset) {
  return &table->header.bytes[offset];
}

static const UnicodeGroupEntry *
getUnicodeGroupEntry (TextTable *table, wchar_t character) {
  TextTableOffset offset = table->header.fields->unicodeGroups[UNICODE_GROUP_NUMBER(character)];
  if (offset) return getTextTableItem(table, offset);
  return NULL;
}

static const UnicodePlaneEntry *
getUnicodePlaneEntry (TextTable *table, wchar_t character) {
  const UnicodeGroupEntry *group = getUnicodeGroupEntry(table, character);

  if (group) {
    TextTableOffset offset = group->planes[UNICODE_PLANE_NUMBER(character)];
    if (offset) return getTextTableItem(table, offset);
  }

  return NULL;
}

static const UnicodeRowEntry *
getUnicodeRowEntry (TextTable *table, wchar_t character) {
  const UnicodePlaneEntry *plane = getUnicodePlaneEntry(table, character);

  if (plane) {
    TextTableOffset offset = plane->rows[UNICODE_ROW_NUMBER(character)];
    if (offset) return getTextTableItem(table, offset);
  }

  return NULL;
}

static const unsigned char *
getUnicodeCellEntry (TextTable *table, wchar_t character) {
  const UnicodeRowEntry *row = getUnicodeRowEntry(table, character);

  if (row) {
    unsigned int cellNumber = UNICODE_CELL_NUMBER(character);
    if (BITMASK_TEST(row->defined, cellNumber)) return &row->cells[cellNumber];
  }

  return NULL;
}

unsigned char
convertCharacterToDots (TextTable *table, wchar_t character) {
  switch (character & ~UNICODE_CELL_MASK) {
    case UNICODE_BRAILLE_ROW:
      return character & UNICODE_CELL_MASK;

    case 0XF000: {
      wint_t wc = convertCharToWchar(character & UNICODE_CELL_MASK);
      if (wc == WEOF) goto unknownCharacter;
      character = wc;
    }

    default: {
      const unsigned char *cell;
      if ((cell = getUnicodeCellEntry(table, character))) return *cell;

    unknownCharacter:
      if ((cell = getUnicodeCellEntry(table, UNICODE_REPLACEMENT_CHARACTER))) return *cell;
      if ((cell = getUnicodeCellEntry(table, WC_C('?')))) return *cell;
      return BRL_DOT1 | BRL_DOT2 | BRL_DOT3 | BRL_DOT4 | BRL_DOT5 | BRL_DOT6 | BRL_DOT7 | BRL_DOT8;
    }
  }
}

wchar_t
convertDotsToCharacter (TextTable *table, unsigned char dots) {
  const TextTableHeader *header = table->header.fields;
  if (BITMASK_TEST(header->dotsCharacterDefined, dots)) return header->dotsToCharacter[dots];
  return UNICODE_REPLACEMENT_CHARACTER;
}

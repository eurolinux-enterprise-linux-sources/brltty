# Android/Application/Makefile.  Generated from Makefile.in by configure.
###############################################################################
# BRLTTY - A background process providing access to the console screen (when in
#          text mode) for a blind person using a refreshable braille display.
#
# Copyright (C) 1995-2013 by The BRLTTY Developers.
#
# BRLTTY comes with ABSOLUTELY NO WARRANTY.
#
# This is free software, placed under the terms of the
# GNU General Public License, as published by the Free Software
# Foundation; either version 2 of the License, or (at your option) any
# later version. Please see the file LICENSE-GPL for details.
#
# Web Page: http://mielke.cc/brltty/
#
# This software is maintained by Dave Mielke <dave@mielke.cc>.
###############################################################################

SRC_TOP = ../../
SRC_DIR = .
# VPATH = .

BLD_TOP = ./../../
BLD_DIR = .

include $(SRC_TOP)common.mk

ANDROID_PACKAGE_NAME = BRLTTY_App
ANDROID_PACKAGE_PATH = org.a11y.brltty.android
include $(SRC_TOP)Android/common.mk

ANDROID_TABLES_DIRECTORY = $(ANDROID_ASSETS_DIRECTORY)/tables
ANDROID_DRIVERS_DIRECTORY = $(ANDROID_ASSETS_DIRECTORY)/drivers

all:: core tables $(BRAILLE_DRIVERS) $(SPEECH_DRIVERS) $(SCREEN_DRIVERS)

core:
	cd ../Core && $(MAKE)

tables-directory:
	$(INSTALL_DIRECTORY) $(ANDROID_TABLES_DIRECTORY)

tables: tables-directory
	$(INSTALL_DATA) $(SRC_TOP)$(TBL_DIR)/*.[tack]t[bi] $(ANDROID_TABLES_DIRECTORY)

drivers-directory:
	$(INSTALL_DIRECTORY) $(ANDROID_DRIVERS_DIRECTORY)

braille-drivers: drivers-directory
	$(INSTALL_DATA) $(BLD_TOP)$(DRV_DIR)/$(MOD_NAME)b?*.$(MOD_EXT) $(ANDROID_DRIVERS_DIRECTORY)

speech-drivers: drivers-directory
	$(INSTALL_DATA) $(BLD_TOP)$(DRV_DIR)/$(MOD_NAME)s?*.$(MOD_EXT) $(ANDROID_DRIVERS_DIRECTORY)

screen-drivers: drivers-directory
	$(INSTALL_DATA) $(BLD_TOP)$(DRV_DIR)/$(MOD_NAME)x?*.$(MOD_EXT) $(ANDROID_DRIVERS_DIRECTORY)


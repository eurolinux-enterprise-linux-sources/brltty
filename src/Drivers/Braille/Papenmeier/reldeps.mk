# Dependencies for braille.$O:
braille.$O: $(SRC_DIR)/braille.c
braille.$O: $(BLD_TOP)config.h
braille.$O: $(SRC_TOP)prologue.h
braille.$O: $(SRC_TOP)Programs/misc.h
braille.$O: $(SRC_TOP)Programs/message.h
braille.$O: $(SRC_TOP)Programs/brl.h
braille.$O: $(SRC_TOP)Programs/brl_driver.h
braille.$O: $(SRC_TOP)Programs/brldefs.h
braille.$O: $(SRC_TOP)Programs/driver.h
braille.$O: $(SRC_DIR)/braille.h
braille.$O: config.tab.c
braille.$O: $(SRC_DIR)/brl-cfg.h
braille.$O: $(SRC_TOP)Programs/io_defs.h
braille.$O: $(SRC_TOP)Programs/io_serial.h
braille.$O: $(SRC_TOP)Programs/io_usb.h
braille.$O: $(SRC_TOP)Programs/io_bluetooth.h
braille.$O: $(SRC_TOP)Programs/io_misc.h

# Dependencies for config.tab.c:
config.tab.c: $(SRC_DIR)/config.y
config.tab.c: $(BLD_TOP)config.h
config.tab.c: $(SRC_TOP)prologue.h
config.tab.c: $(SRC_DIR)/brl-cfg.h
config.tab.c: $(SRC_TOP)Programs/brl.h
config.tab.c: $(SRC_TOP)Programs/brldefs.h
config.tab.c: $(SRC_TOP)Programs/driver.h
config.tab.c: cmd.auto.h
config.tab.c: hlp.auto.h

# Dependencies for read_config.$O:
read_config.$O: $(SRC_DIR)/read_config.c
read_config.$O: $(BLD_TOP)config.h
read_config.$O: $(SRC_TOP)prologue.h
read_config.$O: $(BLD_TOP)Programs/brlapi_constants.h
read_config.$O: $(SRC_TOP)Programs/brlapi_keycodes.h
read_config.$O: $(SRC_TOP)Programs/cmd.h
read_config.$O: config.tab.c


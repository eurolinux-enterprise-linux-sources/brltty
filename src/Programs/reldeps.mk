# Dependencies for adlib.$O:
adlib.$O: $(SRC_DIR)/adlib.c
adlib.$O: $(BLD_TOP)config.h
adlib.$O: $(SRC_TOP)prologue.h
adlib.$O: $(SRC_DIR)/misc.h
adlib.$O: $(SRC_DIR)/bitmask.h
adlib.$O: $(SRC_DIR)/keyboard.h
adlib.$O: $(SRC_DIR)/keycodes.h
adlib.$O: $(SRC_DIR)/system.h
adlib.$O: $(SRC_DIR)/adlib.h

# Dependencies for apitest.$O:
apitest.$O: $(SRC_DIR)/apitest.c
apitest.$O: $(BLD_TOP)config.h
apitest.$O: $(SRC_TOP)prologue.h
apitest.$O: $(SRC_DIR)/options.h
apitest.$O: $(SRC_DIR)/brldefs.h
apitest.$O: brlapi_constants.h
apitest.$O: $(SRC_DIR)/brlapi_keycodes.h
apitest.$O: $(SRC_DIR)/cmd.h
apitest.$O: brlapi.h

# Dependencies for async.$O:
async.$O: $(SRC_DIR)/async.c
async.$O: $(BLD_TOP)config.h
async.$O: $(SRC_TOP)prologue.h
async.$O: $(SRC_DIR)/sys_msdos.h
async.$O: $(SRC_DIR)/misc.h
async.$O: $(SRC_DIR)/queue.h
async.$O: $(SRC_DIR)/async.h

# Dependencies for atb_compile.$O:
atb_compile.$O: $(SRC_DIR)/atb_compile.c
atb_compile.$O: $(BLD_TOP)config.h
atb_compile.$O: $(SRC_TOP)prologue.h
atb_compile.$O: $(SRC_DIR)/misc.h
atb_compile.$O: $(SRC_DIR)/datafile.h
atb_compile.$O: $(SRC_DIR)/dataarea.h
atb_compile.$O: $(SRC_DIR)/atb.h
atb_compile.$O: $(SRC_DIR)/atb_internal.h

# Dependencies for atb_translate.$O:
atb_translate.$O: $(SRC_DIR)/atb_translate.c
atb_translate.$O: $(BLD_TOP)config.h
atb_translate.$O: $(SRC_TOP)prologue.h
atb_translate.$O: $(SRC_DIR)/atb.h
atb_translate.$O: $(SRC_DIR)/atb_internal.h
atb_translate.$O: attr.auto.h

# Dependencies for auth.$O:
auth.$O: $(SRC_DIR)/auth.c
auth.$O: $(BLD_TOP)config.h
auth.$O: $(SRC_TOP)prologue.h
auth.$O: $(SRC_DIR)/misc.h
auth.$O: $(SRC_DIR)/auth.h

# Dependencies for beeper.$O:
beeper.$O: $(SRC_DIR)/beeper.c
beeper.$O: $(BLD_TOP)config.h
beeper.$O: $(SRC_TOP)prologue.h
beeper.$O: $(SRC_DIR)/misc.h
beeper.$O: $(SRC_DIR)/bitmask.h
beeper.$O: $(SRC_DIR)/keyboard.h
beeper.$O: $(SRC_DIR)/keycodes.h
beeper.$O: $(SRC_DIR)/system.h
beeper.$O: $(SRC_DIR)/notes.h

# Dependencies for bluetooth.$O:
bluetooth.$O: $(SRC_DIR)/bluetooth.c
bluetooth.$O: $(BLD_TOP)config.h
bluetooth.$O: $(SRC_TOP)prologue.h
bluetooth.$O: $(SRC_DIR)/misc.h
bluetooth.$O: $(SRC_DIR)/queue.h
bluetooth.$O: $(SRC_DIR)/io_misc.h
bluetooth.$O: $(SRC_DIR)/io_bluetooth.h
bluetooth.$O: $(SRC_DIR)/bluetooth_internal.h

# Dependencies for bluetooth_linux.$O:
bluetooth_linux.$O: $(SRC_DIR)/bluetooth_linux.c
bluetooth_linux.$O: $(BLD_TOP)config.h
bluetooth_linux.$O: $(SRC_TOP)prologue.h
bluetooth_linux.$O: $(SRC_DIR)/misc.h
bluetooth_linux.$O: $(SRC_DIR)/io_bluetooth.h
bluetooth_linux.$O: $(SRC_DIR)/bluetooth_internal.h

# Dependencies for bluetooth_skeleton.$O:
bluetooth_skeleton.$O: $(SRC_DIR)/bluetooth_skeleton.c
bluetooth_skeleton.$O: $(BLD_TOP)config.h
bluetooth_skeleton.$O: $(SRC_TOP)prologue.h
bluetooth_skeleton.$O: $(SRC_DIR)/misc.h
bluetooth_skeleton.$O: $(SRC_DIR)/io_bluetooth.h
bluetooth_skeleton.$O: $(SRC_DIR)/bluetooth_internal.h

# Dependencies for brl.$O:
brl.$O: $(SRC_DIR)/brl.c
brl.$O: $(BLD_TOP)config.h
brl.$O: $(SRC_TOP)prologue.h
brl.$O: $(SRC_DIR)/misc.h
brl.$O: $(SRC_DIR)/async.h
brl.$O: $(SRC_DIR)/message.h
brl.$O: $(SRC_DIR)/charset.h
brl.$O: $(SRC_DIR)/lock.h
brl.$O: $(SRC_DIR)/unicode.h
brl.$O: $(SRC_DIR)/driver.h
brl.$O: $(SRC_DIR)/drivers.h
brl.$O: $(SRC_DIR)/brl.h
brl.$O: $(SRC_DIR)/brldefs.h
brl.$O: $(SRC_DIR)/ttb.h
brl.$O: brl.auto.h
brl.$O: brlapi_constants.h
brl.$O: $(SRC_DIR)/brlapi_keycodes.h
brl.$O: $(SRC_DIR)/cmd.h
brl.$O: $(SRC_DIR)/brl_driver.h

# Dependencies for brlapi_client.$O:
brlapi_client.$O: $(SRC_DIR)/brlapi_client.c
brlapi_client.$O: $(BLD_TOP)config.h
brlapi_client.$O: $(SRC_TOP)prologue.h
brlapi_client.$O: $(SRC_DIR)/misc.h
brlapi_client.$O: $(SRC_DIR)/win_pthread.h
brlapi_client.$O: brlapi.h
brlapi_client.$O: brlapi_constants.h
brlapi_client.$O: $(SRC_DIR)/brlapi_keycodes.h
brlapi_client.$O: $(SRC_DIR)/brlapi_protocol.h
brlapi_client.$O: $(SRC_DIR)/brlapi_common.h
brlapi_client.$O: brlapi_keytab.auto.h

# Dependencies for brlapi_keyranges.$O:
brlapi_keyranges.$O: $(SRC_DIR)/brlapi_keyranges.c
brlapi_keyranges.$O: $(BLD_TOP)config.h
brlapi_keyranges.$O: $(SRC_TOP)prologue.h
brlapi_keyranges.$O: $(SRC_DIR)/brlapi_keyranges.h
brlapi_keyranges.$O: $(SRC_DIR)/misc.h

# Dependencies for brlapi_server.$O:
brlapi_server.$O: $(SRC_DIR)/brlapi_server.c
brlapi_server.$O: $(BLD_TOP)config.h
brlapi_server.$O: $(SRC_TOP)prologue.h
brlapi_server.$O: $(SRC_DIR)/sys_windows.h
brlapi_server.$O: $(SRC_DIR)/misc.h
brlapi_server.$O: $(SRC_DIR)/win_pthread.h
brlapi_server.$O: brlapi.h
brlapi_server.$O: brlapi_constants.h
brlapi_server.$O: $(SRC_DIR)/brlapi_keycodes.h
brlapi_server.$O: $(SRC_DIR)/brlapi_protocol.h
brlapi_server.$O: $(SRC_DIR)/brlapi_keyranges.h
brlapi_server.$O: $(SRC_DIR)/cmd.h
brlapi_server.$O: $(SRC_DIR)/brl.h
brlapi_server.$O: $(SRC_DIR)/brldefs.h
brlapi_server.$O: $(SRC_DIR)/driver.h
brlapi_server.$O: $(SRC_DIR)/ttb.h
brlapi_server.$O: $(SRC_DIR)/bitmask.h
brlapi_server.$O: $(SRC_DIR)/brltty.h
brlapi_server.$O: $(SRC_DIR)/ctb.h
brlapi_server.$O: $(SRC_DIR)/keycodes.h
brlapi_server.$O: $(SRC_DIR)/ktb.h
brlapi_server.$O: $(SRC_DIR)/spk.h
brlapi_server.$O: $(SRC_DIR)/auth.h
brlapi_server.$O: $(SRC_DIR)/io_misc.h
brlapi_server.$O: $(SRC_DIR)/scr.h
brlapi_server.$O: $(SRC_DIR)/tunes.h
brlapi_server.$O: $(SRC_DIR)/charset.h
brlapi_server.$O: $(SRC_DIR)/lock.h
brlapi_server.$O: $(SRC_DIR)/brlapi_common.h

# Dependencies for brltest.$O:
brltest.$O: $(SRC_DIR)/brltest.c
brltest.$O: $(BLD_TOP)config.h
brltest.$O: $(SRC_TOP)prologue.h
brltest.$O: $(SRC_DIR)/program.h
brltest.$O: $(SRC_DIR)/options.h
brltest.$O: $(SRC_DIR)/brl.h
brltest.$O: $(SRC_DIR)/brldefs.h
brltest.$O: $(SRC_DIR)/driver.h
brltest.$O: $(SRC_DIR)/misc.h
brltest.$O: $(SRC_DIR)/charset.h
brltest.$O: $(SRC_DIR)/lock.h
brltest.$O: $(SRC_DIR)/message.h
brltest.$O: $(SRC_DIR)/defaults.h

# Dependencies for brltty.$O:
brltty.$O: $(SRC_DIR)/brltty.c
brltty.$O: $(BLD_TOP)config.h
brltty.$O: $(SRC_TOP)prologue.h
brltty.$O: $(SRC_DIR)/misc.h
brltty.$O: $(SRC_DIR)/message.h
brltty.$O: $(SRC_DIR)/tunes.h
brltty.$O: $(SRC_DIR)/ttb.h
brltty.$O: $(SRC_DIR)/atb.h
brltty.$O: $(SRC_DIR)/ctb.h
brltty.$O: $(SRC_DIR)/routing.h
brltty.$O: $(SRC_DIR)/cut.h
brltty.$O: $(SRC_DIR)/brl.h
brltty.$O: $(SRC_DIR)/brldefs.h
brltty.$O: $(SRC_DIR)/driver.h
brltty.$O: $(SRC_DIR)/touch.h
brltty.$O: brlapi_constants.h
brltty.$O: $(SRC_DIR)/brlapi_keycodes.h
brltty.$O: $(SRC_DIR)/cmd.h
brltty.$O: $(SRC_DIR)/charset.h
brltty.$O: $(SRC_DIR)/lock.h
brltty.$O: $(SRC_DIR)/unicode.h
brltty.$O: $(SRC_DIR)/scancodes.h
brltty.$O: $(SRC_DIR)/scr.h
brltty.$O: $(SRC_DIR)/bitmask.h
brltty.$O: $(SRC_DIR)/brltty.h
brltty.$O: $(SRC_DIR)/keycodes.h
brltty.$O: $(SRC_DIR)/ktb.h
brltty.$O: $(SRC_DIR)/spk.h
brltty.$O: $(SRC_DIR)/defaults.h

# Dependencies for charset.$O:
charset.$O: $(SRC_DIR)/charset.c
charset.$O: $(BLD_TOP)config.h
charset.$O: $(SRC_TOP)prologue.h
charset.$O: $(SRC_DIR)/sys_msdos.h
charset.$O: $(SRC_DIR)/misc.h
charset.$O: $(SRC_DIR)/lock.h
charset.$O: $(SRC_DIR)/charset.h
charset.$O: $(SRC_DIR)/unicode.h

# Dependencies for cmd.$O:
cmd.$O: $(SRC_DIR)/cmd.c
cmd.$O: $(BLD_TOP)config.h
cmd.$O: $(SRC_TOP)prologue.h
cmd.$O: $(SRC_DIR)/misc.h
cmd.$O: $(SRC_DIR)/brldefs.h
cmd.$O: brlapi_constants.h
cmd.$O: $(SRC_DIR)/brlapi_keycodes.h
cmd.$O: $(SRC_DIR)/cmd.h
cmd.$O: $(SRC_DIR)/ttb.h
cmd.$O: $(SRC_DIR)/charset.h
cmd.$O: $(SRC_DIR)/lock.h
cmd.$O: $(SRC_DIR)/queue.h
cmd.$O: cmds.auto.h

# Dependencies for config.$O:
config.$O: $(SRC_DIR)/config.c
config.$O: $(BLD_TOP)config.h
config.$O: $(SRC_TOP)prologue.h
config.$O: brlapi_constants.h
config.$O: $(SRC_DIR)/brlapi_keycodes.h
config.$O: $(SRC_DIR)/cmd.h
config.$O: $(SRC_DIR)/brl.h
config.$O: $(SRC_DIR)/brldefs.h
config.$O: $(SRC_DIR)/driver.h
config.$O: $(SRC_DIR)/spk.h
config.$O: $(SRC_DIR)/scr.h
config.$O: $(SRC_DIR)/ttb.h
config.$O: $(SRC_DIR)/atb.h
config.$O: $(SRC_DIR)/ctb.h
config.$O: $(SRC_DIR)/bitmask.h
config.$O: $(SRC_DIR)/keycodes.h
config.$O: $(SRC_DIR)/ktb.h
config.$O: $(SRC_DIR)/tunes.h
config.$O: $(SRC_DIR)/message.h
config.$O: $(SRC_DIR)/misc.h
config.$O: $(SRC_DIR)/keyboard.h
config.$O: $(SRC_DIR)/system.h
config.$O: $(SRC_DIR)/async.h
config.$O: $(SRC_DIR)/program.h
config.$O: $(SRC_DIR)/options.h
config.$O: $(SRC_DIR)/brltty.h
config.$O: $(SRC_DIR)/defaults.h
config.$O: $(SRC_DIR)/io_defs.h
config.$O: $(SRC_DIR)/io_serial.h
config.$O: $(SRC_DIR)/io_usb.h
config.$O: $(SRC_DIR)/io_bluetooth.h
config.$O: $(SRC_DIR)/sys_windows.h
config.$O: $(SRC_DIR)/sys_msdos.h

# Dependencies for ctb_compile.$O:
ctb_compile.$O: $(SRC_DIR)/ctb_compile.c
ctb_compile.$O: $(BLD_TOP)config.h
ctb_compile.$O: $(SRC_TOP)prologue.h
ctb_compile.$O: $(SRC_DIR)/misc.h
ctb_compile.$O: $(SRC_DIR)/ctb.h
ctb_compile.$O: $(SRC_DIR)/ctb_internal.h
ctb_compile.$O: $(SRC_DIR)/datafile.h
ctb_compile.$O: $(SRC_DIR)/dataarea.h
ctb_compile.$O: $(SRC_DIR)/brldots.h

# Dependencies for ctb_translate.$O:
ctb_translate.$O: $(SRC_DIR)/ctb_translate.c
ctb_translate.$O: $(BLD_TOP)config.h
ctb_translate.$O: $(SRC_TOP)prologue.h
ctb_translate.$O: $(SRC_DIR)/ctb.h
ctb_translate.$O: $(SRC_DIR)/ctb_internal.h
ctb_translate.$O: $(SRC_DIR)/unicode.h
ctb_translate.$O: $(SRC_DIR)/brldots.h

# Dependencies for ctbtest.$O:
ctbtest.$O: $(SRC_DIR)/ctbtest.c
ctbtest.$O: $(BLD_TOP)config.h
ctbtest.$O: $(SRC_TOP)prologue.h
ctbtest.$O: $(SRC_DIR)/program.h
ctbtest.$O: $(SRC_DIR)/options.h
ctbtest.$O: $(SRC_DIR)/misc.h
ctbtest.$O: $(SRC_DIR)/charset.h
ctbtest.$O: $(SRC_DIR)/lock.h
ctbtest.$O: $(SRC_DIR)/unicode.h
ctbtest.$O: $(SRC_DIR)/ttb.h
ctbtest.$O: $(SRC_DIR)/ctb.h

# Dependencies for cut.$O:
cut.$O: $(SRC_DIR)/cut.c
cut.$O: $(BLD_TOP)config.h
cut.$O: $(SRC_TOP)prologue.h
cut.$O: $(SRC_DIR)/driver.h
cut.$O: $(SRC_DIR)/scr.h
cut.$O: $(SRC_DIR)/tunes.h
cut.$O: $(SRC_DIR)/cut.h

# Dependencies for dataarea.$O:
dataarea.$O: $(SRC_DIR)/dataarea.c
dataarea.$O: $(BLD_TOP)config.h
dataarea.$O: $(SRC_TOP)prologue.h
dataarea.$O: $(SRC_DIR)/misc.h
dataarea.$O: $(SRC_DIR)/dataarea.h

# Dependencies for datafile.$O:
datafile.$O: $(SRC_DIR)/datafile.c
datafile.$O: $(BLD_TOP)config.h
datafile.$O: $(SRC_TOP)prologue.h
datafile.$O: $(SRC_DIR)/misc.h
datafile.$O: $(SRC_DIR)/datafile.h
datafile.$O: $(SRC_DIR)/charset.h
datafile.$O: $(SRC_DIR)/lock.h
datafile.$O: $(SRC_DIR)/brldots.h

# Dependencies for drivers.$O:
drivers.$O: $(SRC_DIR)/drivers.c
drivers.$O: $(BLD_TOP)config.h
drivers.$O: $(SRC_TOP)prologue.h
drivers.$O: $(SRC_DIR)/misc.h
drivers.$O: $(SRC_DIR)/bitmask.h
drivers.$O: $(SRC_DIR)/keyboard.h
drivers.$O: $(SRC_DIR)/keycodes.h
drivers.$O: $(SRC_DIR)/system.h
drivers.$O: $(SRC_DIR)/driver.h
drivers.$O: $(SRC_DIR)/drivers.h

# Dependencies for fm.$O:
fm.$O: $(SRC_DIR)/fm.c
fm.$O: $(BLD_TOP)config.h
fm.$O: $(SRC_TOP)prologue.h
fm.$O: $(SRC_DIR)/bitmask.h
fm.$O: $(SRC_DIR)/brl.h
fm.$O: brlapi_constants.h
fm.$O: $(SRC_DIR)/brlapi_keycodes.h
fm.$O: $(SRC_DIR)/brldefs.h
fm.$O: $(SRC_DIR)/brltty.h
fm.$O: $(SRC_DIR)/cmd.h
fm.$O: $(SRC_DIR)/ctb.h
fm.$O: $(SRC_DIR)/driver.h
fm.$O: $(SRC_DIR)/keycodes.h
fm.$O: $(SRC_DIR)/ktb.h
fm.$O: $(SRC_DIR)/spk.h
fm.$O: $(SRC_DIR)/misc.h
fm.$O: $(SRC_DIR)/notes.h
fm.$O: $(SRC_DIR)/adlib.h

# Dependencies for io_misc.$O:
io_misc.$O: $(SRC_DIR)/io_misc.c
io_misc.$O: $(BLD_TOP)config.h
io_misc.$O: $(SRC_TOP)prologue.h
io_misc.$O: $(SRC_DIR)/io_misc.h
io_misc.$O: $(SRC_DIR)/misc.h
io_misc.$O: $(SRC_DIR)/sys_msdos.h

# Dependencies for keyboard.$O:
keyboard.$O: $(SRC_DIR)/keyboard.c
keyboard.$O: $(BLD_TOP)config.h
keyboard.$O: $(SRC_TOP)prologue.h
keyboard.$O: $(SRC_DIR)/keyboard.h
keyboard.$O: $(SRC_DIR)/misc.h

# Dependencies for keycodes.$O:
keycodes.$O: $(SRC_DIR)/keycodes.c
keycodes.$O: $(BLD_TOP)config.h
keycodes.$O: $(SRC_TOP)prologue.h
keycodes.$O: $(SRC_DIR)/bitmask.h
keycodes.$O: $(SRC_DIR)/keycodes.h

# Dependencies for ktb_compile.$O:
ktb_compile.$O: $(SRC_DIR)/ktb_compile.c
ktb_compile.$O: $(BLD_TOP)config.h
ktb_compile.$O: $(SRC_TOP)prologue.h
ktb_compile.$O: $(SRC_DIR)/misc.h
ktb_compile.$O: $(SRC_DIR)/datafile.h
ktb_compile.$O: $(SRC_DIR)/dataarea.h
ktb_compile.$O: brlapi_constants.h
ktb_compile.$O: $(SRC_DIR)/brlapi_keycodes.h
ktb_compile.$O: $(SRC_DIR)/cmd.h
ktb_compile.$O: $(SRC_DIR)/brldefs.h
ktb_compile.$O: $(SRC_DIR)/bitmask.h
ktb_compile.$O: $(SRC_DIR)/keycodes.h
ktb_compile.$O: $(SRC_DIR)/ktb.h
ktb_compile.$O: $(SRC_DIR)/ktb_internal.h
ktb_compile.$O: $(SRC_DIR)/ktb_keynames.h

# Dependencies for ktb_translate.$O:
ktb_translate.$O: $(SRC_DIR)/ktb_translate.c
ktb_translate.$O: $(BLD_TOP)config.h
ktb_translate.$O: $(SRC_TOP)prologue.h
ktb_translate.$O: $(SRC_DIR)/misc.h
ktb_translate.$O: $(SRC_DIR)/bitmask.h
ktb_translate.$O: $(SRC_DIR)/keycodes.h
ktb_translate.$O: $(SRC_DIR)/ktb.h
ktb_translate.$O: $(SRC_DIR)/ktb_internal.h

# Dependencies for lock.$O:
lock.$O: $(SRC_DIR)/lock.c
lock.$O: $(BLD_TOP)config.h
lock.$O: $(SRC_TOP)prologue.h
lock.$O: $(SRC_DIR)/misc.h
lock.$O: $(SRC_DIR)/win_pthread.h
lock.$O: $(SRC_DIR)/lock.h

# Dependencies for midi.$O:
midi.$O: $(SRC_DIR)/midi.c
midi.$O: $(BLD_TOP)config.h
midi.$O: $(SRC_TOP)prologue.h
midi.$O: $(SRC_DIR)/bitmask.h
midi.$O: $(SRC_DIR)/brl.h
midi.$O: brlapi_constants.h
midi.$O: $(SRC_DIR)/brlapi_keycodes.h
midi.$O: $(SRC_DIR)/brldefs.h
midi.$O: $(SRC_DIR)/brltty.h
midi.$O: $(SRC_DIR)/cmd.h
midi.$O: $(SRC_DIR)/ctb.h
midi.$O: $(SRC_DIR)/driver.h
midi.$O: $(SRC_DIR)/keycodes.h
midi.$O: $(SRC_DIR)/ktb.h
midi.$O: $(SRC_DIR)/spk.h
midi.$O: $(SRC_DIR)/misc.h
midi.$O: $(SRC_DIR)/keyboard.h
midi.$O: $(SRC_DIR)/system.h
midi.$O: $(SRC_DIR)/notes.h

# Dependencies for misc.$O:
misc.$O: $(SRC_DIR)/misc.c
misc.$O: $(BLD_TOP)config.h
misc.$O: $(SRC_TOP)prologue.h
misc.$O: $(SRC_DIR)/misc.h
misc.$O: $(SRC_DIR)/sys_msdos.h

# Dependencies for mount.$O:
mount.$O: $(SRC_DIR)/mount.c
mount.$O: $(BLD_TOP)config.h
mount.$O: $(SRC_TOP)prologue.h
mount.$O: $(SRC_DIR)/misc.h
mount.$O: $(SRC_DIR)/bitmask.h
mount.$O: $(SRC_DIR)/keyboard.h
mount.$O: $(SRC_DIR)/keycodes.h
mount.$O: $(SRC_DIR)/system.h
mount.$O: $(SRC_DIR)/async.h
mount.$O: $(SRC_DIR)/mount.h

# Dependencies for options.$O:
options.$O: $(SRC_DIR)/options.c
options.$O: $(BLD_TOP)config.h
options.$O: $(SRC_TOP)prologue.h
options.$O: $(SRC_DIR)/program.h
options.$O: $(SRC_DIR)/options.h
options.$O: $(SRC_DIR)/misc.h
options.$O: $(SRC_DIR)/bitmask.h
options.$O: $(SRC_DIR)/keyboard.h
options.$O: $(SRC_DIR)/keycodes.h
options.$O: $(SRC_DIR)/system.h

# Dependencies for pcm.$O:
pcm.$O: $(SRC_DIR)/pcm.c
pcm.$O: $(BLD_TOP)config.h
pcm.$O: $(SRC_TOP)prologue.h
pcm.$O: $(SRC_DIR)/bitmask.h
pcm.$O: $(SRC_DIR)/brl.h
pcm.$O: brlapi_constants.h
pcm.$O: $(SRC_DIR)/brlapi_keycodes.h
pcm.$O: $(SRC_DIR)/brldefs.h
pcm.$O: $(SRC_DIR)/brltty.h
pcm.$O: $(SRC_DIR)/cmd.h
pcm.$O: $(SRC_DIR)/ctb.h
pcm.$O: $(SRC_DIR)/driver.h
pcm.$O: $(SRC_DIR)/keycodes.h
pcm.$O: $(SRC_DIR)/ktb.h
pcm.$O: $(SRC_DIR)/spk.h
pcm.$O: $(SRC_DIR)/misc.h
pcm.$O: $(SRC_DIR)/keyboard.h
pcm.$O: $(SRC_DIR)/system.h
pcm.$O: $(SRC_DIR)/notes.h

# Dependencies for program.$O:
program.$O: $(SRC_DIR)/program.c
program.$O: $(BLD_TOP)config.h
program.$O: $(SRC_TOP)prologue.h
program.$O: $(SRC_DIR)/program.h
program.$O: $(SRC_DIR)/misc.h
program.$O: $(SRC_DIR)/bitmask.h
program.$O: $(SRC_DIR)/keyboard.h
program.$O: $(SRC_DIR)/keycodes.h
program.$O: $(SRC_DIR)/system.h
program.$O: $(SRC_DIR)/sys_windows.h

# Dependencies for queue.$O:
queue.$O: $(SRC_DIR)/queue.c
queue.$O: $(BLD_TOP)config.h
queue.$O: $(SRC_TOP)prologue.h
queue.$O: $(SRC_DIR)/misc.h
queue.$O: $(SRC_DIR)/queue.h

# Dependencies for routing.$O:
routing.$O: $(SRC_DIR)/routing.c
routing.$O: $(BLD_TOP)config.h
routing.$O: $(SRC_TOP)prologue.h
routing.$O: $(SRC_DIR)/misc.h
routing.$O: $(SRC_DIR)/driver.h
routing.$O: $(SRC_DIR)/scr.h
routing.$O: $(SRC_DIR)/routing.h

# Dependencies for scancodes.$O:
scancodes.$O: $(SRC_DIR)/scancodes.c
scancodes.$O: $(BLD_TOP)config.h
scancodes.$O: $(SRC_TOP)prologue.h
scancodes.$O: $(SRC_DIR)/scancodes.h
scancodes.$O: $(SRC_DIR)/brldefs.h

# Dependencies for scr.$O:
scr.$O: $(SRC_DIR)/scr.c
scr.$O: $(BLD_TOP)config.h
scr.$O: $(SRC_TOP)prologue.h
scr.$O: $(SRC_DIR)/misc.h
scr.$O: $(SRC_DIR)/bitmask.h
scr.$O: $(SRC_DIR)/keyboard.h
scr.$O: $(SRC_DIR)/keycodes.h
scr.$O: $(SRC_DIR)/system.h
scr.$O: $(SRC_DIR)/driver.h
scr.$O: $(SRC_DIR)/drivers.h
scr.$O: $(SRC_DIR)/scr.h
scr.$O: $(SRC_DIR)/scr_base.h
scr.$O: $(SRC_DIR)/scr_frozen.h
scr.$O: $(SRC_DIR)/help.h
scr.$O: $(SRC_DIR)/scr_help.h
scr.$O: $(SRC_DIR)/scr_main.h
scr.$O: $(SRC_DIR)/scr_real.h
scr.$O: scr.auto.h
scr.$O: $(SRC_DIR)/scr_driver.h

# Dependencies for scr_base.$O:
scr_base.$O: $(SRC_DIR)/scr_base.c
scr_base.$O: $(BLD_TOP)config.h
scr_base.$O: $(SRC_TOP)prologue.h
scr_base.$O: $(SRC_DIR)/misc.h
scr_base.$O: $(SRC_DIR)/driver.h
scr_base.$O: $(SRC_DIR)/scr.h
scr_base.$O: $(SRC_DIR)/scr_base.h

# Dependencies for scr_frozen.$O:
scr_frozen.$O: $(SRC_DIR)/scr_frozen.c
scr_frozen.$O: $(BLD_TOP)config.h
scr_frozen.$O: $(SRC_TOP)prologue.h
scr_frozen.$O: $(SRC_DIR)/misc.h
scr_frozen.$O: $(SRC_DIR)/driver.h
scr_frozen.$O: $(SRC_DIR)/scr.h
scr_frozen.$O: $(SRC_DIR)/scr_base.h
scr_frozen.$O: $(SRC_DIR)/scr_frozen.h

# Dependencies for scr_help.$O:
scr_help.$O: $(SRC_DIR)/scr_help.c
scr_help.$O: $(BLD_TOP)config.h
scr_help.$O: $(SRC_TOP)prologue.h
scr_help.$O: $(SRC_DIR)/misc.h
scr_help.$O: $(SRC_DIR)/driver.h
scr_help.$O: $(SRC_DIR)/scr.h
scr_help.$O: $(SRC_DIR)/help.h
scr_help.$O: $(SRC_DIR)/scr_base.h
scr_help.$O: $(SRC_DIR)/scr_help.h

# Dependencies for scr_main.$O:
scr_main.$O: $(SRC_DIR)/scr_main.c
scr_main.$O: $(BLD_TOP)config.h
scr_main.$O: $(SRC_TOP)prologue.h
scr_main.$O: $(SRC_DIR)/misc.h
scr_main.$O: $(SRC_DIR)/driver.h
scr_main.$O: $(SRC_DIR)/scr.h
scr_main.$O: $(SRC_DIR)/scr_base.h
scr_main.$O: $(SRC_DIR)/scr_main.h

# Dependencies for scr_real.$O:
scr_real.$O: $(SRC_DIR)/scr_real.c
scr_real.$O: $(BLD_TOP)config.h
scr_real.$O: $(SRC_TOP)prologue.h
scr_real.$O: $(SRC_DIR)/misc.h
scr_real.$O: $(SRC_DIR)/async.h
scr_real.$O: $(SRC_DIR)/driver.h
scr_real.$O: $(SRC_DIR)/scr.h
scr_real.$O: $(SRC_DIR)/scr_base.h
scr_real.$O: $(SRC_DIR)/scr_main.h
scr_real.$O: $(SRC_DIR)/scr_real.h
scr_real.$O: $(SRC_DIR)/routing.h

# Dependencies for scrtest.$O:
scrtest.$O: $(SRC_DIR)/scrtest.c
scrtest.$O: $(BLD_TOP)config.h
scrtest.$O: $(SRC_TOP)prologue.h
scrtest.$O: $(SRC_DIR)/program.h
scrtest.$O: $(SRC_DIR)/options.h
scrtest.$O: $(SRC_DIR)/misc.h
scrtest.$O: $(SRC_DIR)/driver.h
scrtest.$O: $(SRC_DIR)/scr.h

# Dependencies for serial.$O:
serial.$O: $(SRC_DIR)/serial.c
serial.$O: $(BLD_TOP)config.h
serial.$O: $(SRC_TOP)prologue.h
serial.$O: $(SRC_DIR)/misc.h
serial.$O: $(SRC_DIR)/win_pthread.h
serial.$O: $(SRC_DIR)/bitmask.h
serial.$O: $(SRC_DIR)/keyboard.h
serial.$O: $(SRC_DIR)/keycodes.h
serial.$O: $(SRC_DIR)/system.h
serial.$O: $(SRC_DIR)/io_defs.h
serial.$O: $(SRC_DIR)/io_serial.h
serial.$O: $(SRC_DIR)/io_misc.h

# Dependencies for spk.$O:
spk.$O: $(SRC_DIR)/spk.c
spk.$O: $(BLD_TOP)config.h
spk.$O: $(SRC_TOP)prologue.h
spk.$O: $(SRC_DIR)/misc.h
spk.$O: $(SRC_DIR)/charset.h
spk.$O: $(SRC_DIR)/lock.h
spk.$O: $(SRC_DIR)/driver.h
spk.$O: $(SRC_DIR)/drivers.h
spk.$O: $(SRC_DIR)/spk.h
spk.$O: spk.auto.h
spk.$O: $(SRC_DIR)/spk_driver.h

# Dependencies for spktest.$O:
spktest.$O: $(SRC_DIR)/spktest.c
spktest.$O: $(BLD_TOP)config.h
spktest.$O: $(SRC_TOP)prologue.h
spktest.$O: $(SRC_DIR)/program.h
spktest.$O: $(SRC_DIR)/options.h
spktest.$O: $(SRC_DIR)/driver.h
spktest.$O: $(SRC_DIR)/spk.h
spktest.$O: $(SRC_DIR)/misc.h

# Dependencies for sys_darwin.$O:
sys_darwin.$O: $(SRC_DIR)/sys_darwin.c
sys_darwin.$O: $(BLD_TOP)config.h
sys_darwin.$O: $(SRC_TOP)prologue.h
sys_darwin.$O: $(SRC_DIR)/misc.h
sys_darwin.$O: $(SRC_DIR)/bitmask.h
sys_darwin.$O: $(SRC_DIR)/keyboard.h
sys_darwin.$O: $(SRC_DIR)/keycodes.h
sys_darwin.$O: $(SRC_DIR)/system.h
sys_darwin.$O: $(SRC_DIR)/sys_prog_none.h
sys_darwin.$O: $(SRC_DIR)/sys_boot_none.h
sys_darwin.$O: $(SRC_DIR)/sys_exec_unix.h
sys_darwin.$O: $(SRC_DIR)/sys_mount_none.h
sys_darwin.$O: $(SRC_DIR)/sys_shlib_dyld.h
sys_darwin.$O: $(SRC_DIR)/sys_beep_none.h
sys_darwin.$O: $(SRC_DIR)/sys_pcm_none.h
sys_darwin.$O: $(SRC_DIR)/sys_midi_darwin.h
sys_darwin.$O: $(SRC_DIR)/sys_ports_none.h
sys_darwin.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_freebsd.$O:
sys_freebsd.$O: $(SRC_DIR)/sys_freebsd.c
sys_freebsd.$O: $(BLD_TOP)config.h
sys_freebsd.$O: $(SRC_TOP)prologue.h
sys_freebsd.$O: $(SRC_DIR)/misc.h
sys_freebsd.$O: $(SRC_DIR)/bitmask.h
sys_freebsd.$O: $(SRC_DIR)/keyboard.h
sys_freebsd.$O: $(SRC_DIR)/keycodes.h
sys_freebsd.$O: $(SRC_DIR)/system.h
sys_freebsd.$O: $(SRC_DIR)/sys_prog_none.h
sys_freebsd.$O: $(SRC_DIR)/sys_boot_none.h
sys_freebsd.$O: $(SRC_DIR)/sys_exec_unix.h
sys_freebsd.$O: $(SRC_DIR)/sys_mount_none.h
sys_freebsd.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_freebsd.$O: $(SRC_DIR)/sys_beep_spkr.h
sys_freebsd.$O: $(SRC_DIR)/io_misc.h
sys_freebsd.$O: $(SRC_DIR)/sys_pcm_oss.h
sys_freebsd.$O: $(SRC_DIR)/sys_midi_none.h
sys_freebsd.$O: $(SRC_DIR)/sys_ports_none.h
sys_freebsd.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_hpux.$O:
sys_hpux.$O: $(SRC_DIR)/sys_hpux.c
sys_hpux.$O: $(BLD_TOP)config.h
sys_hpux.$O: $(SRC_TOP)prologue.h
sys_hpux.$O: $(SRC_DIR)/misc.h
sys_hpux.$O: $(SRC_DIR)/bitmask.h
sys_hpux.$O: $(SRC_DIR)/keyboard.h
sys_hpux.$O: $(SRC_DIR)/keycodes.h
sys_hpux.$O: $(SRC_DIR)/system.h
sys_hpux.$O: $(SRC_DIR)/sys_prog_none.h
sys_hpux.$O: $(SRC_DIR)/sys_boot_none.h
sys_hpux.$O: $(SRC_DIR)/sys_exec_unix.h
sys_hpux.$O: $(SRC_DIR)/sys_mount_none.h
sys_hpux.$O: $(SRC_DIR)/sys_beep_none.h
sys_hpux.$O: $(SRC_DIR)/sys_midi_none.h
sys_hpux.$O: $(SRC_DIR)/sys_ports_none.h
sys_hpux.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_hurd.$O:
sys_hurd.$O: $(SRC_DIR)/sys_hurd.c
sys_hurd.$O: $(BLD_TOP)config.h
sys_hurd.$O: $(SRC_TOP)prologue.h
sys_hurd.$O: $(SRC_DIR)/misc.h
sys_hurd.$O: $(SRC_DIR)/bitmask.h
sys_hurd.$O: $(SRC_DIR)/keyboard.h
sys_hurd.$O: $(SRC_DIR)/keycodes.h
sys_hurd.$O: $(SRC_DIR)/system.h
sys_hurd.$O: $(SRC_DIR)/sys_prog_none.h
sys_hurd.$O: $(SRC_DIR)/sys_boot_none.h
sys_hurd.$O: $(SRC_DIR)/sys_exec_unix.h
sys_hurd.$O: $(SRC_DIR)/sys_mount_none.h
sys_hurd.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_hurd.$O: $(SRC_DIR)/sys_beep_none.h
sys_hurd.$O: $(SRC_DIR)/sys_pcm_none.h
sys_hurd.$O: $(SRC_DIR)/sys_midi_none.h
sys_hurd.$O: $(SRC_DIR)/sys_ports_glibc.h
sys_hurd.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_kfreebsd.$O:
sys_kfreebsd.$O: $(SRC_DIR)/sys_kfreebsd.c
sys_kfreebsd.$O: $(BLD_TOP)config.h
sys_kfreebsd.$O: $(SRC_TOP)prologue.h
sys_kfreebsd.$O: $(SRC_DIR)/misc.h
sys_kfreebsd.$O: $(SRC_DIR)/bitmask.h
sys_kfreebsd.$O: $(SRC_DIR)/keyboard.h
sys_kfreebsd.$O: $(SRC_DIR)/keycodes.h
sys_kfreebsd.$O: $(SRC_DIR)/system.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_prog_none.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_boot_none.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_exec_unix.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_mount_none.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_beep_spkr.h
sys_kfreebsd.$O: $(SRC_DIR)/io_misc.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_pcm_oss.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_midi_none.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_ports_kfreebsd.h
sys_kfreebsd.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_linux.$O:
sys_linux.$O: $(SRC_DIR)/sys_linux.c
sys_linux.$O: $(BLD_TOP)config.h
sys_linux.$O: $(SRC_TOP)prologue.h
sys_linux.$O: $(SRC_DIR)/misc.h
sys_linux.$O: $(SRC_DIR)/bitmask.h
sys_linux.$O: $(SRC_DIR)/keyboard.h
sys_linux.$O: $(SRC_DIR)/keycodes.h
sys_linux.$O: $(SRC_DIR)/system.h
sys_linux.$O: $(SRC_DIR)/sys_linux.h
sys_linux.$O: $(SRC_DIR)/sys_exec_unix.h
sys_linux.$O: $(SRC_DIR)/sys_mount_linux.h
sys_linux.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_linux.$O: $(SRC_DIR)/io_misc.h
sys_linux.$O: $(SRC_DIR)/sys_pcm_oss.h
sys_linux.$O: $(SRC_DIR)/sys_pcm_alsa.h
sys_linux.$O: $(SRC_DIR)/sys_pcm_none.h
sys_linux.$O: $(SRC_DIR)/sys_midi_oss.h
sys_linux.$O: $(SRC_DIR)/sys_midi_alsa.h
sys_linux.$O: $(SRC_DIR)/sys_midi_none.h
sys_linux.$O: $(SRC_DIR)/sys_ports_glibc.h
sys_linux.$O: $(SRC_DIR)/async.h
sys_linux.$O: $(SRC_DIR)/sys_kbd_linux.h

# Dependencies for sys_msdos.$O:
sys_msdos.$O: $(SRC_DIR)/sys_msdos.c
sys_msdos.$O: $(BLD_TOP)config.h
sys_msdos.$O: $(SRC_TOP)prologue.h
sys_msdos.$O: $(SRC_DIR)/misc.h
sys_msdos.$O: $(SRC_DIR)/bitmask.h
sys_msdos.$O: $(SRC_DIR)/keyboard.h
sys_msdos.$O: $(SRC_DIR)/keycodes.h
sys_msdos.$O: $(SRC_DIR)/system.h
sys_msdos.$O: $(SRC_DIR)/sys_prog_none.h
sys_msdos.$O: $(SRC_DIR)/sys_boot_none.h
sys_msdos.$O: $(SRC_DIR)/sys_exec_none.h
sys_msdos.$O: $(SRC_DIR)/sys_mount_none.h
sys_msdos.$O: $(SRC_DIR)/sys_shlib_none.h
sys_msdos.$O: $(SRC_DIR)/sys_beep_msdos.h
sys_msdos.$O: $(SRC_DIR)/sys_pcm_none.h
sys_msdos.$O: $(SRC_DIR)/sys_midi_none.h
sys_msdos.$O: $(SRC_DIR)/sys_ports_always.h
sys_msdos.$O: $(SRC_DIR)/sys_ports_x86.h
sys_msdos.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_netbsd.$O:
sys_netbsd.$O: $(SRC_DIR)/sys_netbsd.c
sys_netbsd.$O: $(BLD_TOP)config.h
sys_netbsd.$O: $(SRC_TOP)prologue.h
sys_netbsd.$O: $(SRC_DIR)/misc.h
sys_netbsd.$O: $(SRC_DIR)/bitmask.h
sys_netbsd.$O: $(SRC_DIR)/keyboard.h
sys_netbsd.$O: $(SRC_DIR)/keycodes.h
sys_netbsd.$O: $(SRC_DIR)/system.h
sys_netbsd.$O: $(SRC_DIR)/sys_prog_none.h
sys_netbsd.$O: $(SRC_DIR)/sys_boot_none.h
sys_netbsd.$O: $(SRC_DIR)/sys_exec_unix.h
sys_netbsd.$O: $(SRC_DIR)/sys_mount_none.h
sys_netbsd.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_netbsd.$O: $(SRC_DIR)/sys_beep_wskbd.h
sys_netbsd.$O: $(SRC_DIR)/io_misc.h
sys_netbsd.$O: $(SRC_DIR)/sys_pcm_audio.h
sys_netbsd.$O: $(SRC_DIR)/sys_midi_none.h
sys_netbsd.$O: $(SRC_DIR)/sys_ports_none.h
sys_netbsd.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_openbsd.$O:
sys_openbsd.$O: $(SRC_DIR)/sys_openbsd.c
sys_openbsd.$O: $(BLD_TOP)config.h
sys_openbsd.$O: $(SRC_TOP)prologue.h
sys_openbsd.$O: $(SRC_DIR)/misc.h
sys_openbsd.$O: $(SRC_DIR)/bitmask.h
sys_openbsd.$O: $(SRC_DIR)/keyboard.h
sys_openbsd.$O: $(SRC_DIR)/keycodes.h
sys_openbsd.$O: $(SRC_DIR)/system.h
sys_openbsd.$O: $(SRC_DIR)/sys_prog_none.h
sys_openbsd.$O: $(SRC_DIR)/sys_boot_none.h
sys_openbsd.$O: $(SRC_DIR)/sys_exec_unix.h
sys_openbsd.$O: $(SRC_DIR)/sys_mount_none.h
sys_openbsd.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_openbsd.$O: $(SRC_DIR)/sys_beep_wskbd.h
sys_openbsd.$O: $(SRC_DIR)/io_misc.h
sys_openbsd.$O: $(SRC_DIR)/sys_pcm_audio.h
sys_openbsd.$O: $(SRC_DIR)/sys_midi_none.h
sys_openbsd.$O: $(SRC_DIR)/sys_ports_none.h
sys_openbsd.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_osf.$O:
sys_osf.$O: $(SRC_DIR)/sys_osf.c
sys_osf.$O: $(BLD_TOP)config.h
sys_osf.$O: $(SRC_TOP)prologue.h
sys_osf.$O: $(SRC_DIR)/misc.h
sys_osf.$O: $(SRC_DIR)/bitmask.h
sys_osf.$O: $(SRC_DIR)/keyboard.h
sys_osf.$O: $(SRC_DIR)/keycodes.h
sys_osf.$O: $(SRC_DIR)/system.h
sys_osf.$O: $(SRC_DIR)/sys_prog_none.h
sys_osf.$O: $(SRC_DIR)/sys_boot_none.h
sys_osf.$O: $(SRC_DIR)/sys_exec_unix.h
sys_osf.$O: $(SRC_DIR)/sys_mount_none.h
sys_osf.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_osf.$O: $(SRC_DIR)/sys_beep_none.h
sys_osf.$O: $(SRC_DIR)/sys_pcm_none.h
sys_osf.$O: $(SRC_DIR)/sys_midi_none.h
sys_osf.$O: $(SRC_DIR)/sys_ports_none.h
sys_osf.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_qnx.$O:
sys_qnx.$O: $(SRC_DIR)/sys_qnx.c
sys_qnx.$O: $(BLD_TOP)config.h
sys_qnx.$O: $(SRC_TOP)prologue.h
sys_qnx.$O: $(SRC_DIR)/misc.h
sys_qnx.$O: $(SRC_DIR)/bitmask.h
sys_qnx.$O: $(SRC_DIR)/keyboard.h
sys_qnx.$O: $(SRC_DIR)/keycodes.h
sys_qnx.$O: $(SRC_DIR)/system.h
sys_qnx.$O: $(SRC_DIR)/sys_prog_none.h
sys_qnx.$O: $(SRC_DIR)/sys_boot_none.h
sys_qnx.$O: $(SRC_DIR)/sys_exec_unix.h
sys_qnx.$O: $(SRC_DIR)/sys_mount_none.h
sys_qnx.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_qnx.$O: $(SRC_DIR)/sys_beep_none.h
sys_qnx.$O: $(SRC_DIR)/io_misc.h
sys_qnx.$O: $(SRC_DIR)/sys_pcm_qsa.h
sys_qnx.$O: $(SRC_DIR)/sys_midi_none.h
sys_qnx.$O: $(SRC_DIR)/sys_ports_none.h
sys_qnx.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_skeleton.$O:
sys_skeleton.$O: $(SRC_DIR)/sys_skeleton.c
sys_skeleton.$O: $(BLD_TOP)config.h
sys_skeleton.$O: $(SRC_TOP)prologue.h
sys_skeleton.$O: $(SRC_DIR)/misc.h
sys_skeleton.$O: $(SRC_DIR)/bitmask.h
sys_skeleton.$O: $(SRC_DIR)/keyboard.h
sys_skeleton.$O: $(SRC_DIR)/keycodes.h
sys_skeleton.$O: $(SRC_DIR)/system.h
sys_skeleton.$O: $(SRC_DIR)/sys_prog_none.h
sys_skeleton.$O: $(SRC_DIR)/sys_boot_none.h
sys_skeleton.$O: $(SRC_DIR)/sys_exec_none.h
sys_skeleton.$O: $(SRC_DIR)/sys_mount_none.h
sys_skeleton.$O: $(SRC_DIR)/sys_shlib_none.h
sys_skeleton.$O: $(SRC_DIR)/sys_beep_none.h
sys_skeleton.$O: $(SRC_DIR)/sys_pcm_none.h
sys_skeleton.$O: $(SRC_DIR)/sys_midi_none.h
sys_skeleton.$O: $(SRC_DIR)/sys_ports_none.h
sys_skeleton.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_solaris.$O:
sys_solaris.$O: $(SRC_DIR)/sys_solaris.c
sys_solaris.$O: $(BLD_TOP)config.h
sys_solaris.$O: $(SRC_TOP)prologue.h
sys_solaris.$O: $(SRC_DIR)/misc.h
sys_solaris.$O: $(SRC_DIR)/bitmask.h
sys_solaris.$O: $(SRC_DIR)/keyboard.h
sys_solaris.$O: $(SRC_DIR)/keycodes.h
sys_solaris.$O: $(SRC_DIR)/system.h
sys_solaris.$O: $(SRC_DIR)/sys_boot_none.h
sys_solaris.$O: $(SRC_DIR)/sys_exec_unix.h
sys_solaris.$O: $(SRC_DIR)/sys_mount_none.h
sys_solaris.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_solaris.$O: $(SRC_DIR)/sys_beep_none.h
sys_solaris.$O: $(SRC_DIR)/io_misc.h
sys_solaris.$O: $(SRC_DIR)/sys_pcm_audio.h
sys_solaris.$O: $(SRC_DIR)/sys_midi_none.h
sys_solaris.$O: $(SRC_DIR)/sys_ports_none.h
sys_solaris.$O: $(SRC_DIR)/sys_kbd_none.h

# Dependencies for sys_windows.$O:
sys_windows.$O: $(SRC_DIR)/sys_windows.c
sys_windows.$O: $(BLD_TOP)config.h
sys_windows.$O: $(SRC_TOP)prologue.h
sys_windows.$O: $(SRC_DIR)/misc.h
sys_windows.$O: $(SRC_DIR)/bitmask.h
sys_windows.$O: $(SRC_DIR)/keyboard.h
sys_windows.$O: $(SRC_DIR)/keycodes.h
sys_windows.$O: $(SRC_DIR)/system.h
sys_windows.$O: $(SRC_DIR)/sys_windows.h
sys_windows.$O: $(SRC_DIR)/sys_prog_windows.h
sys_windows.$O: $(SRC_DIR)/sys_boot_none.h
sys_windows.$O: $(SRC_DIR)/sys_mount_none.h
sys_windows.$O: $(SRC_DIR)/sys_beep_none.h
sys_windows.$O: $(SRC_DIR)/sys_beep_windows.h
sys_windows.$O: $(SRC_DIR)/sys_ports_windows.h
sys_windows.$O: $(SRC_DIR)/sys_ports_x86.h
sys_windows.$O: $(SRC_DIR)/sys_kbd_none.h
sys_windows.$O: $(SRC_DIR)/sys_exec_unix.h
sys_windows.$O: $(SRC_DIR)/sys_shlib_dlfcn.h
sys_windows.$O: $(SRC_DIR)/io_misc.h
sys_windows.$O: $(SRC_DIR)/sys_pcm_oss.h
sys_windows.$O: $(SRC_DIR)/sys_midi_oss.h
sys_windows.$O: $(SRC_DIR)/sys_exec_windows.h
sys_windows.$O: $(SRC_DIR)/sys_shlib_windows.h
sys_windows.$O: $(SRC_DIR)/sys_pcm_windows.h
sys_windows.$O: $(SRC_DIR)/sys_midi_windows.h

# Dependencies for tbl2hex.$O:
tbl2hex.$O: $(SRC_DIR)/tbl2hex.c
tbl2hex.$O: $(BLD_TOP)config.h
tbl2hex.$O: $(SRC_TOP)prologue.h
tbl2hex.$O: $(SRC_DIR)/options.h
tbl2hex.$O: $(SRC_DIR)/misc.h
tbl2hex.$O: $(SRC_DIR)/ttb.h
tbl2hex.$O: $(SRC_DIR)/bitmask.h
tbl2hex.$O: $(SRC_DIR)/ttb_internal.h
tbl2hex.$O: $(SRC_DIR)/unicode.h
tbl2hex.$O: $(SRC_DIR)/atb.h
tbl2hex.$O: $(SRC_DIR)/atb_internal.h
tbl2hex.$O: $(SRC_DIR)/ctb.h
tbl2hex.$O: $(SRC_DIR)/ctb_internal.h

# Dependencies for touch.$O:
touch.$O: $(SRC_DIR)/touch.c
touch.$O: $(BLD_TOP)config.h
touch.$O: $(SRC_TOP)prologue.h
touch.$O: $(SRC_DIR)/misc.h
touch.$O: $(SRC_DIR)/brl.h
touch.$O: $(SRC_DIR)/brldefs.h
touch.$O: $(SRC_DIR)/driver.h
touch.$O: $(SRC_DIR)/touch.h
touch.$O: $(SRC_DIR)/bitmask.h
touch.$O: brlapi_constants.h
touch.$O: $(SRC_DIR)/brlapi_keycodes.h
touch.$O: $(SRC_DIR)/brltty.h
touch.$O: $(SRC_DIR)/cmd.h
touch.$O: $(SRC_DIR)/ctb.h
touch.$O: $(SRC_DIR)/keycodes.h
touch.$O: $(SRC_DIR)/ktb.h
touch.$O: $(SRC_DIR)/spk.h

# Dependencies for ttb_compile.$O:
ttb_compile.$O: $(SRC_DIR)/ttb_compile.c
ttb_compile.$O: $(BLD_TOP)config.h
ttb_compile.$O: $(SRC_TOP)prologue.h
ttb_compile.$O: $(SRC_DIR)/misc.h
ttb_compile.$O: $(SRC_DIR)/datafile.h
ttb_compile.$O: $(SRC_DIR)/dataarea.h
ttb_compile.$O: $(SRC_DIR)/charset.h
ttb_compile.$O: $(SRC_DIR)/lock.h
ttb_compile.$O: $(SRC_DIR)/ttb.h
ttb_compile.$O: $(SRC_DIR)/bitmask.h
ttb_compile.$O: $(SRC_DIR)/ttb_internal.h
ttb_compile.$O: $(SRC_DIR)/unicode.h
ttb_compile.$O: $(SRC_DIR)/ttb_compile.h

# Dependencies for ttb_gnome.$O:
ttb_gnome.$O: $(SRC_DIR)/ttb_gnome.c
ttb_gnome.$O: $(BLD_TOP)config.h
ttb_gnome.$O: $(SRC_TOP)prologue.h
ttb_gnome.$O: $(SRC_DIR)/ttb.h
ttb_gnome.$O: $(SRC_DIR)/bitmask.h
ttb_gnome.$O: $(SRC_DIR)/ttb_internal.h
ttb_gnome.$O: $(SRC_DIR)/unicode.h
ttb_gnome.$O: $(SRC_DIR)/datafile.h
ttb_gnome.$O: $(SRC_DIR)/ttb_compile.h

# Dependencies for ttb_louis.$O:
ttb_louis.$O: $(SRC_DIR)/ttb_louis.c
ttb_louis.$O: $(BLD_TOP)config.h
ttb_louis.$O: $(SRC_TOP)prologue.h
ttb_louis.$O: $(SRC_DIR)/ttb.h
ttb_louis.$O: $(SRC_DIR)/bitmask.h
ttb_louis.$O: $(SRC_DIR)/ttb_internal.h
ttb_louis.$O: $(SRC_DIR)/unicode.h
ttb_louis.$O: $(SRC_DIR)/datafile.h
ttb_louis.$O: $(SRC_DIR)/ttb_compile.h

# Dependencies for ttb_native.$O:
ttb_native.$O: $(SRC_DIR)/ttb_native.c
ttb_native.$O: $(BLD_TOP)config.h
ttb_native.$O: $(SRC_TOP)prologue.h
ttb_native.$O: $(SRC_DIR)/misc.h
ttb_native.$O: $(SRC_DIR)/ttb.h
ttb_native.$O: $(SRC_DIR)/bitmask.h
ttb_native.$O: $(SRC_DIR)/ttb_internal.h
ttb_native.$O: $(SRC_DIR)/unicode.h
ttb_native.$O: $(SRC_DIR)/datafile.h
ttb_native.$O: $(SRC_DIR)/ttb_compile.h

# Dependencies for ttb_translate.$O:
ttb_translate.$O: $(SRC_DIR)/ttb_translate.c
ttb_translate.$O: $(BLD_TOP)config.h
ttb_translate.$O: $(SRC_TOP)prologue.h
ttb_translate.$O: $(SRC_DIR)/charset.h
ttb_translate.$O: $(SRC_DIR)/lock.h
ttb_translate.$O: $(SRC_DIR)/ttb.h
ttb_translate.$O: $(SRC_DIR)/bitmask.h
ttb_translate.$O: $(SRC_DIR)/ttb_internal.h
ttb_translate.$O: $(SRC_DIR)/unicode.h
ttb_translate.$O: $(SRC_DIR)/brldots.h
ttb_translate.$O: text.auto.h

# Dependencies for ttbtest.$O:
ttbtest.$O: $(SRC_DIR)/ttbtest.c
ttbtest.$O: $(BLD_TOP)config.h
ttbtest.$O: $(SRC_TOP)prologue.h
ttbtest.$O: $(SRC_DIR)/program.h
ttbtest.$O: $(SRC_DIR)/options.h
ttbtest.$O: $(SRC_DIR)/misc.h
ttbtest.$O: $(SRC_DIR)/brldots.h
ttbtest.$O: $(SRC_DIR)/charset.h
ttbtest.$O: $(SRC_DIR)/lock.h
ttbtest.$O: $(SRC_DIR)/ttb.h
ttbtest.$O: $(SRC_DIR)/bitmask.h
ttbtest.$O: $(SRC_DIR)/ttb_internal.h
ttbtest.$O: $(SRC_DIR)/unicode.h
ttbtest.$O: $(SRC_DIR)/datafile.h
ttbtest.$O: $(SRC_DIR)/ttb_compile.h
ttbtest.$O: brlapi.h
ttbtest.$O: brlapi_constants.h
ttbtest.$O: $(SRC_DIR)/brlapi_keycodes.h

# Dependencies for tunes.$O:
tunes.$O: $(SRC_DIR)/tunes.c
tunes.$O: $(BLD_TOP)config.h
tunes.$O: $(SRC_TOP)prologue.h
tunes.$O: $(SRC_DIR)/misc.h
tunes.$O: $(SRC_DIR)/bitmask.h
tunes.$O: $(SRC_DIR)/keyboard.h
tunes.$O: $(SRC_DIR)/keycodes.h
tunes.$O: $(SRC_DIR)/system.h
tunes.$O: $(SRC_DIR)/message.h
tunes.$O: $(SRC_DIR)/brl.h
tunes.$O: $(SRC_DIR)/brldefs.h
tunes.$O: $(SRC_DIR)/driver.h
tunes.$O: brlapi_constants.h
tunes.$O: $(SRC_DIR)/brlapi_keycodes.h
tunes.$O: $(SRC_DIR)/brltty.h
tunes.$O: $(SRC_DIR)/cmd.h
tunes.$O: $(SRC_DIR)/ctb.h
tunes.$O: $(SRC_DIR)/ktb.h
tunes.$O: $(SRC_DIR)/spk.h
tunes.$O: $(SRC_DIR)/tunes.h
tunes.$O: $(SRC_DIR)/notes.h

# Dependencies for tunetest.$O:
tunetest.$O: $(SRC_DIR)/tunetest.c
tunetest.$O: $(BLD_TOP)config.h
tunetest.$O: $(SRC_TOP)prologue.h
tunetest.$O: $(SRC_DIR)/options.h
tunetest.$O: $(SRC_DIR)/tunes.h
tunetest.$O: $(SRC_DIR)/misc.h
tunetest.$O: $(SRC_DIR)/defaults.h
tunetest.$O: $(SRC_DIR)/bitmask.h
tunetest.$O: $(SRC_DIR)/brl.h
tunetest.$O: brlapi_constants.h
tunetest.$O: $(SRC_DIR)/brlapi_keycodes.h
tunetest.$O: $(SRC_DIR)/brldefs.h
tunetest.$O: $(SRC_DIR)/brltty.h
tunetest.$O: $(SRC_DIR)/cmd.h
tunetest.$O: $(SRC_DIR)/ctb.h
tunetest.$O: $(SRC_DIR)/driver.h
tunetest.$O: $(SRC_DIR)/keycodes.h
tunetest.$O: $(SRC_DIR)/ktb.h
tunetest.$O: $(SRC_DIR)/spk.h
tunetest.$O: $(SRC_DIR)/message.h

# Dependencies for txt2hlp.$O:
txt2hlp.$O: $(SRC_DIR)/txt2hlp.c
txt2hlp.$O: $(BLD_TOP)config.h
txt2hlp.$O: $(SRC_TOP)prologue.h
txt2hlp.$O: $(SRC_DIR)/options.h
txt2hlp.$O: $(SRC_DIR)/misc.h
txt2hlp.$O: $(SRC_DIR)/help.h

# Dependencies for usb.$O:
usb.$O: $(SRC_DIR)/usb.c
usb.$O: $(BLD_TOP)config.h
usb.$O: $(SRC_TOP)prologue.h
usb.$O: $(SRC_DIR)/misc.h
usb.$O: $(SRC_DIR)/io_defs.h
usb.$O: $(SRC_DIR)/io_usb.h
usb.$O: $(SRC_DIR)/queue.h
usb.$O: $(SRC_DIR)/usb_internal.h

# Dependencies for usb_darwin.$O:
usb_darwin.$O: $(SRC_DIR)/usb_darwin.c
usb_darwin.$O: $(BLD_TOP)config.h
usb_darwin.$O: $(SRC_TOP)prologue.h
usb_darwin.$O: $(SRC_DIR)/misc.h
usb_darwin.$O: $(SRC_DIR)/io_defs.h
usb_darwin.$O: $(SRC_DIR)/io_usb.h
usb_darwin.$O: $(SRC_DIR)/queue.h
usb_darwin.$O: $(SRC_DIR)/usb_internal.h

# Dependencies for usb_freebsd.$O:
usb_freebsd.$O: $(SRC_DIR)/usb_freebsd.c
usb_freebsd.$O: $(BLD_TOP)config.h
usb_freebsd.$O: $(SRC_TOP)prologue.h
usb_freebsd.$O: $(SRC_DIR)/misc.h
usb_freebsd.$O: $(SRC_DIR)/io_defs.h
usb_freebsd.$O: $(SRC_DIR)/io_usb.h
usb_freebsd.$O: $(SRC_DIR)/queue.h
usb_freebsd.$O: $(SRC_DIR)/usb_internal.h
usb_freebsd.$O: $(SRC_DIR)/usb_bsd.h

# Dependencies for usb_kfreebsd.$O:
usb_kfreebsd.$O: $(SRC_DIR)/usb_kfreebsd.c
usb_kfreebsd.$O: $(BLD_TOP)config.h
usb_kfreebsd.$O: $(SRC_TOP)prologue.h
usb_kfreebsd.$O: $(SRC_DIR)/misc.h
usb_kfreebsd.$O: $(SRC_DIR)/io_defs.h
usb_kfreebsd.$O: $(SRC_DIR)/io_usb.h
usb_kfreebsd.$O: $(SRC_DIR)/queue.h
usb_kfreebsd.$O: $(SRC_DIR)/usb_internal.h
usb_kfreebsd.$O: $(SRC_DIR)/usb_bsd.h

# Dependencies for usb_libusb.$O:
usb_libusb.$O: $(SRC_DIR)/usb_libusb.c
usb_libusb.$O: $(BLD_TOP)config.h
usb_libusb.$O: $(SRC_TOP)prologue.h
usb_libusb.$O: $(SRC_DIR)/misc.h
usb_libusb.$O: $(SRC_DIR)/io_defs.h
usb_libusb.$O: $(SRC_DIR)/io_usb.h
usb_libusb.$O: $(SRC_DIR)/queue.h
usb_libusb.$O: $(SRC_DIR)/usb_internal.h

# Dependencies for usb_linux.$O:
usb_linux.$O: $(SRC_DIR)/usb_linux.c
usb_linux.$O: $(BLD_TOP)config.h
usb_linux.$O: $(SRC_TOP)prologue.h
usb_linux.$O: $(SRC_DIR)/misc.h
usb_linux.$O: $(SRC_DIR)/mount.h
usb_linux.$O: $(SRC_DIR)/io_defs.h
usb_linux.$O: $(SRC_DIR)/io_usb.h
usb_linux.$O: $(SRC_DIR)/queue.h
usb_linux.$O: $(SRC_DIR)/usb_internal.h

# Dependencies for usb_netbsd.$O:
usb_netbsd.$O: $(SRC_DIR)/usb_netbsd.c
usb_netbsd.$O: $(BLD_TOP)config.h
usb_netbsd.$O: $(SRC_TOP)prologue.h
usb_netbsd.$O: $(SRC_DIR)/misc.h
usb_netbsd.$O: $(SRC_DIR)/io_defs.h
usb_netbsd.$O: $(SRC_DIR)/io_usb.h
usb_netbsd.$O: $(SRC_DIR)/queue.h
usb_netbsd.$O: $(SRC_DIR)/usb_internal.h
usb_netbsd.$O: $(SRC_DIR)/usb_bsd.h

# Dependencies for usb_openbsd.$O:
usb_openbsd.$O: $(SRC_DIR)/usb_openbsd.c
usb_openbsd.$O: $(BLD_TOP)config.h
usb_openbsd.$O: $(SRC_TOP)prologue.h
usb_openbsd.$O: $(SRC_DIR)/misc.h
usb_openbsd.$O: $(SRC_DIR)/io_defs.h
usb_openbsd.$O: $(SRC_DIR)/io_usb.h
usb_openbsd.$O: $(SRC_DIR)/queue.h
usb_openbsd.$O: $(SRC_DIR)/usb_internal.h
usb_openbsd.$O: $(SRC_DIR)/usb_bsd.h

# Dependencies for usb_skeleton.$O:
usb_skeleton.$O: $(SRC_DIR)/usb_skeleton.c
usb_skeleton.$O: $(BLD_TOP)config.h
usb_skeleton.$O: $(SRC_TOP)prologue.h
usb_skeleton.$O: $(SRC_DIR)/misc.h
usb_skeleton.$O: $(SRC_DIR)/io_defs.h
usb_skeleton.$O: $(SRC_DIR)/io_usb.h
usb_skeleton.$O: $(SRC_DIR)/queue.h
usb_skeleton.$O: $(SRC_DIR)/usb_internal.h

# Dependencies for usb_solaris.$O:
usb_solaris.$O: $(SRC_DIR)/usb_solaris.c
usb_solaris.$O: $(BLD_TOP)config.h
usb_solaris.$O: $(SRC_TOP)prologue.h
usb_solaris.$O: $(SRC_DIR)/misc.h
usb_solaris.$O: $(SRC_DIR)/io_defs.h
usb_solaris.$O: $(SRC_DIR)/io_usb.h
usb_solaris.$O: $(SRC_DIR)/queue.h
usb_solaris.$O: $(SRC_DIR)/usb_internal.h

# Dependencies for xbrlapi.$O:
xbrlapi.$O: $(SRC_DIR)/xbrlapi.c
xbrlapi.$O: $(BLD_TOP)config.h
xbrlapi.$O: $(SRC_TOP)prologue.h
xbrlapi.$O: brlapi.h
xbrlapi.$O: brlapi_constants.h
xbrlapi.$O: $(SRC_DIR)/brlapi_keycodes.h
xbrlapi.$O: $(SRC_DIR)/misc.h
xbrlapi.$O: $(SRC_DIR)/options.h


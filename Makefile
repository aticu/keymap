.PHONY: all
all: ../../../../ergodox_ez_aticu.hex

../../../../ergodox_ez_aticu.hex: config.h keymap.c rules.mk
	cd -P ../../../.. && make ergodox_ez:aticu

.PHONY: flash
flash: ../../../../ergodox_ez_aticu.hex
	teensy-loader-cli -mmcu=atmega32u4 -v -w $<

.PHONY: clean
clean:
	cd -P ../../../.. && make clean
	rm ../../../../ergodox_ez_aticu.hex

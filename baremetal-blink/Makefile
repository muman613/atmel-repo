# Makefile for baremetal programming of Arduino Mega2560 (Atmel2560)

PORT=/dev/ttyACM0
# DEFINES=-DATMEL2560
ifeq ($(TARGET), ATMEL328)
	DEFINES=-DATMEL328
	MCU=atmega328p
	PROGRAMMER=arduino
endif
ifeq ($(TARGET), ATMEL2560)
	DEFINES=-DATMEL2560
	MCU=atmega2560
	PROGRAMMER=arduino
endif

baremetal.hex : baremetal.elf
	avr-objcopy -O ihex -R .eeprom baremetal.elf baremetal.hex

baremetal.elf: baremetal.o 
	avr-gcc -mmcu=${MCU} baremetal.o -o baremetal.elf

baremetal.o: baremetal.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=${MCU} ${DEFINES} -c -o baremetal.o baremetal.c

clean:
	rm -f *.o baremetal.hex baremetal.elf

flash: baremetal.hex
	avrdude  -v -p${MCU} -c${PROGRAMMER} -P${PORT} -b115200 -D -Uflash:w:baremetal.hex:i

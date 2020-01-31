# Makefile for baremetal programming of Arduino Mega2560 (Atmel2560)

PORT ?= /dev/ttyACM0
TARGET ?= ATMEGA382
F_CPU ?= 16000000

# DEFINES=-DATMEL2560
ifeq ($(TARGET), ATMEGA382)
	MCU=atmega328p
	PROGRAMMER=arduino
endif
ifeq ($(TARGET), ATMEGA2560)
	MCU=atmega2560
	PROGRAMMER=arduino
endif

PROJECT = baremetal

${PROJECT}.hex : ${PROJECT}.elf
	avr-objcopy -O ihex -R .eeprom ${PROJECT}.elf ${PROJECT}.hex

${PROJECT}.elf: baremetal.o
	avr-gcc -mmcu=${MCU} baremetal.o -o ${PROJECT}.elf

baremetal.o: src/baremetal.c
	avr-gcc -Os -DF_CPU=${F_CPU} -mmcu=${MCU} ${DEFINES} -c -o baremetal.o src/baremetal.c

clean:
	rm -f *.o baremetal.hex baremetal.elf

flash: baremetal.hex
	avrdude  -v -p${MCU} -c${PROGRAMMER} -P${PORT} -b115200 -D -Uflash:w:baremetal.hex:i

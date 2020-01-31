# Makefile for baremetal programming of Arduino Mega2560 (Atmel2560)

PROJECT = baremetal-uart
TARGET ?= ATMEGA328
PORT ?= /dev/ttyS10
F_CPU ?= 16000000

ifeq ($(TARGET), ATMEGA328)
	MCU=atmega328p
	PROGRAMMER=arduino
endif
ifeq ($(TARGET), ATMEGA2560)
	MCU=atmega2560
	PROGRAMMER=arduino
endif

SRCS = baremetal.c uart.c
OBJS = ${SRCS:%.c=%.o}

${PROJECT}.hex : ${PROJECT}.elf
	avr-objcopy -O ihex -R .eeprom ${PROJECT}.elf ${PROJECT}.hex

${PROJECT}.elf: ${OBJS}
	avr-gcc -mmcu=${MCU} baremetal.o uart.o -o ${PROJECT}.elf

%.o : src/%.c
	avr-gcc -Os -DF_CPU=${F_CPU} -mmcu=${MCU} ${DEFINES} $< -c

clean:
	rm -f *.o ${PROJECT}.hex ${PROJECT}.elf

flash: ${PROJECT}.hex
	avrdude -v -p${MCU} -c${PROGRAMMER} -P${PORT} -b115200 -e -Uflash:w:${PROJECT}.hex:i

erase:
	avrdude -v -p${MCU} -c${PROGRAMMER} -P${PORT} -b115200 -e

.phony: erase

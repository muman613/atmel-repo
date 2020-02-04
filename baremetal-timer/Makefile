# Makefile for baremetal programming of Arduino Mega2560 (Atmel2560)

PORT ?= /dev/ttyACM0
TARGET ?= ATMEGA328
F_CPU ?= 16000000

# DEFINES=-DATMEL2560
ifeq ($(TARGET), ATMEGA328)
	MCU=atmega328p
	PROGRAMMER=arduino
endif
ifeq ($(TARGET), ATMEGA2560)
	MCU=atmega2560
	PROGRAMMER=wiring
endif

PROJECT = baremetal-timer
SRCS = 	baremetal.c 		\
		../common/gpio.c    \
		../common/uart.c	\
		../common/timer.c

OBJS = ${SRCS:%.c=%.o}
CFLAGS = -I ../common/

${PROJECT}.hex : ${PROJECT}.elf
	avr-objcopy -O ihex -R .eeprom ${PROJECT}.elf ${PROJECT}.hex

${PROJECT}.elf: ${OBJS}
	avr-gcc -mmcu=${MCU} ${OBJS} -o ${PROJECT}.elf

%.o : src/%.c
	avr-gcc -Os -DF_CPU=${F_CPU} -mmcu=${MCU} ${DEFINES} ${CFLAGS} -c $< -o $@

../common/%.o : ../common/%.c
	avr-gcc -Os -DF_CPU=${F_CPU} -mmcu=${MCU} ${DEFINES} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${PROJECT}.hex ${PROJECT}.elf

flash: ${PROJECT}.hex
	avrdude  -v -p${MCU} -c${PROGRAMMER} -P${PORT} -b115200 -D -Uflash:w:${PROJECT}.hex:i

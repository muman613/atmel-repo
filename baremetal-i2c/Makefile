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

PROJECT = baremetal-i2c
SRCS = baremetal.c twi.c gpio.c
OBJS = ${SRCS:%.c=%.o}

${PROJECT}.hex : ${PROJECT}.elf
	avr-objcopy -O ihex -R .eeprom ${PROJECT}.elf ${PROJECT}.hex

${PROJECT}.elf: ${OBJS}
	avr-gcc -mmcu=${MCU} ${OBJS} -o ${PROJECT}.elf

%.o : src/%.c
	avr-gcc -Os -DF_CPU=${F_CPU} -mmcu=${MCU} ${DEFINES} -c $<

clean:
	rm -f *.o baremetal.hex baremetal.elf

flash: ${PROJECT}.hex
	avrdude  -v -p${MCU} -c${PROGRAMMER} -P${PORT} -b115200 -D -Uflash:w:${PROJECT}.hex:i

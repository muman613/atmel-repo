# Makefile for baremetal programming of Arduino Mega2560 (Atmel2560)

# DEFINES=-DATMEL2560
DEFINES=-DATMEL328
MCU=atmega328

baremetal.hex : baremetal
	avr-objcopy -O ihex -R .eeprom baremetal baremetal.hex

baremetal: baremetal.o 
	avr-gcc -mmcu=${MCU} baremetal.o -o baremetal

baremetal.o: baremetal.c
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=${MCU} ${DEFINES} -c -o baremetal.o baremetal.c

clean:
	rm -f *.o *.hex baremetal

flash: baremetal.hex
	avrdude  -v -patmega2560 -cwiring -P/dev/ttyACM0 -b115200 -D -Uflash:w:baremetal.hex:i

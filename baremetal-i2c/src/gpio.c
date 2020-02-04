#include <avr/io.h>

#include "gpio.h"
#include "pins.h"

typedef struct portInfo {
    volatile uint8_t *        port;
    volatile uint8_t *        ddr;
} PORTINFO;

typedef struct pinInfo {
    PORTINFO *  portInfo;
    int         bit;
} PININFO;

#if defined(__AVR_ATmega328P__)
PORTINFO portB = {
    &PORTB,
    &DDRB
};

PORTINFO portC = {
    &PORTC,
    &DDRC
};

PORTINFO portD = {
    &PORTC,
    &DDRC
};

PININFO pinTable[] = {
    { &portD, 0 },              // Pin 0
    { &portD, 1 },              // Pin 1
    { &portD, 2 },              // Pin 2
    { &portD, 3 },              // Pin 3
    { &portD, 4 },              // Pin 4
    { &portD, 5 },              // Pin 5
    { &portD, 6 },              // Pin 6
    { &portD, 7 },              // Pin 7
    { &portB, 0 },              // Pin 8
    { &portB, 1 },              // Pin 9
    { &portB, 2 },              // Pin 10
    { &portB, 3 },              // Pin 11
    { &portB, 4 },              // Pin 12
    { &portB, 5 },              // Pin 13
};

#endif

void pinMode(int pin, int mode) {
    // DDRB |= _BV(DDB5);
    if (mode == MODE_INPUT) {
        *(pinTable[pin].portInfo->ddr) &= ~(1 << pinTable[pin].bit);
    } else if (mode == MODE_OUTPUT) {
        *(pinTable[pin].portInfo->ddr) |= (1 << pinTable[pin].bit);

    }
}

void digitalWrite(int pin, int value) {
    if (value == VALUE_HIGH) {
        *(pinTable[pin].portInfo->port) |= (1 << pinTable[pin].bit);
    } else if (value == VALUE_LOW) {
        *(pinTable[pin].portInfo->port) &= ~(1 << pinTable[pin].bit);
    }
    return;
}
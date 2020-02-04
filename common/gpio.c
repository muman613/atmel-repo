#include <avr/io.h>
#include <avr/interrupt.h>

#include "gpio.h"
#include "pins.h"

#if defined(__AVR_ATmega328P__)
static PORTINFO portB = {
    &PORTB,
    &DDRB,
    &PINB
};

static PORTINFO portC = {
    &PORTC,
    &DDRC,
    &PINC
};

static PORTINFO portD = {
    &PORTC,
    &DDRC,
    &PINC
};

static PININFO pinTable[] = {
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

/**
 * Set the Pin mode.
 *
 * pin - Pin # to set mode
 * mode - MODE_INPUT/MODE_INPUT_PULLUP/MODE_OUTPUT
 */
void pinMode(int pin, int mode) {
    switch (mode) {
        case MODE_INPUT:
            *(pinTable[pin].portInfo->ddr)  &= ~(1 << pinTable[pin].bit);
            *(pinTable[pin].portInfo->port) &= ~(1 << pinTable[pin].bit);
            break;
        case MODE_INPUT_PULLUP:
            *(pinTable[pin].portInfo->ddr)  &= ~(1 << pinTable[pin].bit);
            *(pinTable[pin].portInfo->port) |= ~(1 << pinTable[pin].bit);
            break;
        case MODE_OUTPUT:
            *(pinTable[pin].portInfo->ddr) |= (1 << pinTable[pin].bit);
            break;
        default:
            break;
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

void togglePin(int pin) {
    uint8_t sreg = SREG;
    cli();
    *(pinTable[pin].portInfo->port) ^= (1 << pinTable[pin].bit);
    SREG = sreg;
}

int digitalRead(int pin) {

}

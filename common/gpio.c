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
    { &portC, 0 },              // Pin 14
    { &portC, 1 },              // Pin 15
    { &portC, 2 },              // Pin 16
    { &portC, 3 },              // Pin 17
    { &portC, 4 },              // Pin 18
    { &portC, 5 },              // Pin 19
};
#elif defined(__AVR_ATmega2560__)
static PORTINFO portA = {
    &PORTA,
    &DDRA,
    &PINA
};

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

static PORTINFO portE = {
    &PORTE,
    &DDRE,
    &PINE
};

static PORTINFO portF = {
    &PORTF,
    &DDRF,
    &PINF
};

static PORTINFO portG = {
    &PORTG,
    &DDRG,
    &PING
};

static PORTINFO portH = {
    &PORTH,
    &DDRH,
    &PINH
};

// No PortI

static PORTINFO portJ = {
    &PORTJ,
    &DDRJ,
    &PINJ
};

static PORTINFO portK = {
    &PORTK,
    &DDRK,
    &PINK
};

static PORTINFO portL = {
    &PORTL,
    &DDRL,
    &PINL
};

static PININFO pinTable[] = {
    { &portE, 0 },              // Pin 0
    { &portE, 1 },              // Pin 1
    { &portE, 4 },              // Pin 2
    { &portE, 5 },              // Pin 3
    { &portG, 5 },              // Pin 4
    { &portE, 3 },              // Pin 5
    { &portH, 3 },              // Pin 6
    { &portH, 4 },              // Pin 7
    { &portH, 5 },              // Pin 8
    { &portH, 6 },              // Pin 9
    { &portB, 4 },              // Pin 10
    { &portB, 5 },              // Pin 11
    { &portB, 6 },              // Pin 12
    { &portB, 7 },              // Pin 13
    { &portJ, 1 },              // Pin 14
    { &portJ, 0 },              // Pin 15
    { &portH, 1 },              // Pin 16
    { &portH, 0 },              // Pin 17
    { &portD, 3 },              // Pin 18
    { &portD, 2 },              // Pin 19
    { &portD, 1 },              // Pin 20 (I2C_SDA)
    { &portD, 0 },              // Pin 21 (I2C_SCL)
    { &portA, 0 },              // Pin 22
    { &portA, 1 },              // Pin 23
    { &portA, 2 },              // Pin 24
    { &portA, 3 },              // Pin 25
    { &portA, 4 },              // Pin 26
    { &portA, 5 },              // Pin 27
    { &portA, 6 },              // Pin 28
    { &portA, 7 },              // Pin 29
    { &portC, 7 },              // Pin 30
    { &portC, 6 },              // Pin 31
    { &portC, 5 },              // Pin 32
    { &portC, 4 },              // Pin 33
    { &portC, 3 },              // Pin 34
    { &portC, 2 },              // Pin 35
    { &portC, 1 },              // Pin 36
    { &portC, 0 },              // Pin 37
    { &portD, 7 },              // Pin 38
    { &portG, 2 },              // Pin 39
    { &portG, 1 },              // Pin 40
    { &portG, 0 },              // Pin 41
    { &portL, 7 },              // Pin 42
    { &portL, 6 },              // Pin 43
    { &portL, 5 },              // Pin 44
    { &portL, 4 },              // Pin 45
    { &portL, 3 },              // Pin 46
    { &portL, 2 },              // Pin 47
    { &portL, 1 },              // Pin 48
    { &portL, 0 },              // Pin 49
    { &portB, 3 },              // Pin 50 (SPI_MISO)
    { &portB, 2 },              // Pin 51 (SPI_MOSI)
    { &portB, 1 },              // Pin 52 (SPI_SCK)
    { &portB, 0 },              // Pin 53
    { &portF, 0 },              // Pin 54
    { &portF, 1 },              // Pin 55
    { &portF, 2 },              // Pin 56
    { &portF, 3 },              // Pin 57
    { &portF, 4 },              // Pin 58
    { &portF, 5 },              // Pin 59
    { &portF, 6 },              // Pin 60
    { &portF, 7 },              // Pin 61

    { &portK, 0 },              // Pin 62
    { &portK, 1 },              // Pin 63
    { &portK, 2 },              // Pin 64
    { &portK, 3 },              // Pin 65
    { &portK, 4 },              // Pin 66
    { &portK, 5 },              // Pin 67
    { &portK, 6 },              // Pin 68
    { &portK, 7 },              // Pin 69
};
#endif

static const int pinCount = sizeof(pinTable)/sizeof(PININFO);

/**
 * Set the Pin mode.
 *
 * pin - Pin # to set mode
 * mode - MODE_INPUT/MODE_INPUT_PULLUP/MODE_OUTPUT
 */
void pinMode(int pin, int mode) {
    if ((pin < 0) || (pin > pinCount))
        return;

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
    if ((pin < 0) || (pin > pinCount))
        return;

    if (value == VALUE_HIGH) {
        *(pinTable[pin].portInfo->port) |= (1 << pinTable[pin].bit);
    } else if (value == VALUE_LOW) {
        *(pinTable[pin].portInfo->port) &= ~(1 << pinTable[pin].bit);
    }
    return;
}

void togglePin(int pin) {
    if ((pin < 0) || (pin > pinCount))
        return;

    uint8_t sreg = SREG;
    cli();
    *(pinTable[pin].portInfo->port) ^= (1 << pinTable[pin].bit);
    SREG = sreg;
}

int digitalRead(int pin) {
    if ((pin < 0) || (pin > pinCount))
        return -1;

    return ((*pinTable[pin].portInfo->pin) & (1 << pinTable[pin].bit))?VALUE_HIGH:VALUE_LOW;
}

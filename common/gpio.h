#ifndef __GPIO_H__
#define __GPIO_H__

void    pinMode(int pin, int mode);
void    digitalWrite(int pin, int value);
void    togglePin(int pin);
int     digitalRead(int pin);

enum {
    MODE_INPUT,
    MODE_INPUT_PULLUP,
    MODE_OUTPUT
};

#define VALUE_HIGH      1
#define VALUE_LOW       0

typedef struct portInfo {
    volatile uint8_t *          port;       // Port Output Register
    volatile uint8_t *          ddr;        // Port Data Direction Register
    volatile uint8_t *          pin;        // Port Input Register
} PORTINFO;

typedef struct pinInfo {
    PORTINFO *  portInfo;
    int         bit;
} PININFO;

#endif

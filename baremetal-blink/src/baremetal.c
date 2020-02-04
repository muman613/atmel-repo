#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "pins.h"

#define MS_DELAY 1000

int main(void) {
    /* Set digital pin 13 to output mode */
    pinMode(BUILTIN_LED, MODE_OUTPUT);

    while (1) {
        togglePin(BUILTIN_LED);
        _delay_ms(MS_DELAY);
    }
}

#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "pins.h"


#define MS_DELAY 5000

#define LED 13  // LED on pin # 13

// #if defined(__AVR_ATmega2560__)
//     const int ddb   = DDB7;
//     const int portb = PORTB7;
// #elif defined(__AVR_ATmega328P__)
//     const int ddb   = DDB5;
//     const int portb = PORTB5;
// #endif

int main (void) {

    /*Set to one the fifth bit of DDRB to one
    **Set digital pin 13 to output mode */
    // DDRB |= _BV(ddb);
    pinMode(LED, MODE_OUTPUT);

    while(1) {
        /*Set to one the fifth bit of PORTB to one
        **Set to HIGH the pin 13 */
        // PORTB |= _BV(portb);
        digitalWrite(LED, VALUE_HIGH);
        /*Wait 3000 ms */
        _delay_ms(MS_DELAY);

        /*Set to zero the fifth bit of PORTB
        **Set to LOW the pin 13 */
        // PORTB &= ~_BV(portb);
        digitalWrite(LED, VALUE_LOW);
        /*Wait 3000 ms */
        _delay_ms(MS_DELAY);
    }
}

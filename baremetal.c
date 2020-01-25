#include <avr/io.h>
#include <util/delay.h>
#if defined(ATMEL2560)
  s  #include <avr/iom2560.h>
#elif defined(ATMEL328)
//   #include <avr/iom328p.h>
#endif

#define MS_DELAY 100

#if defined(ATMEL2560)
const int ddb = DDB7;
const int portb = PORTB7;
#elif defined(ATMEL328)
const int ddb = DDB5;
const int portb = PORTB5;
#endif

int main (void) {
    /*Set to one the fifth bit of DDRB to one
    **Set digital pin 13 to output mode */
    DDRB |= _BV(ddb);

    while(1) {
        /*Set to one the fifth bit of PORTB to one
        **Set to HIGH the pin 13 */
        PORTB |= _BV(portb);

        /*Wait 3000 ms */
        _delay_ms(MS_DELAY);

        /*Set to zero the fifth bit of PORTB
        **Set to LOW the pin 13 */
        PORTB &= ~_BV(portb);

        /*Wait 3000 ms */
        _delay_ms(MS_DELAY);
    }
}
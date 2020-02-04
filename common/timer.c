#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>
#include <inttypes.h>
#include "timer.h"

static CALLBACK     timer1_cb   = NULL;
static uint16_t     count       = 0;

void init_timer1_interrupt(int ms, CALLBACK cb) {
    int16_t     count = (ms / 1000) * (F_CPU / 1024 + 1);

    timer1_cb = cb;
    OCR1A = count;
    TCCR1B |= (1 << WGM12);
    // Mode 4, CTC on OCR1A
    TIMSK1 |= (1 << OCIE1A);
    //Set interrupt on compare match
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // set prescaler to 1024 and start the timer

    sei();
}

ISR (TIMER1_COMPA_vect)
{
    count += 1;

    if (timer1_cb)
        (*timer1_cb)(count);
}

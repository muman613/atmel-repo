/**
 * Module       : timer.h
 * Project      : Atmel General Purpose Library
 * Programmer   : Michael Uman
 */

#ifndef __TIMER_H__
#define __TIMER_H__

#include <inttypes.h>

typedef void (*CALLBACK)(uint16_t count);

void init_timer1_interrupt(int ms, CALLBACK cb);

#endif /* TIMER */

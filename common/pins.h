#ifndef __PINS_H__
#define __PINS_H__

#define BUILTIN_LED     13

#if defined(__AVR_ATmega328P__)
#define SDA 18
#define SCL 19
#elif defined(__AVR_ATmega2560__)
#define SDA 20
#define SCL 21
#endif

#endif// __PINS_H__

/**
 * \brief Implementation of some simple user functions.
 *
 * \file mylib.c
 * \author Matthias Kleemann
 */

#include <math.h>
#include <avr/io.h>
#include <util/delay.h>

#include "mylib.h"

/**
 * \brief initializes a port pin for a LED
 * In this case port pin 2 of the port D of an atmega16 is used.
 * or (need manual change in the CMakeLists.txt)
 * In this case port pin 2 of the port Q of an atxmega128a1 is used.
 */
void initPort(void)
{
#ifdef __AVR_ATxmega128A1__
    PORTQ.DIRSET = PIN2_bm;
    PORTQ.OUT = PIN2_bm;
#else
   /* output pin 2 at port D */
   DDRD |= (1 << PIN2);
#endif
}

/**
 * \brief toggle the defined port pin for the LED
 */
void togglePin(void)
{
#ifdef __AVR_ATxmega128A1__
    PORTQ.OUTTGL = PIN2_bm;
#else
    // toggle pin
   PORTD ^= (1 << PIN2);
#endif
   // wait for 250ms
   _delay_ms(250);
}

double externalLibFunctionSin(double x)
{
    // use the sine function from the math library
    return sin(x);
}

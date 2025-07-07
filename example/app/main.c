/**
 * \brief Simple application to toggle an AVR output for a LED.
 *
 * \file main.c
 * \author Matthias Kleemann
 */

#include <avr/io.h>
#include "mylib.h"

/**
 * \brief main loop
 * Within the main loop the LED port(s) are initialized and toggled, using mylib. The
 * main loop never ends until switching off the AVR itself.
 */
int main(void)
{
   /* test the GNU __extension__ with -pedantic settings */
   uint8_t someBinVar = __extension__ 0b01011010;

#ifdef __AVR_ATxmega128A1__
   PORTQ.DIRSET = someBinVar;
#else
   DDRB |= someBinVar;
#endif

   double x __attribute__((unused));
   x = externalLibFunctionSin(0.5);

   uint8_t y __attribute__((unused));
   y = asmFunction(5, 10);

   initPort();

   while(1)
   {
      togglePin();
   }
}


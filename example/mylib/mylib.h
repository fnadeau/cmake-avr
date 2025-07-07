#ifndef MYLIB_H
#define MYLIB_H

#include <stdint.h>

/**
 * \brief Header for mylib.
 *
 * \file mylib.h
 * \author Matthias Kleemann
 */

/**
 * \brief initializes a port pin for a LED
 * In this case port pin 2 of the port D of an atmega8 is used.
 */
void initPort(void);

/**
 * \brief toggle the defined port pin for the LED
 */
void togglePin(void);

/**
 * \brief external library function to calculate the sine of a value
 * This function is provided by an external library.
 *
 * \param x The value for which the sine is calculated.
 * \return The sine of the value x.
 */
double externalLibFunctionSin(double x);

/**
 * \brief assembly function to add two integers
 *
 * This function is implemented in assembly language and adds two integers.
 *
 * \param a The first integer to add.
 * \param b The second integer to add.
 * \return The sum of the two integers.
 */
uint8_t asmFunction(uint8_t a, uint8_t b);

#endif // MYLIB_H

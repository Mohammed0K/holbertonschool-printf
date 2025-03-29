#include "main.h"

/**
 * print_octal_long - Prints an unsigned long integer in octal notation.
 * @n: The unsigned long integer.
 *
 * Return: The number of characters printed.
 */
int print_octal_long(unsigned long int n)
{
	int count = 0;
	char digit;

	if (n / 8)
		count += print_octal_long(n / 8);
	digit = (n % 8) + '0';
	buffered_putchar(digit);
	return (count + 1);
}

#include "main.h"

/**
 * print_octal - Prints an unsigned integer in octal notation.
 * @n: The unsigned integer.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int n)
{
	int count = 0;
	char digit;

	if (n / 8)
		count += print_octal(n / 8);
	digit = (n % 8) + '0';
	buffered_putchar(digit);
	return (count + 1);
}

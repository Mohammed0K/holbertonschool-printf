#include "main.h"

/**
 * print_unsigned_long_number - Prints an unsigned long integer.
 * @n: The unsigned long integer to print.
 *
 * Return: The number of digits printed.
 */
int print_unsigned_long_number(unsigned long int n)
{
	int count = 0;
	char digit;

	if (n / 10)
		count += print_unsigned_long_number(n / 10);
	digit = (n % 10) + '0';
	buffered_putchar(digit);
	return (count + 1);
}

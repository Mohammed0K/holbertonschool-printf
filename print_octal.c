#include "main.h"

/**
 * print_octal - Prints an unsigned integer in octal notation.
 * @n: The unsigned integer.
 *
 * Return: Number of characters printed.
 */
int print_octal(unsigned int n)
{
	int count = 0;
	char digit;

	if (n / 8)
		count += print_octal(n / 8);
	digit = (n % 8) + '0';
	write(1, &digit, 1);
	return (count + 1);
}

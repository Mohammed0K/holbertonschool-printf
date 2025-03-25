#include "main.h"

/**
 * print_unsigned_number - Prints an unsigned integer.
 * @n: The unsigned integer to print.
 *
 * Return: Number of digits printed.
 */
int print_unsigned_number(unsigned int n)
{
	int count = 0;
	char digit;

	if (n / 10)
		count += print_unsigned_number(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
	return (count + 1);
}

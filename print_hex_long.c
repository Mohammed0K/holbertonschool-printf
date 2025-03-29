#include "main.h"

/**
 * print_hex_long - Prints an unsigned long integer in hexadecimal notation.
 * @n: The unsigned long integer.
 * @uppercase: 0 for lowercase, 1 for uppercase.
 *
 * Return: The number of characters printed.
 */
int print_hex_long(unsigned long int n, int uppercase)
{
	int count = 0;
	char digit;

	if (n / 16)
		count += print_hex_long(n / 16, uppercase);
	if (n % 16 < 10)
		digit = (n % 16) + '0';
	else
	{
		if (uppercase)
			digit = (n % 16) - 10 + 'A';
		else
			digit = (n % 16) - 10 + 'a';
	}
	buffered_putchar(digit);
	return (count + 1);
}

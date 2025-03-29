#include "main.h"

/**
 * print_long_number - Prints a long integer.
 * @n: The long integer to print.
 *
 * Return: The number of characters printed.
 */
int print_long_number(long int n)
{
	int count = 0;
	unsigned long int num;

	if (n < 0)
	{
		count += buffered_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}
	count += print_unsigned_long_number(num);
	return (count);
}

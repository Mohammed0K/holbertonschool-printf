#include "main.h"

/**
 * print_number - Prints an integer.
 * @n: The integer to print.
 *
 * Return: Number of characters printed.
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
		num = n;
	count += print_unsigned_number(num);
	return (count);
}

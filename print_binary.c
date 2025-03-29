#include "main.h"

/**
 * print_binary - Converts an unsigned int to binary and prints it.
 * @n: The unsigned int to convert.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int n)
{
	int i = 0, count = 0;
	char local_buf[32];
	char c;

	if (n == 0)
	{
		buffered_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		local_buf[i++] = (n % 2) + '0';
		n /= 2;
	}
	while (i--)
	{
		c = local_buf[i];
		buffered_putchar(c);
		count++;
	}
	return (count);
}

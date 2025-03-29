#include "main.h"
/**
 * print_binary - Prints an unsigned number in binary.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n = va_arg(types, unsigned int);
	int i = 0, count = 0;
	char temp[32];

	(void)flags;
	(void)width;
	(void)precision;
	(void)size;
	if (n == 0)
	{
		buffer[count++] = '0';
		return (write(1, buffer, count));
	}
	while (n > 0)
	{
		temp[i++] = (n % 2) + '0';
		n /= 2;
	}
	while (i--)
		buffer[count++] = temp[i];
	return (write(1, buffer, count));
}

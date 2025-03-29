#include "main.h"
/**
 * print_octal - Prints an unsigned number in octal notation.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n = va_arg(types, unsigned int);
	int i = 0, count = 0;
	char temp[50];

	(void)width;
	(void)precision;
	n = convert_size_unsgnd(n, size);
	if (n == 0)
	{
		buffer[count++] = '0';
		return (write(1, buffer, count));
	}
	while (n > 0)
	{
		temp[i++] = (n % 8) + '0';
		n /= 8;
	}
	if (flags & FLAG_HASH && temp[i - 1] != '0')
		buffer[count++] = '0';
	while (i--)
		buffer[count++] = temp[i];
	return (write(1, buffer, count));
}

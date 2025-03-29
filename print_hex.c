#include "main.h"
/**
 * print_hex - Prints an unsigned number in hexadecimal (lowercase).
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_hex(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n = va_arg(types, unsigned int);
	int i = 0, count = 0;
	char temp[50];
	char *map = "0123456789abcdef";

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
		temp[i++] = map[n % 16];
		n /= 16;
	}
	if (flags & FLAG_HASH && buffer[0] != '0')
	{
		buffer[count++] = 'x';
		buffer[count++] = '0';
	}
	while (i--)
		buffer[count++] = temp[i];
	return (write(1, buffer, count));
}

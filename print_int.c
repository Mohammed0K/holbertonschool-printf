#include "main.h"
/**
 * print_int - Prints an integer.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, count = 0, neg = 0;
	long int n = va_arg(types, int);
	unsigned long int num;
	char temp[50];

	n = convert_size_number(n, size);
	if (n < 0)
	{
		neg = 1;
		num = -n;
	}
	else
	{
		num = n;
	}
	do {
		temp[i++] = (num % 10) + '0';
		num /= 10;
	} while (num != 0);
	if (neg)
		temp[i++] = '-';
	while (i--)
		buffer[count++] = temp[i];
	return (write(1, buffer, count));
}

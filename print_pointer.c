#include "main.h"
/**
 * print_pointer - Prints the value of a pointer.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned long int num;
	int i = 0, count = 0;
	char temp[50];
	void *p = va_arg(types, void *);

	(void)flags;
	(void)width;
	(void)precision;
	(void)size;
	if (p == NULL)
		return (write(1, "(nil)", 5));
	num = (unsigned long int)p;
	while (num > 0)
	{
		temp[i++] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	buffer[count++] = 'x';
	buffer[count++] = '0';
	while (i--)
		buffer[count++] = temp[i];
	return (write(1, buffer, count));
}

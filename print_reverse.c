#include "main.h"
/**
 * print_reverse - Prints a string in reverse.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, count = 0;
	char *str = va_arg(types, char *);

	(void)flags;
	(void)width;
	(void)precision;
	(void)size;
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		;
	for (i = i - 1; i >= 0; i--)
		buffer[count++] = str[i];
	return (write(1, buffer, count));
}

#include "main.h"

/**
 * print_char - Prints a single character.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = (char)va_arg(types, int);

	(void)flags;
	(void)width;
	(void)precision;
	(void)size;
	return (write(1, &c, 1));
}

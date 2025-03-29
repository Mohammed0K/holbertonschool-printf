#include "main.h"

/**
 * print_percent - Prints a percent sign.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	(void)types;
	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;
	return (write(1, "%", 1));
}

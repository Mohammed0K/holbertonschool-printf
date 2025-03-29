#include "main.h"

/**
 * _printf - Prints output according to a format.
 * @format: The format string.
 *
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = process_format(format, &args);
	va_end(args);
	flush_buffer();
	return (count);
}

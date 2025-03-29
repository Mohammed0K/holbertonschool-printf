#include "main.h"
/**
 * _printf - Prints output according to a format.
 * @format: The format string.
 *
 * This function processes the format string, handles format specifiers,
 * and writes the formatted output to stdout.
 *
 * Return: The total number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list list;
	char buffer[BUFF_SIZE];
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, printed_spec;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[printed++] = format[i];
			if (printed == BUFF_SIZE)
			{
				write(1, buffer, printed);
				printed_chars += printed;
				printed = 0;
			}
		}
		else
		{
			write(1, buffer, printed);
			printed_chars += printed;
			printed = 0;
			flags = handle_flags(format, &i);
			width = handle_width(format, &i, list);
			precision = handle_precision(format, &i, list);
			size = handle_size(format, &i);
			printed_spec = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed_spec == -1)
				return (-1);
			printed_chars += printed_spec;
		}
	}
	write(1, buffer, printed);
	printed_chars += printed;
	va_end(list);
	return (printed_chars);
}

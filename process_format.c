#include "main.h"

/**
 * process_format - Processes the format string and prints output.
 * @format: The format string.
 * @args: A list of arguments.
 *
 * Return: The total number of characters printed, or -1 on error.
 */
int process_format(const char *format, va_list *args)
{
	int i = 0, count = 0, printed;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			printed = handle_conversion(format[i], args);
			if (printed < 0)
				return (-1);
			count += printed;
		}
		else
		{
			buffered_putchar(format[i]);
			count++;
		}
		i++;
	}
	return (count);
}

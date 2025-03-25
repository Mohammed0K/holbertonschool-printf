#include "main.h"

/**
 * process_format - Processes the format string and prints the output.
 * @format: The format string.
 * @args: The va_list containing the arguments.
 *
 * Return: Total number of characters printed, or -1 on error.
 */
int process_format(const char *format, va_list args)
{
	int i = 0, count = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			count += handle_conversion(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

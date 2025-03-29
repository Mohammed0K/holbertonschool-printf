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
	int flags, length;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			flags = 0;
			/* Parse flag characters */
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				if (format[i] == '+')
					flags |= FLAG_PLUS;
				else if (format[i] == ' ')
					flags |= FLAG_SPACE;
				else if (format[i] == '#')
					flags |= FLAG_HASH;
				i++;
			}
			/* Parse length modifiers */
			length = LENGTH_NONE;
			if (format[i] == 'l')
			{
				length = LENGTH_L;
				i++;
			}
			else if (format[i] == 'h')
			{
				length = LENGTH_H;
				i++;
			}
			if (!format[i])
				return (-1);
			printed = handle_conversion(format[i], args, flags, length);
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

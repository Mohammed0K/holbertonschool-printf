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
	int flags, width, length, precision;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			flags = 0;
			while (format[i] == '+' || format[i] == ' ' ||
			       format[i] == '#' || format[i] == '0' ||
			       format[i] == '-')
			{
				if (format[i] == '+')
					flags |= FLAG_PLUS;
				else if (format[i] == ' ')
					flags |= FLAG_SPACE;
				else if (format[i] == '#')
					flags |= FLAG_HASH;
				else if (format[i] == '0')
					flags |= FLAG_ZERO;
				else if (format[i] == '-')
					flags |= FLAG_MINUS;
				i++;
			}
			if (format[i] == '*')
			{
				width = va_arg(*args, int);
				i++;
			}
			else
			{
				width = 0;
				while (format[i] >= '0' && format[i] <= '9')
				{
					width = width * 10 + (format[i] - '0');
					i++;
				}
			}
			precision = -1;
			if (format[i] == '.')
			{
				i++;
				if (format[i] == '*')
				{
					precision = va_arg(*args, int);
					i++;
				}
				else
				{
					precision = 0;
					while (format[i] >= '0' && format[i] <= '9')
					{
						precision = precision * 10 + (format[i] - '0');
						i++;
					}
				}
			}
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
			printed = handle_conversion(format[i], args, flags,
						    length, width, precision);
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

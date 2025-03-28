#include "main.h"
/**
 * process_format - Processes the format string and prints the output.
 * @format: The format string.
 * @args: Pointer to the va_list containing the arguments.
 *
 * Return: Total number of characters printed, or -1 on error.
 */
int process_format(const char *format, va_list args)
{
	int i = 0, count = 0, printed;
	char buffer[1024];
	int buff_index = 0;
	
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (buff_index > 0)
			{
				write(1, buffer, buff_index);
				buff_index = 0;
			}
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
			buffer[buff_index++] = format[i];
			if (buff_index == 1024)
			{
				write(1, buffer, buff_index);
				buff_index = 0;
			}
			count++;
		}
		i++;
	}
	if (buff_index > 0)
		write(1, buffer, buff_index);
	return (count);
}

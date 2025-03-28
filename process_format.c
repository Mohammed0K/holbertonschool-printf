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
	int i = 0;
	int count = 0;
	int printed;
	char buffer[1024];
	int buff_index = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			/* Flush the buffer before handling conversion */
			if (buff_index > 0)
			{
				write(1, buffer, buff_index);
				buff_index = 0;
			}
			i++;  /* Move to conversion specifier */
			if (!format[i])
				return (-1);
			printed = handle_conversion(format[i], &args);
			if (printed < 0)
				return (-1);
			count += printed;
			i++;  /* Advance past the specifier */
			continue;
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
	/* Flush any remaining characters */
	if (buff_index > 0)
		write(1, buffer, buff_index);
	return (count);
}

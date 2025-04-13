#include "main.h"

/**
 * handle_conversion - Handles simple conversion specifiers: c, s, %.
 * @specifier: The conversion specifier.
 * @args: Pointer to the list of arguments.
 *
 * Return: Number of characters printed.
 */
int handle_conversion(char specifier, va_list *args)
{
	int count = 0;
	int i;

	if (specifier == 's')
	{
		char *str = va_arg(*args, char *);

		if (!str)
			str = "(null)";

		for (i = 0; str[i]; i++)
		{
			buffered_putchar(str[i]);
			count++;
		}
	}
	else if (specifier == 'c')
	{
		char ch = (char)va_arg(*args, int);

		buffered_putchar(ch);
		count++;
	}
	else if (specifier == '%')
	{
		buffered_putchar('%');
		count++;
	}

	return (count);
}

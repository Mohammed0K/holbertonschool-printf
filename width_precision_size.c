#include "main.h"
/**
 * handle_width - Calculates the field width from the format string.
 * @format: The format string.
 * @i: Pointer to the current index in the format string.
 * @list: The argument list.
 *
 * Return: The field width.
 */
int handle_width(const char *format, int *i, va_list list)
{
	int width = 0;

	for ((*i)++; format[*i] >= '0' && format[*i] <= '9'; (*i)++)
		width = width * 10 + (format[*i] - '0');
	if (format[*i] == '*')
	{
		width = va_arg(list, int);
		(*i)++;
	}
	return (width);
}

/**
 * handle_precision - Calculates the precision from the format string.
 * @format: The format string.
 * @i: Pointer to the current index in the format string.
 * @list: The argument list.
 *
 * Return: The precision.
 */
int handle_precision(const char *format, int *i, va_list list)
{
	int precision = -1;

	if (format[*i] != '.')
		return (precision);
	precision = 0;
	(*i)++;
	for (; format[*i] >= '0' && format[*i] <= '9'; (*i)++)
		precision = precision * 10 + (format[*i] - '0');
	if (format[*i] == '*')
	{
		precision = va_arg(list, int);
		(*i)++;
	}
	return (precision);
}

/**
 * handle_size - Determines the size specifier.
 * @format: The format string.
 * @i: Pointer to the current index in the format string.
 *
 * Return: The size specifier.
 */
int handle_size(const char *format, int *i)
{
	int size = 0;

	if (format[*i] == 'l')
		size = SIZE_LONG;
	else if (format[*i] == 'h')
		size = SIZE_SHORT;
	if (size)
		(*i)++;
	return (size);
}

#include "main.h"

/**
 * handle_print - Matches a format specifier with the corresponding function.
 * @fmt: The format string.
 * @i: Pointer to the current index in the format string.
 * @list: The argument list.
 * @buffer: The buffer array used for printing.
 * @flags: Calculates active flags.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: The number of characters printed.
 */
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int j, k, unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hex},
		{'X', print_HEX}, {'S', print_non_printable}, {'p', print_pointer},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (j = 0; fmt_types[j].fmt != '\0'; j++)
	{
		if (fmt[*i] == fmt_types[j].fmt)
			return (fmt_types[j].fn(list, buffer, flags, width, precision, size));
	}
	if (fmt_types[j].fmt == '\0')
	{
		if (fmt[*i] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*i - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			for (k = *i; k < width; k++)
				unknown_len += write(1, " ", 1);
		}
		unknown_len += write(1, &fmt[*i], 1);
		return (unknown_len);
	}
	return (printed_chars);
}

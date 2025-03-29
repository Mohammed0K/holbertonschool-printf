#include "main.h"

/**
 * handle_conversion - Handles conversion specifiers with flag, length,
 * field width, and precision support.
 * @specifier: The conversion specifier.
 * @args: Pointer to the list of arguments.
 * @flags: Bitwise OR of flags.
 * @length: Length modifier.
 * @width: Field width.
 * @precision: Precision value (-1 if not specified).
 *
 * Return: Number of characters printed.
 */
int handle_conversion(char specifier, va_list *args, int flags, int length,
		      int width, int precision)
{
	int count = 0, i;

	if (specifier == 'd' || specifier == 'i')
	{
		long num;
		int negative = 0;
		char num_buf[50];
		int pos = 0, num_digits, zeros = 0, pad_zeros = 0, spaces = 0;
		int sign_len = 0;
		char sign_char = '\0';

		if (length == LENGTH_L)
			num = va_arg(*args, long int);
		else
			num = va_arg(*args, int);
		if (num < 0)
		{
			negative = 1;
			num = -num;
		}
		if (num == 0)
			num_buf[pos++] = '0';
		else
		{
			while (num)
			{
				num_buf[pos++] = (num % 10) + '0';
				num /= 10;
			}
		}
		if (precision == 0 && pos == 1 && num_buf[0] == '0')
			pos = 0;
		num_digits = pos;
		if (negative)
		{
			sign_len = 1;
			sign_char = '-';
		}
		else if (flags & FLAG_PLUS)
		{
			sign_len = 1;
			sign_char = '+';
		}
		else if (flags & FLAG_SPACE)
		{
			sign_len = 1;
			sign_char = ' ';
		}
		if (precision > num_digits)
			zeros = precision - num_digits;
		else
			zeros = 0;
		if (precision < 0 && (flags & FLAG_ZERO) && !(flags & FLAG_MINUS) &&
		    width > (sign_len + num_digits))
			pad_zeros = width - (sign_len + num_digits);
		else
			pad_zeros = 0;
		{
			int temp = (num_digits > zeros) ? num_digits : zeros;
			int total_num_len = sign_len + temp;

			if (pad_zeros > total_num_len)
				total_num_len = pad_zeros + sign_len + num_digits;
			if (width > total_num_len)
				spaces = width - total_num_len;
			else
				spaces = 0;
		}
		if (!(flags & FLAG_MINUS))
		{
			for (i = 0; i < spaces; i++)
			{
				buffered_putchar(' ');
				count++;
			}
		}
		if (sign_len)
		{
			buffered_putchar(sign_char);
			count++;
		}
		{
			int zeros_to_print = (pad_zeros > 0) ? pad_zeros : zeros;

			for (i = 0; i < zeros_to_print; i++)
			{
				buffered_putchar('0');
				count++;
			}
		}
		for (i = num_digits - 1; i >= 0; i--)
		{
			buffered_putchar(num_buf[i]);
			count++;
		}
		if (flags & FLAG_MINUS)
		{
			for (i = 0; i < spaces; i++)
			{
				buffered_putchar(' ');
				count++;
			}
		}
		return (count);
	}
	return (handle_default(specifier));
}

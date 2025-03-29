#include "main.h"

/**
 * handle_conversion - Handles conversion specifiers with flag, length,
 *                     field width, and precision support.
 * @specifier: The conversion specifier.
 * @args: A pointer to the list of arguments.
 * @flags: Bitwise OR of flags (+, space, #, 0, -).
 * @length: The length modifier (LENGTH_NONE, LENGTH_H, LENGTH_L).
 * @width: The field width.
 * @precision: The precision value (-1 if not specified).
 *
 * Return: Number of characters printed for the conversion.
 */
int handle_conversion(char specifier, va_list *args, int flags,
		      int length, int width, int precision)
{
	int count = 0, pad = 0, i = 0, real_count = 0, len = 0;
	va_list args_copy;

	switch (specifier)
	{
		case 'c':
		{
			int ch;
			pad = (width > 1) ? width - 1 : 0;
			if (!(flags & FLAG_MINUS))
			{
				for (i = 0; i < pad; i++)
					count += buffered_putchar(' ');
			}
			ch = va_arg(*args, int);
			count += buffered_putchar(ch);
			if (flags & FLAG_MINUS)
			{
				for (i = 0; i < pad; i++)
					count += buffered_putchar(' ');
			}
			break;
		}
		case 's':
		{
			char *s = va_arg(*args, char *);
			int str_len = 0;
			if (s == NULL)
				s = "(null)";
			while (s[str_len])
				str_len++;
			if (precision >= 0 && precision < str_len)
				str_len = precision;
			pad = (width > str_len) ? width - str_len : 0;
			if (!(flags & FLAG_MINUS))
			{
				for (i = 0; i < pad; i++)
					count += buffered_putchar(' ');
			}
			for (i = 0; i < str_len; i++)
				count += buffered_putchar(s[i]);
			if (flags & FLAG_MINUS)
			{
				for (i = 0; i < pad; i++)
					count += buffered_putchar(' ');
			}
			break;
		}
		case '%':
		{
			pad = (width > 1) ? width - 1 : 0;
			if (!(flags & FLAG_MINUS))
			{
				for (i = 0; i < pad; i++)
					count += buffered_putchar(' ');
			}
			count += buffered_putchar('%');
			if (flags & FLAG_MINUS)
			{
				for (i = 0; i < pad; i++)
					count += buffered_putchar(' ');
			}
			break;
		}
		case 'd':
		case 'i':
		{
			va_copy(args_copy, *args);
			g_count_mode = 1;
			g_dummy_count = 0;
			if (length == LENGTH_L)
				print_long_number(va_arg(args_copy, long int));
			else if (length == LENGTH_H)
				print_number((short int)va_arg(args_copy, int));
			else
				print_number(va_arg(args_copy, int));
			len = g_dummy_count;
			g_count_mode = 0;
			va_end(args_copy);
			if (precision > len)
				len = precision;
			pad = (width > len) ? width - len : 0;
			if (!(flags & FLAG_MINUS) && (flags & FLAG_ZERO) && precision < 0)
			{
				for (i = 0; i < pad; i++)
					real_count += buffered_putchar('0');
			}
			else
			{
				for (i = 0; i < pad; i++)
					real_count += buffered_putchar(' ');
			}
			if (length == LENGTH_L)
				real_count += print_long_number(va_arg(*args, long int));
			else if (length == LENGTH_H)
				real_count += print_number((short int)va_arg(*args, int));
			else
				real_count += print_number(va_arg(*args, int));
			if (flags & FLAG_MINUS)
			{
				for (i = 0; i < pad; i++)
					real_count += buffered_putchar(' ');
			}
			count = real_count;
			break;
		}
		case 'r':
		{
			count = print_reversed(*args);
			break;
		}
		case 'R':
		{
			count = print_rot13(*args);
			break;
		}
		default:
			count = handle_default(specifier);
			break;
	}
	return (count);
}

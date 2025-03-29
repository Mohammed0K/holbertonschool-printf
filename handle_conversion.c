#include "main.h"

/**
 * handle_conversion - Handles conversion specifiers with flag, length,
 *                     and field width support.
 * @specifier: The conversion specifier.
 * @args: A pointer to the list of arguments.
 * @flags: Bitwise OR of flags (+, space, #).
 * @length: The length modifier (LENGTH_NONE, LENGTH_H, LENGTH_L).
 * @width: The field width.
 *
 * Return: Number of characters printed for the conversion.
 */
int handle_conversion(char specifier, va_list *args, int flags,
		      int length, int width)
{
	int count = 0, pad, i;
	int real_count = 0, len;
	va_list args_copy;

	switch (specifier)
	{
		case 'c':
		{
			int ch;
			pad = (width > 1) ? width - 1 : 0;
			for (i = 0; i < pad; i++)
				count += buffered_putchar(' ');
			ch = va_arg(*args, int);
			count += buffered_putchar(ch);
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
			pad = (width > str_len) ? width - str_len : 0;
			for (i = 0; i < pad; i++)
				count += buffered_putchar(' ');
			while (*s)
				count += buffered_putchar(*s++);
			break;
		}
		case '%':
		{
			pad = (width > 1) ? width - 1 : 0;
			for (i = 0; i < pad; i++)
				count += buffered_putchar(' ');
			count += buffered_putchar('%');
			break;
		}
		case 'd':
		case 'i':
		{
			if (width > 0)
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
				pad = (width > len) ? width - len : 0;
				for (i = 0; i < pad; i++)
					real_count += buffered_putchar(' ');
			}
			if (length == LENGTH_L)
				real_count += print_long_number(va_arg(*args, long int));
			else if (length == LENGTH_H)
				real_count += print_number((short int)va_arg(*args, int));
			else
				real_count += print_number(va_arg(*args, int));
			count = real_count;
			break;
		}
		case 'u':
		{
			if (width > 0)
			{
				va_copy(args_copy, *args);
				g_count_mode = 1;
				g_dummy_count = 0;
				if (length == LENGTH_L)
					print_unsigned_long_number(
						va_arg(args_copy, unsigned long int));
				else if (length == LENGTH_H)
					print_unsigned_number((unsigned short int)
						va_arg(args_copy, int));
				else
					print_unsigned_number(va_arg(args_copy, unsigned int));
				len = g_dummy_count;
				g_count_mode = 0;
				va_end(args_copy);
				pad = (width > len) ? width - len : 0;
				for (i = 0; i < pad; i++)
					real_count += buffered_putchar(' ');
			}
			if (length == LENGTH_L)
				real_count += print_unsigned_long_number(
					va_arg(*args, unsigned long int));
			else if (length == LENGTH_H)
				real_count += print_unsigned_number((unsigned short int)
					va_arg(*args, int));
			else
				real_count += print_unsigned_number(
					va_arg(*args, unsigned int));
			count = real_count;
			break;
		}
		case 'o':
		{
			if (width > 0)
			{
				va_copy(args_copy, *args);
				g_count_mode = 1;
				g_dummy_count = 0;
				if (length == LENGTH_L)
				{
					if (flags & FLAG_HASH)
						buffered_putchar('0');
					print_octal_long(va_arg(args_copy,
						unsigned long int));
				}
				else if (length == LENGTH_H)
				{
					if (flags & FLAG_HASH)
						buffered_putchar('0');
					print_octal((unsigned short int)
						va_arg(args_copy, int));
				}
				else
				{
					if (flags & FLAG_HASH)
						buffered_putchar('0');
					print_octal(va_arg(args_copy, unsigned int));
				}
				len = g_dummy_count;
				g_count_mode = 0;
				va_end(args_copy);
				pad = (width > len) ? width - len : 0;
				for (i = 0; i < pad; i++)
					real_count += buffered_putchar(' ');
			}
			if (length == LENGTH_L)
			{
				if (flags & FLAG_HASH)
					real_count += buffered_putchar('0');
				real_count += print_octal_long(va_arg(*args,
					unsigned long int));
			}
			else if (length == LENGTH_H)
			{
				if (flags & FLAG_HASH)
					real_count += buffered_putchar('0');
				real_count += print_octal((unsigned short int)
					va_arg(*args, int));
			}
			else
			{
				if (flags & FLAG_HASH)
					real_count += buffered_putchar('0');
				real_count += print_octal(va_arg(*args, unsigned int));
			}
			count = real_count;
			break;
		}
		case 'x':
		case 'X':
		{
			if (width > 0)
			{
				va_copy(args_copy, *args);
				g_count_mode = 1;
				g_dummy_count = 0;
				if (length == LENGTH_L)
				{
					if (flags & FLAG_HASH)
					{
						buffered_putchar('0');
						buffered_putchar(specifier == 'x' ? 'x' : 'X');
					}
					print_hex_long(va_arg(args_copy, unsigned long int),
						       (specifier == 'X'));
				}
				else if (length == LENGTH_H)
				{
					if (flags & FLAG_HASH)
					{
						buffered_putchar('0');
						buffered_putchar(specifier == 'x' ? 'x' : 'X');
					}
					print_hex((unsigned short int)
						  va_arg(args_copy, int),
						  (specifier == 'X'));
				}
				else
				{
					if (flags & FLAG_HASH)
					{
						buffered_putchar('0');
						buffered_putchar(specifier == 'x' ? 'x' : 'X');
					}
					print_hex(va_arg(args_copy, unsigned int),
						  (specifier == 'X'));
				}
				len = g_dummy_count;
				g_count_mode = 0;
				va_end(args_copy);
				pad = (width > len) ? width - len : 0;
				for (i = 0; i < pad; i++)
					real_count += buffered_putchar(' ');
			}
			if (length == LENGTH_L)
			{
				if (flags & FLAG_HASH)
				{
					real_count += buffered_putchar('0');
					real_count += buffered_putchar(specifier == 'x' ?
									'x' : 'X');
				}
				real_count += print_hex_long(va_arg(*args,
					unsigned long int), (specifier == 'X'));
			}
			else if (length == LENGTH_H)
			{
				if (flags & FLAG_HASH)
				{
					real_count += buffered_putchar('0');
					real_count += buffered_putchar(specifier == 'x' ?
									'x' : 'X');
				}
				real_count += print_hex((unsigned short int)
					va_arg(*args, int), (specifier == 'X'));
			}
			else
			{
				if (flags & FLAG_HASH)
				{
					real_count += buffered_putchar('0');
					real_count += buffered_putchar(specifier == 'x' ?
									'x' : 'X');
				}
				real_count += print_hex(va_arg(*args, unsigned int),
						       (specifier == 'X'));
			}
			count = real_count;
			break;
		}
		case 'p':
		{
			count = print_pointer(va_arg(*args, void *));
			break;
		}
		case 'b':
		{
			if (width > 0)
			{
				va_copy(args_copy, *args);
				g_count_mode = 1;
				g_dummy_count = 0;
				print_binary(va_arg(args_copy, unsigned int));
				len = g_dummy_count;
				g_count_mode = 0;
				va_end(args_copy);
				pad = (width > len) ? width - len : 0;
				for (i = 0; i < pad; i++)
					real_count += buffered_putchar(' ');
			}
			real_count += print_binary(va_arg(*args, unsigned int));
			count = real_count;
			break;
		}
		case 'S':
			count = print_custom_S(*args);
			break;
		default:
			count = handle_default(specifier);
			break;
	}
	return (count);
}

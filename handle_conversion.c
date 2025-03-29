#include "main.h"

/**
 * handle_conversion - Handles conversion specifiers with flag support.
 * @specifier: The conversion specifier.
 * @args: A pointer to the list of arguments.
 * @flags: Bitwise OR of flags (+, space, #).
 *
 * Return: Number of characters printed for the conversion.
 */
int handle_conversion(char specifier, va_list *args, int flags)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
			count = print_char(*args);
			break;
		case 's':
			count = print_str(*args);
			break;
		case '%':
			count = buffered_putchar('%');
			break;
		case 'd':
		case 'i':
		{
			int n = va_arg(*args, int);

			if (n >= 0)
			{
				if (flags & FLAG_PLUS)
					count += buffered_putchar('+');
				else if (flags & FLAG_SPACE)
					count += buffered_putchar(' ');
			}
			count += print_number(n);
			break;
		}
		case 'u':
		{
			unsigned int n = va_arg(*args, unsigned int);

			count += print_unsigned_number(n);
			break;
		}
		case 'o':
		{
			unsigned int n = va_arg(*args, unsigned int);

			if ((flags & FLAG_HASH) && n != 0)
				count += buffered_putchar('0');
			count += print_octal(n);
			break;
		}
		case 'x':
		case 'X':
		{
			unsigned int n = va_arg(*args, unsigned int);

			if ((flags & FLAG_HASH) && n != 0)
			{
				count += buffered_putchar('0');
				count += buffered_putchar(specifier == 'x' ? 'x' : 'X');
			}
			count += print_hex(n, (specifier == 'X'));
			break;
		}
		case 'p':
			count = print_pointer(va_arg(*args, void *));
			break;
		case 'b':
			count = print_binary(va_arg(*args, unsigned int));
			break;
		case 'S':
			count = print_custom_S(*args);
			break;
		default:
			count = handle_default(specifier);
			break;
	}
	return (count);
}

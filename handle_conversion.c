#include "main.h"

/**
 * handle_conversion - Handles conversion specifiers with flag and length support.
 * @specifier: The conversion specifier.
 * @args: A pointer to the list of arguments.
 * @flags: Bitwise OR of flags (+, space, #).
 * @length: The length modifier (LENGTH_NONE, LENGTH_H, LENGTH_L).
 *
 * Return: Number of characters printed for the conversion.
 */
int handle_conversion(char specifier, va_list *args, int flags, int length)
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
			if (length == LENGTH_L)
			{
				long int value = va_arg(*args, long int);
				count = print_long_number(value);
			}
			else if (length == LENGTH_H)
			{
				int value = va_arg(*args, int);
				count = print_number((short int)value);
			}
			else
			{
				int value = va_arg(*args, int);
				count = print_number(value);
			}
			break;
		}
		case 'u':
		{
			if (length == LENGTH_L)
			{
				unsigned long int value =
				    va_arg(*args, unsigned long int);
				count = print_unsigned_long_number(value);
			}
			else if (length == LENGTH_H)
			{
				int value = va_arg(*args, int);
				count = print_unsigned_number((unsigned short int)value);
			}
			else
			{
				unsigned int value = va_arg(*args, unsigned int);
				count = print_unsigned_number(value);
			}
			break;
		}
		case 'o':
		{
			if (length == LENGTH_L)
			{
				unsigned long int value =
				    va_arg(*args, unsigned long int);
				if ((flags & FLAG_HASH) && value != 0)
					count += buffered_putchar('0');
				count += print_octal_long(value);
			}
			else if (length == LENGTH_H)
			{
				int value = va_arg(*args, int);
				unsigned short int us_val = (unsigned short int)value;
				if ((flags & FLAG_HASH) && us_val != 0)
					count += buffered_putchar('0');
				count += print_octal(us_val);
			}
			else
			{
				unsigned int value = va_arg(*args, unsigned int);
				if ((flags & FLAG_HASH) && value != 0)
					count += buffered_putchar('0');
				count += print_octal(value);
			}
			break;
		}
		case 'x':
		case 'X':
		{
			if (length == LENGTH_L)
			{
				unsigned long int value =
				    va_arg(*args, unsigned long int);
				if ((flags & FLAG_HASH) && value != 0)
				{
					count += buffered_putchar('0');
					count += buffered_putchar(
					    specifier == 'x' ? 'x' : 'X');
				}
				count += print_hex_long(value, (specifier == 'X'));
			}
			else if (length == LENGTH_H)
			{
				int value = va_arg(*args, int);
				unsigned short int us_val = (unsigned short int)value;
				if ((flags & FLAG_HASH) && us_val != 0)
				{
					count += buffered_putchar('0');
					count += buffered_putchar(
					    specifier == 'x' ? 'x' : 'X');
				}
				count += print_hex(us_val, (specifier == 'X'));
			}
			else
			{
				unsigned int value = va_arg(*args, unsigned int);
				if ((flags & FLAG_HASH) && value != 0)
				{
					count += buffered_putchar('0');
					count += buffered_putchar(
					    specifier == 'x' ? 'x' : 'X');
				}
				count += print_hex(value, (specifier == 'X'));
			}
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

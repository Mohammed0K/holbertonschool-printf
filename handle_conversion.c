#include "main.h"
/**
 * handle_conversion - Handles conversion specifiers.
 * @specifier: The conversion specifier.
 * @args: The va_list containing the arguments.
 *
 * Return: Number of characters printed for the conversion.
 */
int handle_conversion(char specifier, va_list args)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
			count = print_char(args);
			break;
		case 's':
			count = print_str(args);
			break;
		case '%':
			write(1, "%", 1);
			count = 1;
			break;
		case 'd':
		case 'i':
			count = print_number(va_arg(args, int));
			break;
		case 'u':
			count = print_unsigned_number(va_arg(args, unsigned int));
			break;
		case 'o':
			count = print_octal(va_arg(args, unsigned int));
			break;
		case 'x':
		case 'X':
			count = print_hex(va_arg(args, unsigned int), (specifier == 'X'));
			break;
		case 'p':
			count = print_pointer(va_arg(args, void *));
			break;
		case 'b':
			count = print_binary(va_arg(args, unsigned int));
			break;
		default:
			count = handle_default(specifier);
			break;
	}
	return (count);
}

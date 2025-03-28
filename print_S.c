#include "main.h"

/**
 * print_custom_S - Prints a string with non printable characters converted
 *                  to \x followed by the ASCII code in uppercase hexadecimal.
 * @args: A list of arguments containing the string.
 *
 * Return: The number of characters printed.
 */
int print_custom_S(va_list args)
{
	char *s = va_arg(args, char *);
	int i, count = 0;
	unsigned char c;
	int high, low;
	char hex_digit;

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		c = s[i];
		if ((c > 0 && c < 32) || c >= 127)
		{
			count += buffered_putchar('\\');
			count += buffered_putchar('x');
			high = c / 16;
			low = c % 16;
			if (high < 10)
				hex_digit = high + '0';
			else
				hex_digit = high - 10 + 'A';
			count += buffered_putchar(hex_digit);
			if (low < 10)
				hex_digit = low + '0';
			else
				hex_digit = low - 10 + 'A';
			count += buffered_putchar(hex_digit);
		}
		else
		{
			count += buffered_putchar(c);
		}
	}
	return (count);
}

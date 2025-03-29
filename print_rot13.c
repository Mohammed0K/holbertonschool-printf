#include "main.h"

/**
 * print_rot13 - Prints the rot13'ed string.
 * @args: A list of arguments containing the string.
 *
 * Return: The number of characters printed.
 */
int print_rot13(va_list args)
{
	char *s = va_arg(args, char *);
	int i, count = 0;
	char c;

	if (!s)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		c = s[i];
		if (c >= 'A' && c <= 'Z')
			c = ((c - 'A' + 13) % 26) + 'A';
		else if (c >= 'a' && c <= 'z')
			c = ((c - 'a' + 13) % 26) + 'a';
		count += buffered_putchar(c);
	}
	return (count);
}

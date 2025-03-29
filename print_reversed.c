#include "main.h"

/**
 * print_reversed - Prints the reversed string.
 * @args: A list of arguments containing the string.
 *
 * Return: The number of characters printed.
 */
int print_reversed(va_list args)
{
	char *s = va_arg(args, char *);
	int len = 0, i, count = 0;

	if (!s)
		s = "(null)";
	while (s[len])
		len++;
	for (i = len - 1; i >= 0; i--)
		count += buffered_putchar(s[i]);
	return (count);
}

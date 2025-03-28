#include "main.h"

/**
 * print_char - Prints a single character.
 * @args: A list of arguments containing the character.
 *
 * Return: 1.
 */
int print_char(va_list args)
{
	int c = (char)va_arg(args, int);

	buffered_putchar(c);
	return (1);
}

/**
 * print_str - Prints a string.
 * @args: A list of arguments containing the string.
 *
 * Return: The number of characters printed.
 */
int print_str(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0, count = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		buffered_putchar(s[i]);
		count++;
		i++;
	}
	return (count);
}

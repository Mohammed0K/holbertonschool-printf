#include "main.h"

/**
 * print_char - Prints a single character.
 * @args: va_list containing the character.
 *
 * Return: 1.
 */
int print_char(va_list args)
{
	int c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_str - Prints a string.
 * @args: va_list containing the string.
 *
 * Return: number of characters printed.
 */
int print_str(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0, count = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		count++;
		i++;
	}
	return (count);
}

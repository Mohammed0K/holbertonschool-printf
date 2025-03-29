#include "main.h"
/**
 * is_printable - Checks if a character is printable.
 * @c: The character to check.
 *
 * Return: 1 if printable, 0 otherwise.
 */
int is_printable(char c)
{
	return (c >= 32 && c < 127);
}

/**
 * append_hexa_code - Appends the hexadecimal of non-printable character.
 * @c: The non-printable character.
 * @buffer: Buffer array.
 * @i: Index at which to start appending.
 *
 * Return: New index after appending.
 */
int append_hexa_code(char c, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map[(c / 16) % 16];
	buffer[i++] = map[c % 16];
	return (i);
}

/**
 * print_non_printable - Prints a string and replaces non-printable characters
 *                       with their hexadecimal codes.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, j = 0;
	char *str = va_arg(types, char *);

	(void)flags;
	(void)width;
	(void)precision;
	(void)size;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[j++] = str[i];
		else
			j = append_hexa_code(str[i], buffer, j);
		i++;
	}
	return (write(1, buffer, j));
}

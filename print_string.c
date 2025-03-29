#include "main.h"
/**
 * print_string - Prints a string.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length, i;
	char *str = va_arg(types, char *);

	(void)flags;
	(void)width;
	(void)size;
	if (str == NULL)
		str = "(null)";
	for (length = 0; str[length] != '\0'; length++)
		;
	if (precision >= 0 && precision < length)
		length = precision;
	for (i = 0; i < length; i++)
		buffer[i] = str[i];
	return (write(1, buffer, length));
}

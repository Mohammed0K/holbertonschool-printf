#include "main.h"
/**
 * print_rot13string - Prints a string encoded in ROT13.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Field width.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, j, count = 0;
	char *str = va_arg(types, char *);
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	(void)flags;
	(void)width;
	(void)precision;
	(void)size;
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; in[j] != '\0'; j++)
		{
			if (str[i] == in[j])
			{
				buffer[count++] = out[j];
				break;
			}
		}
		if (!in[j])
			buffer[count++] = str[i];
	}
	return (write(1, buffer, count));
}

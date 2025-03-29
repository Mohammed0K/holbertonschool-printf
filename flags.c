#include "main.h"

/**
 * handle_flags - Calculates active flags for formatting.
 * @format: The format string.
 * @i: Pointer to the current index in the format string.
 *
 * Return: The flags.
 */
int handle_flags(const char *format, int *i)
{
	int j, flags = 0;
	char flags_arr[] = { '+', ' ', '#', '0', '-' };
	int flags_arr_num[] = { FLAG_PLUS, FLAG_SPACE, FLAG_HASH, FLAG_ZERO, FLAG_MINUS };

	for (j = 0; flags_arr[j] != '\0'; j++)
	{
		if (format[*i + 1] == flags_arr[j])
		{
			flags |= flags_arr_num[j];
			(*i)++;
			j = -1;
		}
	}
	return (flags);
}

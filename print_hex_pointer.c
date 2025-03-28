#include "main.h"

/**
 * print_hex_pointer - Helper function to print a hexadecimal value.
 * @n: The unsigned integer representing the pointer.
 *
 * Return: The number of characters printed.
 */
int print_hex_pointer(uintptr_t n)
{
	int count = 0;
	char digit;

	if (n / 16)
		count += print_hex_pointer(n / 16);
	if (n % 16 < 10)
		digit = (n % 16) + '0';
	else
		digit = (n % 16) - 10 + 'a';
	buffered_putchar(digit);
	return (count + 1);
}

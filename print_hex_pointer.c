#include "main.h"

/**
 * print_hex_pointer - Helper function to print hexadecimal.
 * @n: The unsigned integer representing the pointer.
 *
 * Return: Number of characters printed.
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
	write(1, &digit, 1);
	return (count + 1);
}

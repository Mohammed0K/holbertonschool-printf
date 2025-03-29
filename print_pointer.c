#include "main.h"

/**
 * print_pointer - Prints a pointer value.
 * @ptr: The pointer to print.
 *
 * Return: The number of characters printed.
 */
int print_pointer(void *ptr)
{
	int count = 0;
	uintptr_t address;

	if (ptr == NULL)
	{
		count += buffered_putchar('(');
		count += buffered_putchar('n');
		count += buffered_putchar('i');
		count += buffered_putchar('l');
		count += buffered_putchar(')');
		return (count);
	}
	count += buffered_putchar('0');
	count += buffered_putchar('x');
	address = (uintptr_t)ptr;
	count += print_hex_pointer(address);
	return (count);
}

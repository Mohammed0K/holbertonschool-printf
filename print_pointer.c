#include "main.h"

/**
 * print_pointer - Prints a pointer value.
 * @ptr: The pointer to print.
 *
 * Return: Number of characters printed.
 */
int print_pointer(void *ptr)
{
	int count = 0;
	uintptr_t address;

	count += write(1, "0x", 2);
	address = (uintptr_t)ptr;
	count += print_hex_pointer(address);
	return (count);
}

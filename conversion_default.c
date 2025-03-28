#include "main.h"

/**
 * handle_default - Handles an unknown conversion specifier.
 * @specifier: The conversion specifier.
 *
 * Return: 2.
 */
int handle_default(char specifier)
{
	buffered_putchar('%');
	buffered_putchar(specifier);
	return (2);
}

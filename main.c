#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int len, len2;

	/* Test cases */
	len = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	_printf("Length:[%d]\n", len);
	printf("Length:[%d]\n", len2);

	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	_printf("Length:[%d]\n", len);
	printf("Length:[%d]\n", len2);

	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Length:[%d]\n", len);
	printf("Length:[%d]\n", len2);

	return (0);
}

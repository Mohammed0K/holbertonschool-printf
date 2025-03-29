#include "main.h"
/**
 * convert_size_number - Casts a number to the specified size.
 * @num: Number to be cast.
 * @size: Size specifier.
 *
 * Return: Cast number.
 */
long int convert_size_number(long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	if (size == SIZE_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts an unsigned number to the specified size.
 * @num: Number to be cast.
 * @size: Size specifier.
 *
 * Return: Cast number.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	if (size == SIZE_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}

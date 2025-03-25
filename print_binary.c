#include "main.h"
/**
 * print_binary - Converts an unsigned int to binary and prints it.
 * @n: The unsigned int to convert.
 *
 * Return: Number of characters printed.
 */
int print_binary(unsigned int n)
{
    int i = 0, count = 0;
    char buffer[32];
    char c;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    while (n > 0)
    {
        buffer[i++] = (n % 2) + '0';
        n /= 2;
    }
    while (i--)
    {
        c = buffer[i];
        write(1, &c, 1);
        count++;
    }
    return (count);
}

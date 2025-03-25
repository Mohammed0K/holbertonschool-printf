#include <stdint.h>
#include <unistd.h>
#include "main.h"

/**
 * print_unsigned_number - Prints an unsigned integer.
 * @n: The unsigned integer to print.
 *
 * Return: Number of digits printed.
 */
int print_unsigned_number(unsigned int n)
{
    int  count;
    char digit;

    count = 0;
    if (n / 10)
        count += print_unsigned_number(n / 10);
    digit = (n % 10) + '0';
    write(1, &digit, 1);
    return (count + 1);
}

/**
 * print_number - Prints an integer.
 * @n: The integer to print.
 *
 * Return: Number of characters printed.
 */
int print_number(int n)
{
    int           count;
    unsigned int  num;

    count = 0;
    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = -n;
    }
    else
    {
        num = n;
    }
    count += print_unsigned_number(num);
    return (count);
}

/**
 * print_octal - Prints an unsigned integer in octal notation.
 * @n: The unsigned integer.
 *
 * Return: Number of characters printed.
 */
int print_octal(unsigned int n)
{
    int  count;
    char digit;

    count = 0;
    if (n / 8)
        count += print_octal(n / 8);
    digit = (n % 8) + '0';
    write(1, &digit, 1);
    return (count + 1);
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal notation.
 * @n: The unsigned integer.
 * @uppercase: 0 for lowercase, 1 for uppercase.
 *
 * Return: Number of characters printed.
 */
int print_hex(unsigned int n, int uppercase)
{
    int  count;
    char digit;

    count = 0;
    if (n / 16)
        count += print_hex(n / 16, uppercase);
    if (n % 16 < 10)
        digit = (n % 16) + '0';
    else
    {
        if (uppercase)
            digit = (n % 16) - 10 + 'A';
        else
            digit = (n % 16) - 10 + 'a';
    }
    write(1, &digit, 1);
    return (count + 1);
}

/**
 * print_hex_pointer - Helper function to print an unsigned integer in hexadecimal.
 * @n: The unsigned integer representing the pointer.
 *
 * Return: Number of characters printed.
 */
int print_hex_pointer(uintptr_t n)
{
    int  count;
    char digit;

    count = 0;
    if (n / 16)
        count += print_hex_pointer(n / 16);
    if (n % 16 < 10)
        digit = (n % 16) + '0';
    else
        digit = (n % 16) - 10 + 'a';
    write(1, &digit, 1);
    return (count + 1);
}

/**
 * print_pointer - Prints a pointer value.
 * @ptr: The pointer to print.
 *
 * Return: Number of characters printed.
 */
int print_pointer(void *ptr)
{
    int         count;
    uintptr_t   address;

    count = 0;
    count += write(1, "0x", 2);
    address = (uintptr_t)ptr;
    count += print_hex_pointer(address);
    return (count);
}

/**
 * handle_conversion - Handles conversion specifiers.
 * @specifier: The conversion specifier.
 * @args: The va_list containing the arguments.
 *
 * Return: Number of characters printed for the conversion.
 */
int handle_conversion(char specifier, va_list args)
{
    int count;

    count = 0;
    if (specifier == 'c')
    {
        char c;

        c = (char)va_arg(args, int);
        write(1, &c, 1);
        count++;
    }
    else if (specifier == 's')
    {
        char *s;
        int   j;

        s = va_arg(args, char *);
        j = 0;
        if (!s)
            s = "(null)";
        while (s[j])
        {
            write(1, &s[j], 1);
            count++;
            j++;
        }
    }
    else if (specifier == '%')
    {
        write(1, "%", 1);
        count++;
    }
    else if (specifier == 'd' || specifier == 'i')
    {
        int num;

        num = va_arg(args, int);
        count += print_number(num);
    }
    else if (specifier == 'u')
    {
        unsigned int num;

        num = va_arg(args, unsigned int);
        count += print_unsigned_number(num);
    }
    else if (specifier == 'o')
    {
        unsigned int num;

        num = va_arg(args, unsigned int);
        count += print_octal(num);
    }
    else if (specifier == 'x')
    {
        unsigned int num;

        num = va_arg(args, unsigned int);
        count += print_hex(num, 0);
    }
    else if (specifier == 'X')
    {
        unsigned int num;

        num = va_arg(args, unsigned int);
        count += print_hex(num, 1);
    }
    else if (specifier == 'p')
    {
        void *ptr;

        ptr = va_arg(args, void *);
        count += print_pointer(ptr);
    }
    else
    {
        write(1, "%", 1);
        write(1, &specifier, 1);
        count += 2;
    }
    return (count);
}

/**
 * process_format - Processes the format string and prints the output.
 * @format: The format string.
 * @args: The va_list containing the arguments.
 *
 * Return: Total number of characters printed, or -1 on error.
 */
int process_format(const char *format, va_list args)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                return (-1);
            count += handle_conversion(format[i], args);
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    return (count);
}


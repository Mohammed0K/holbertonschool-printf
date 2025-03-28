#include "main.h"
/**
 * _printf.c
 * _printf - Produces output according to a format.
 * Return: Total number of characters printed.
 */
#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count;

    if (!format)
        return (-1);
    va_start(args, format);
    count = process_format(format, &args);
    va_end(args);
    return (count);
}

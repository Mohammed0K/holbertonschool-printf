#include "main.h"
/**
 * process_format.c
 * process_format - Processes the format string and prints the output.
 * Return: Total number of characters printed, or -1 on error.
 */
#include "main.h"
#include <unistd.h>

int process_format(const char *format, va_list *args)
{
    int i, count, printed;
    char buffer[1024];
    int buff_index;

    i = 0;
    count = 0;
    buff_index = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (buff_index > 0)
            {
                write(1, buffer, buff_index);
                buff_index = 0;
            }
            i++;
            if (!format[i])
                return (-1);
            printed = handle_conversion(format[i], args);
            if (printed < 0)
                return (-1);
            count += printed;
        }
        else
        {
            buffer[buff_index++] = format[i];
            if (buff_index == 1024)
            {
                write(1, buffer, buff_index);
                buff_index = 0;
            }
            count++;
        }
        i++;
    }
    if (buff_index > 0)
        write(1, buffer, buff_index);
    return (count);
}

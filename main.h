#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
/* Function Prototype */
int _printf(const char *format, ...);
int process_format(const char *format, va_list args);
int handle_conversion(char specifier, va_list args);
int print_number(int n);
int print_unsigned_number(unsigned int n);
#endif


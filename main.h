#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
/* Function Prototype */
int print_hex_pointer(uintptr_t n);
int _printf(const char *format, ...);
int process_format(const char *format, va_list args);
int handle_conversion(char specifier, va_list args);
int print_number(int n);
int print_unsigned_number(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_pointer(void *ptr);

#endif

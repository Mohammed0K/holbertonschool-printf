#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>


/* Function Prototype */
int print_unsigned_number(unsigned int n);
int print_number(int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_hex_pointer(uintptr_t n);
int print_pointer(void *ptr);
int process_format(const char *format, va_list args);
int _printf(const char *format, ...);
int handle_conversion(char specifier, va_list args);
/* Prototypes for helper functions */
int print_char(va_list args);
int print_str(va_list args);
int handle_default(char specifier);
int print_binary(unsigned int n);
#endif

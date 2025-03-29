#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 1024

/* Flag definitions */
#define FLAG_PLUS  (1 << 0)
#define FLAG_SPACE (1 << 1)
#define FLAG_HASH  (1 << 2)

/* Length modifier definitions */
#define LENGTH_NONE 0
#define LENGTH_H    1
#define LENGTH_L    2

int _printf(const char *format, ...);
int process_format(const char *format, va_list *args);
int handle_conversion(char specifier, va_list *args, int flags, int length);
int print_char(va_list args);
int print_str(va_list args);
int handle_default(char specifier);
int print_number(int n);
int print_unsigned_number(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_hex_pointer(uintptr_t n);
int print_pointer(void *ptr);
int print_binary(unsigned int n);
int print_custom_S(va_list args);

/* New functions for long modifiers */
int print_long_number(long int n);
int print_unsigned_long_number(unsigned long int n);
int print_octal_long(unsigned long int n);
int print_hex_long(unsigned long int n, int uppercase);

/* Buffered output functions */
int buffered_putchar(char c);
void flush_buffer(void);

#endif

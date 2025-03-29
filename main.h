#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/**
 * struct fmt - Matches a format specifier with its corresponding function.
 * @fmt: The format specifier.
 * @fn: Pointer to the printing function associated with @fmt.
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char *, int, int, int, int);
} fmt_t;

#define FLAG_PLUS 1
#define FLAG_SPACE 2
#define FLAG_HASH 4
#define FLAG_ZERO 8
#define FLAG_MINUS 16

#define SIZE_LONG 2
#define SIZE_SHORT 1

/* Function prototypes */
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hex(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_HEX(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

int handle_flags(const char *format, int *i);
int handle_width(const char *format, int *i, va_list list);
int handle_precision(const char *format, int *i, va_list list);
int handle_size(const char *format, int *i);

int is_printable(char c);
int append_hexa_code(char c, char buffer[], int i);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif

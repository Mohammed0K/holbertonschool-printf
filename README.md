# printf

- ### A custom implementation of the C standard `printf` function.



## DESCRIPTION

- The _printf function processes a format string along with a variable number of arguments to produce formatted output. It supports:

### Basic Conversion Specifiers

- Print a character `%c`
- Print a string `%s`
- Print a percent sign `%%`


### Integer Conversion Specifiers

- Print integers `%d` and `%d`


### Custom Conversion Specifiers

- Print an unsigned integer in binary `%b`
- Print a string, with non-printable characters represented as `%x` followed by their two-digit uppercase hexadecimal value `%S`
- Print the reversed string `%r`
- Print the ROT13 encoded string `%R`


### Additional Numeric Conversion Specifiers

- Print unsigned integers `%u`
- Print numbers in octal `%o`
- Print numbers in hexadecimal (lowercase and uppercase, respectively) `%x` and `%X`


### Pointer Conversion Specifier

- Print a pointer address `%p`


### Formatting Options:

- Flags: Supports flags such as `+`, space, and `#` for numeric conversions.


- Field Width & Precision: Implements field width and precision for formatting numbers and strings.

- Length Modifiers: Supports l and h for applicable conversion specifiers.

- Buffering: Uses a local buffer of 1024 characters to reduce the number of calls to write.

- Overall, _printf closely mimics the behavior of the standard printf function while incorporating additional custom features.
  

## RETURN VALUE

- On Success: Returns the total number of characters printed (excluding the terminating null byte).

- On Error: Returns a negative value if an error occurs during printing.

## Header file

- `main.h`

These conversion specifiers provide flexibility in formatting and displaying different types of data using the `_printf` function.


---

## Usage

- All the files are to be compiled on Ubuntu 22.04 Compile your code with gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c Include the "main.h" header file on the functions using the _printf().


- If you have a test file (e.g., `main.c`), compile and run it as follows:



```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c -o main
./main
```

---

## Example (main.c)

```
#include "main.h"

int main(void)
{
    _printf("Character: %c\nString: %s\nPercent: %%\n", 'A', "Hello");
    _printf("Integer: %d\n", 123);
    _printf("Binary: %b\n", 98);
    _printf("Unsigned: %u\n", 300);
    _printf("Octal: %o\n", 100);
    _printf("Hexadecimal: %x\n", 255);
    _printf("Pointer: %p\n", (void *)main);
    _printf("Non-printable: %S\n", "Best\nSchool");
    _printf("Reversed: %r\n", "Hello");
    _printf("ROT13: %R\n", "Hello");
    return (0);
}
```

---

## NAME

- _printf - A custom implementation of the C standard printf function.

---

## SYNOPSIS

```
int _printf(const char *format, ...);
```

## Example:

```
_printf("Character: %c, String: %s, Number: %d\n", 'A', "Hello", 123);
```

---

## EXAMPLES

### Basic Output:
```
_printf("Hello, World!\n");
```
### Output:
```
Hello, World!
```
### Multiple Conversion Specifiers:
```
_printf("Name: %s, Age: %d, Grade: %c\n", "Alice", 20, 'A');
```
### Output:
```
Name: Alice, Age: 20, Grade: A
```
### Custom Specifiers:
```
_printf("Binary: %b\n", 98);             // Output: 1100010
_printf("Non-printable: %S\n", "Best\nSchool");  // Output: Best\x0ASchool
_printf("Reversed: %r\n", "Hello");        // Output: olleH
_printf("ROT13: %R\n", "Hello");           // Output: Uryyb
```
---
## FUNCTIONS AND PROTOTYPES
- Below is an overview of key functions and their purposes. (Adjust function names if your implementation differs.)

_printf
```
int _printf(const char *format, ...);
```

- Purpose: Main entry point; parses the format string and processes conversion specifiers.

- Return Value: Total number of characters printed, or a negative value on error.

---

## Helper Functions for Conversion Specifiers:

- `int print_char(va_list args); – Handles %c`.

- `int print_string(va_list args); – Handles %s`.

- `int print_int(va_list args); – Handles %d and %i`.

- `int print_unsigned(va_list args); – Handles %u`.

- `int print_octal(va_list args); – Handles %o`.

- `int print_hex(va_list args); – Handles %x`.

- `int print_HEX(va_list args); – Handles %X`.

- `int print_binary(va_list args); – Handles %b`.

- `int print_pointer(va_list args); – Handles %p`.

- `int print_S(va_list args); – Handles %S (non-printable characters)`.

- `int print_reverse(va_list args); – Handles %r (reversed string)`.

- `int print_ROT13(va_list args); – Handles %R (ROT13 encoding)`.


### Formatting Helpers:

- Functions such as handle_flags, handle_width, handle_precision, etc., manage flags, field width, precision, and length modifiers.

---

## MAN PAGE

- A manual page for the _printf function is provided in the file `man_3_printf`. To view it locally:

```
man ./man_3_printf
```

---

## BUGS
- No known bugs at the moment. Please report any bugs or issues using the project repository.

---

## SEE ALSO

man_3_printf

---

## AUTHORS

- Mohammed Al-Qabas

mohammed.alqabas@holbertonstudents.com

- Abrar Al-Mukhlifi

abrar.almukhlifi@holbertonstudents.com

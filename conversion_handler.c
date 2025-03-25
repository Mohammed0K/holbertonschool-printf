#include "main.h"

/**
 * print_unsigned_number - Prints an unsigned integer.
 * @n: The unsigned integer to print.
 *
 * Return: Number of digits printed.
 */
int print_unsigned_number(unsigned int n)
{
	int count;
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
	int count;
	unsigned int num;

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
		int j;
		
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
 * Return: Total number of characters printed.
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
			break;
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

#include "main.h"

/**
 * handle_conversion - Handles conversion specifiers with flag, length,
 * field width, and precision support.
 * @specifier: The conversion specifier.
 * @args: Pointer to the list of arguments.
 * @flags: Bitwise OR of flags.
 * @length: Length modifier.
 * @width: Field width.
 * @precision: Precision value (-1 if not specified).
 *
 * Return: Number of characters printed.
 */
int handle_conversion(char specifier, va_list *args, int flags, int length,
		      int width, int precision)
{
	int count = 0, i, pad = 0;
	char temp[50];
	int len = 0, num_is_zero = 0;
	long num = 0;
	int negative = 0;
	int sign = 0;

	if (specifier == 'd' || specifier == 'i')
	{
		if (length == LENGTH_L)
			num = va_arg(*args, long int);
		else
			num = va_arg(*args, int);
		if (num < 0)
		{
			negative = 1;
			num = -num;
		}
		if (num == 0)
		{
			temp[len++] = '0';
			num_is_zero = 1;
		}
		else
		{
			while (num)
			{
				temp[len++] = (num % 10) + '0';
				num /= 10;
			}
		}
		if (precision == 0 && num_is_zero)
			len = 0;
		if (negative)
			sign = 1;
		else if (flags & FLAG_PLUS)
			sign = 1;
		else if (flags & FLAG_SPACE)
			sign = 1;
		{
			int prec_zeros = (precision > len) ? precision - len : 0;
			int num_total = sign + ((len > precision) ? len : precision);

			pad = (width > num_total) ? width - num_total : 0;
			if (!(flags & FLAG_MINUS))
			{
				if ((flags & FLAG_ZERO) && (precision < 0))
				{
					for (i = 0; i < pad; i++)
					{
						buffered_putchar('0');
						count++;
					}
				}
				else
				{
					for (i = 0; i < pad; i++)
					{
						buffered_putchar(' ');
						count++;
					}
				}
			}
			if (negative)
			{
				buffered_putchar('-');
				count++;
			}
			else if (flags & FLAG_PLUS)
			{
				buffered_putchar('+');
				count++;
			}
			else if (flags & FLAG_SPACE)
			{
				buffered_putchar(' ');
				count++;
			}
			for (i = 0; i < prec_zeros; i++)
			{
				buffered_putchar('0');
				count++;
			}
			for (i = len - 1; i >= 0; i--)
			{
				buffered_putchar(temp[i]);
				count++;
			}
			if (flags & FLAG_MINUS)
			{
				for (i = 0; i < pad; i++)
				{
					buffered_putchar(' ');
					count++;
				}
			}
			return (count);
		}
	}
	else if (specifier == 'u')
	{
		unsigned long unum = 0;

		if (length == LENGTH_L)
			unum = va_arg(*args, unsigned long int);
		else if (length == LENGTH_H)
			unum = (unsigned short int)va_arg(*args, int);
		else
			unum = va_arg(*args, unsigned int);
		if (unum == 0)
		{
			temp[len++] = '0';
			num_is_zero = 1;
		}
		else
		{
			while (unum)
			{
				temp[len++] = (unum % 10) + '0';
				unum /= 10;
			}
		}
		if (precision == 0 && num_is_zero)
			len = 0;
		{
			int prec_zeros = (precision > len) ? precision - len : 0;
			int num_total = (len > precision) ? len : precision;

			pad = (width > num_total) ? width - num_total : 0;
			if (!(flags & FLAG_MINUS))
			{
				if ((flags & FLAG_ZERO) && (precision < 0))
				{
					for (i = 0; i < pad; i++)
					{
						buffered_putchar('0');
						count++;
					}
				}
				else
				{
					for (i = 0; i < pad; i++)
					{
						buffered_putchar(' ');
						count++;
					}
				}
			}
			for (i = 0; i < prec_zeros; i++)
			{
				buffered_putchar('0');
				count++;
			}
			for (i = len - 1; i >= 0; i--)
			{
				buffered_putchar(temp[i]);
				count++;
			}
			if (flags & FLAG_MINUS)
			{
				for (i = 0; i < pad; i++)
				{
					buffered_putchar(' ');
					count++;
				}
			}
			return (count);
		}
	}
	return (handle_default(specifier));
}

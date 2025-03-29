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
    int count = 0, i, pad = 0, zeros = 0, num_len = 0, total = 0;
    char num_str[50];
    int sign_len = 0;
    char sign_char = '\0';

    if (specifier == 's')
    {
        char *str = va_arg(*args, char *);
        int str_len = 0;
        if (!str)
            str = "(null)";
        while (str[str_len])
            str_len++;
        if (precision >= 0 && precision < str_len)
            str_len = precision;
        pad = (width > str_len) ? width - str_len : 0;
        if (!(flags & FLAG_MINUS))
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        for (i = 0; i < str_len; i++) { buffered_putchar(str[i]); count++; }
        if (flags & FLAG_MINUS)
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        return count;
    }
    else if (specifier == 'c')
    {
        /* معالجة حرف مع دعم العرض */
        char ch = (char)va_arg(*args, int);
        pad = (width > 1) ? width - 1 : 0;
        if (!(flags & FLAG_MINUS))
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        /* إذا كان الحرف هو '\0'، يتم احتسابه في الطول دون طباعته */
        if (ch)
            buffered_putchar(ch), count++;
        else
            count++; /* يُحتسب كحرف حتى وإن لم يظهر */
        if (flags & FLAG_MINUS)
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        return count;
    }
    else if (specifier == '%')
    {
        buffered_putchar('%');
        return 1;
    }
    else if (specifier == 'd' || specifier == 'i')
    {
        long num;
        if (length == LENGTH_L)
            num = va_arg(*args, long int);
        else
            num = va_arg(*args, int);
        if (num < 0)
        {
            sign_char = '-';
            sign_len = 1;
            num = -num;
        }
        else if (flags & FLAG_PLUS)
        {
            sign_char = '+';
            sign_len = 1;
        }
        else if (flags & FLAG_SPACE)
        {
            sign_char = ' ';
            sign_len = 1;
        }
        i = 0;
        if (num == 0)
            num_str[i++] = '0';
        else
            while (num)
            {
                num_str[i++] = (num % 10) + '0';
                num /= 10;
            }
        num_len = i;
        if (precision == 0 && num_len == 1 && num_str[0] == '0')
            num_len = 0;
        if (precision >= 0)
            zeros = (precision > num_len) ? precision - num_len : 0;
        else if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS) &&
                 width > (sign_len + num_len))
            zeros = width - sign_len - num_len;
        total = sign_len + zeros + num_len;
        pad = (width > total) ? width - total : 0;
        if (!(flags & FLAG_MINUS))
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        if (sign_len) { buffered_putchar(sign_char); count++; }
        for (i = 0; i < zeros; i++) { buffered_putchar('0'); count++; }
        for (i = num_len - 1; i >= 0; i--) { buffered_putchar(num_str[i]); count++; }
        if (flags & FLAG_MINUS)
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        return count;
    }
    else if (specifier == 'u')
    {
        unsigned long unum;
        if (length == LENGTH_L)
            unum = va_arg(*args, unsigned long int);
        else if (length == LENGTH_H)
            unum = (unsigned short int)va_arg(*args, int);
        else
            unum = va_arg(*args, unsigned int);
        i = 0;
        if (unum == 0)
            num_str[i++] = '0';
        else
            while (unum)
            {
                num_str[i++] = (unum % 10) + '0';
                unum /= 10;
            }
        num_len = i;
        if (precision == 0 && num_len == 1 && num_str[0] == '0')
            num_len = 0;
        if (precision >= 0)
            zeros = (precision > num_len) ? precision - num_len : 0;
        else if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS) &&
                 width > num_len)
            zeros = width - num_len;
        total = zeros + num_len;
        pad = (width > total) ? width - total : 0;
        if (!(flags & FLAG_MINUS))
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        for (i = 0; i < zeros; i++) { buffered_putchar('0'); count++; }
        for (i = num_len - 1; i >= 0; i--) { buffered_putchar(num_str[i]); count++; }
        if (flags & FLAG_MINUS)
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        return count;
    }
    else if (specifier == 'o')
    {
        unsigned long unum;
        int prefix = 0;
        if (length == LENGTH_L)
            unum = va_arg(*args, unsigned long int);
        else if (length == LENGTH_H)
            unum = (unsigned short int)va_arg(*args, int);
        else
            unum = va_arg(*args, unsigned int);
        i = 0;
        if (unum == 0)
            num_str[i++] = '0';
        else
            while (unum)
            {
                num_str[i++] = (unum % 8) + '0';
                unum /= 8;
            }
        num_len = i;
        if (precision == 0 && num_len == 1 && num_str[0] == '0')
            num_len = 0;
        if ((flags & FLAG_HASH) && (num_len > 0) && num_str[0] != '0')
            prefix = 1;
        if (precision >= 0)
            zeros = (precision > num_len) ? precision - num_len : 0;
        else if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS) &&
                 width > (prefix + num_len))
            zeros = width - prefix - num_len;
        total = prefix + zeros + num_len;
        pad = (width > total) ? width - total : 0;
        if (!(flags & FLAG_MINUS))
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        if (prefix) { buffered_putchar('0'); count++; }
        for (i = 0; i < zeros; i++) { buffered_putchar('0'); count++; }
        for (i = num_len - 1; i >= 0; i--) { buffered_putchar(num_str[i]); count++; }
        if (flags & FLAG_MINUS)
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        return count;
    }
    else if (specifier == 'x' || specifier == 'X')
    {
        unsigned long unum;
        int prefix = 0;
        char xbase = (specifier == 'x') ? 'a' : 'A';
        if (length == LENGTH_L)
            unum = va_arg(*args, unsigned long int);
        else if (length == LENGTH_H)
            unum = (unsigned short int)va_arg(*args, int);
        else
            unum = va_arg(*args, unsigned int);
        i = 0;
        if (unum == 0)
            num_str[i++] = '0';
        else
            while (unum)
            {
                int digit = unum % 16;
                if (digit < 10)
                    num_str[i++] = digit + '0';
                else
                    num_str[i++] = digit - 10 + xbase;
                unum /= 16;
            }
        num_len = i;
        if (precision == 0 && num_len == 1 && num_str[0] == '0')
            num_len = 0;
        if ((flags & FLAG_HASH) && num_len > 0 &&
            !(num_len == 1 && num_str[0] == '0'))
            prefix = 2;
        if (precision >= 0)
            zeros = (precision > num_len) ? precision - num_len : 0;
        else if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS) &&
                 width > (prefix + num_len))
            zeros = width - prefix - num_len;
        total = prefix + zeros + num_len;
        pad = (width > total) ? width - total : 0;
        if (!(flags & FLAG_MINUS))
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        if (prefix == 2)
        {
            buffered_putchar('0');
            buffered_putchar((specifier == 'x') ? 'x' : 'X');
            count += 2;
        }
        for (i = 0; i < zeros; i++) { buffered_putchar('0'); count++; }
        for (i = num_len - 1; i >= 0; i--) { buffered_putchar(num_str[i]); count++; }
        if (flags & FLAG_MINUS)
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        return count;
    }
    else if (specifier == 'p')
    {
        void *ptr = va_arg(*args, void *);
        int j;
        char temp[50];

        if (!ptr)
        {
            buffered_putchar('(');
            buffered_putchar('n');
            buffered_putchar('i');
            buffered_putchar('l');
            buffered_putchar(')');
            return 5;
        }
        /* تحويل العنوان إلى سلسلة سداسية عشرية */
        {
            unsigned long addr = (unsigned long)ptr;
            i = 0;
            if (addr == 0)
                temp[i++] = '0';
            else
            {
                while (addr)
                {
                    int digit = addr % 16;
                    temp[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
                    addr /= 16;
                }
            }
            num_len = i;
            /* عكس السلسلة */
            for (j = 0; j < num_len; j++)
                num_str[j] = temp[num_len - j - 1];
            num_str[num_len] = '\0';
        }
        total = 2 + num_len; /* "0x" + الرقم */
        pad = (width > total) ? width - total : 0;
        if (!(flags & FLAG_MINUS))
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        buffered_putchar('0');
        buffered_putchar('x');
        count += 2;
        for (i = 0; i < num_len; i++)
        {
            buffered_putchar(num_str[i]);
            count++;
        }
        if (flags & FLAG_MINUS)
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        return count;
    }
    else if (specifier == 'b')
    {
        unsigned int num = va_arg(*args, unsigned int);
        i = 0;
        if (num == 0)
            num_str[i++] = '0';
        else
            while (num)
            {
                num_str[i++] = (num % 2) + '0';
                num /= 2;
            }
        num_len = i;
        pad = (width > num_len) ? width - num_len : 0;
        if (!(flags & FLAG_MINUS))
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        for (i = num_len - 1; i >= 0; i--) { buffered_putchar(num_str[i]); count++; }
        if (flags & FLAG_MINUS)
            for (i = 0; i < pad; i++) { buffered_putchar(' '); count++; }
        return count;
    }
    else if (specifier == 'S')
    {
        char *str = va_arg(*args, char *);
        int j = 0;
        if (!str)
            str = "(null)";
        while (str[j])
        {
            if ((str[j] > 0 && str[j] < 32) || str[j] >= 127)
            {
                buffered_putchar('\\');
                buffered_putchar('x');
                {
                    int high = str[j] / 16;
                    int low = str[j] % 16;
                    buffered_putchar((high < 10) ? high + '0' : high - 10 + 'A');
                    buffered_putchar((low < 10) ? low + '0' : low - 10 + 'A');
                    count += 4;
                }
            }
            else
            {
                buffered_putchar(str[j]);
                count++;
            }
            j++;
        }
        return count;
    }
    else if (specifier == 'r')
    {
        char *str = va_arg(*args, char *);
        int j, cnt = 0;
        if (!str)
            str = "(null)";
        for (j = 0; str[j]; j++);
        for (j = j - 1; j >= 0; j--)
        {
            buffered_putchar(str[j]);
            cnt++;
        }
        return cnt;
    }
    else if (specifier == 'R')
    {
        char *str = va_arg(*args, char *);
        int j, cnt = 0;
        char c;
        if (!str)
            str = "(null)";
        for (j = 0; str[j]; j++)
        {
            c = str[j];
            if (c >= 'A' && c <= 'Z')
                c = ((c - 'A' + 13) % 26) + 'A';
            else if (c >= 'a' && c <= 'z')
                c = ((c - 'a' + 13) % 26) + 'a';
            buffered_putchar(c);
            cnt++;
        }
        return cnt;
    }
    return handle_default(specifier);
}

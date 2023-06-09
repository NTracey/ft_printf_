#include "ft_printf.h"

void handle_format_specifier(const char *format, va_list args)
{
    if (*format == 'c' || *format == '%')
    {
        int ch = va_arg(args, int);
        _putchar((char)ch);
    }
    else if (*format == 's')
    {
        char *str = va_arg(args, char *);
        _putstr(str);
    }
    else if (*format == 'd' || *format == 'i')
    {
        int num = va_arg(args, int);
        _dec_int(num);
    }
    else if (*format == 'u')
    {
        int num = va_arg(args, int);
        _unsigned_decimal(num);
    }
    else if (*format == 'x' || *format == 'X')
    {
        unsigned int decimal_number = va_arg(args, unsigned int);
        _hex(decimal_number, *format == 'x');
    }
}

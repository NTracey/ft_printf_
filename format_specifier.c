#include "ft_printf.h"

void handle_format_specifier(const char *format, va_list args)
{
    if (*format == 'c')
    {
        int ch = va_arg(args, int);
        ft_putchar((char)ch);
    }
    else if (*format == '%')
    {
        int ch = va_arg(args, int);
        ft_percent((char)ch);
    }
    else if (*format == 's')
    {
        char *str = va_arg(args, char *);
        ft_putstr(str);
    }
    else if (*format == 'd' || *format == 'i')
    {
        int num = va_arg(args, int);
        ft_dec_int(num);
    }
    else if (*format == 'u')
    {
        int num = va_arg(args, int);
        ft_unsigned_decimal(num);
    }
    else if (*format == 'x' || *format == 'X')
    {
        unsigned int num = va_arg(args, unsigned int);
        ft_hex(num, *format == 'x');
    }
    else if (*format == 'p')
    {
        void* num = va_arg(args, void*);
        ft_pointer(num);
    }
}

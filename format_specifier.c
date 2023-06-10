#include "ft_printf.h"

void handle_format_specifier(const char *format, va_list args)
{

    /*
        void *ptr = va_arg(args, void *);
        if (ptr == NULL)
            ft_putstr('nill);

    */
    if (*format == 'c' || *format == '%')
    {
        int ch = va_arg(args, int);
        ft_putchar((char)ch);
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
        unsigned int num = va_arg(args, unsigned long int);
        // fix this code
        ft_hex(num, *format == 'x');
    }
    else if (*format == 'p')
    {
        unsigned int num = va_arg(args, unsigned long int);
        // fix this line
        ft_pointer(num);
    }
}

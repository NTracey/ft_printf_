#include "../ft_printf.h"

int format_specifier(const char *format, va_list args)
{
    int char_count;

    char_count = 0;
    if (*format == 'c')
        char_count += ft_putchar((char)va_arg(args, int));
    else if (*format == '%')
        char_count += ft_percent();
    else if (*format == 's')
        char_count += ft_putstr(va_arg(args, char *));
    else if (*format == 'd' || *format == 'i')
        char_count += ft_dec_int(va_arg(args, int));
    else if (*format == 'u')
        char_count += ft_unsigned_decimal(va_arg(args, int));
    else if (*format == 'x' || *format == 'X')
        char_count += ft_hex(va_arg(args, unsigned int), *format == 'x');
    else if (*format == 'p')
        char_count += ft_pointer(va_arg(args, void *));

    return (char_count);
}

// int format_specifier(const char *format, va_list args)
// {
//     int char_count = 0;

//     if (*format == 'c')
//     {
//         int ch = va_arg(args, int);
//         ft_putchar((char)ch);
//         char_count++;
//     }
//     else if (*format == '%')
//     {
//         ft_percent();
//         char_count++;
//     }
//     else if (*format == 's')
//     {
//         char *str = va_arg(args, char *);
//         char_count += ft_putstr(str);
//     }
//     else if (*format == 'd' || *format == 'i')
//     {
//         int num = va_arg(args, int);
//         char_count += ft_dec_int(num);
//     }
//     else if (*format == 'u')
//     {
//         int num = va_arg(args, int);
//         char_count += ft_unsigned_decimal(num);
//     }
//     else if (*format == 'x' || *format == 'X')
//     {
//         unsigned int num = va_arg(args, unsigned int);
//         char_count += ft_hex(num, *format == 'x');
//     }
//     else if (*format == 'p')
//     {
//         void *num = va_arg(args, void *);
//         char_count += ft_pointer(num);
//     }

//     return char_count;
// }

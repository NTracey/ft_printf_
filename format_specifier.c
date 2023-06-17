#include "ft_printf.h"
// void format_specifier(const char *format, va_list args)
// {
//     // If the format specifier is 'c', 
//     // it retrieves the next argument as an int using va_arg 
//     // and passes it to the ft_putchar function, which prints a character.
//     if (*format == 'c')
//         ft_putchar((char)va_arg(args, int));
//     else if (*format == '%')
//         ft_percent();
//     else if (*format == 's')
//         ft_putstr(va_arg(args, char *));
//     else if (*format == 'd' || *format == 'i')
//         ft_dec_int(va_arg(args, int));
//     else if (*format == 'u')
//         ft_unsigned_decimal(va_arg(args, int));
//     else if (*format == 'x' || *format == 'X')
//         ft_hex(va_arg(args, unsigned int), *format == 'x');
//     else if (*format == 'p')
//     {
//         void *num = va_arg(args, void *);
//         ft_pointer(num);
//     }
// }

// void format_specifier(const char *format, va_list args)
// {
//     if (*format == 'c')
//     {
//         int ch = va_arg(args, int);
//         ft_putchar((char)ch);
//     }
//     else if (*format == '%')
//     {
//         ft_percent();
//     }
//     else if (*format == 's')
//     {
//         char *str = va_arg(args, char *);
//         ft_putstr(str);
//     }
//     else if (*format == 'd' || *format == 'i')
//     {
//         int num = va_arg(args, int);
//         ft_dec_int(num);
//     }
//     else if (*format == 'u')
//     {
//         int num = va_arg(args, int);
//         ft_unsigned_decimal(num);
//     }
//     else if (*format == 'x' || *format == 'X')
//     {
//         unsigned int num = va_arg(args, unsigned int);
//         ft_hex(num, *format == 'x');
//     }
//     else if (*format == 'p')
//     {
//         void* num = va_arg(args, void*);
//         ft_pointer(num);
//     }
// }

// int format_specifier(const char *format, va_list args)
// {
// //     int char_count = 0;
// // while (char_count)
// // {
//     if (*format == 'c')
//     {
//         int ch = va_arg(args, int);
//         ft_putchar((char)ch);
//     }
//     else if (*format == '%')
//     {
//         ft_percent();
//     }
//     else if (*format == 's')
//     {
//         char *str = va_arg(args, char *);
//         ft_putstr(str);
//     }
//     else if (*format == 'd' || *format == 'i')
//     {
//         int num = va_arg(args, int);
//         ft_dec_int(num);
//     }
//     else if (*format == 'u')
//     {
//         int num = va_arg(args, int);
//         ft_unsigned_decimal(num);
//     }
//     else if (*format == 'x' || *format == 'X')
//     {
//         unsigned int num = va_arg(args, unsigned int);
//         ft_hex(num, *format == 'x');
//     }
//     else if (*format == 'p')
//     {
//         void *num = va_arg(args, void *);
//         ft_pointer(num);
//     }
//     // char_count++;
// // }
// // return (char_count);
// }
int format_specifier(const char *format, va_list args)
{
    int char_count = 0;

    if (*format == 'c')
    {
        int ch = va_arg(args, int);
        ft_putchar((char)ch);
        char_count++;
    }
    else if (*format == '%')
    {
        ft_percent();
        char_count++;
    }
    else if (*format == 's')
    {
        char *str = va_arg(args, char *);
        char_count += ft_putstr(str);
    }
    else if (*format == 'd' || *format == 'i')
    {
        int num = va_arg(args, int);
        char_count += ft_dec_int(num);
    }
    else if (*format == 'u')
    {
        int num = va_arg(args, int);
        char_count += ft_unsigned_decimal(num);
    }
    else if (*format == 'x' || *format == 'X')
    {
        unsigned int num = va_arg(args, unsigned int);
        char_count += ft_hex(num, *format == 'x');
    }


    return char_count;
}

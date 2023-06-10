#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int convert_to_ascii(unsigned long int decimal_number, int lowercase)
{
    int i;
    int remainder;
    char hexa_num[100];

    i = 0;
    if (decimal_number == 0)
        hexa_num[i++] = '0';
    else // handles positive decimal numbers
    {
        while (decimal_number != 0)
        {
            remainder = decimal_number % 16;
            if (remainder < 10)
                hexa_num[i++] = remainder + '0'; // Convert to ASCII character
            else
                hexa_num[i++] = remainder + (lowercase ? 'a' : 'A') - 10;
            decimal_number = decimal_number / 16;
        }
    }
    while (--i >= 0) // Print the hex number in reverse order
        ft_putchar(hexa_num[i]);
    return 0;
}

void ft_putstr(char *str)
{
    int i = 0;
    if (str == NULL)
        ft_putstr("(null)");
    else
    {
        while (str[i] != '\0')
        {
            write(1, &str[i], 1);
            i++;
        }
    }
}

void ft_pointer(const void *ptr)
{
    if (ptr == NULL)
        ft_putstr("(nil)");
    else
    {
        unsigned long int decimal_number = (unsigned long int)ptr;
        // ft_putchar('0');
        // ft_putchar('x');
        ft_putstr("0x");
        convert_to_ascii(decimal_number, 1);
    }
}

void handle_format_specifier(const char *format, va_list args)
{
    if (*format == 'c')
        ft_putchar((char)va_arg(args, int));
    // else if (*format == '%')
    //     ft_percent((char)va_arg(args, int));
    else if (*format == 's')
        ft_putstr(va_arg(args, char *));
    // else if (*format == 'd' || *format == 'i')
    //     ft_dec_int(va_arg(args, int));
    // else if (*format == 'u')
    //     ft_unsigned_decimal(va_arg(args, int));
    // else if (*format == 'x' || *format == 'X')
        // ft_hex(va_arg(args, unsigned int), *format == 'x');
    else if (*format == 'p')
    {
        void *num = va_arg(args, void *);
        ft_pointer(num);
    }
}

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            handle_format_specifier(format, args);
        }
        else
        {
            ft_putchar(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count;
}

int main()
{
    printf("\nCHAR\n");
    int c = printf("printf: %c, %c, %c, %c, %c", 'A', '9', '-', 48, '\0');
    printf("\nReturn value: %d\n", c);

    int ch = ft_printf("ft_printf: %c, %c, %c, %c, %c", 'A', '9', '-', 48, '\0');
    printf("\nReturn value: %d\n", ch);

    printf("\nSTRING\n");

    printf("printf: %s, %s, %s, %s, %s\n", "Apple", "9", "", "-", "\0");
    ft_printf("ft_printf: %s, %s, %s, %s, %s\n", "Apple", "9", "", "-", NULL);

    printf("\nPOINTER\n");

    printf("printf: %p, %p\n", (void *)0x1234, NULL);
    ft_printf("ft_printf: %p, %p\n", (void *)0x1234, NULL);

    return 0;
}

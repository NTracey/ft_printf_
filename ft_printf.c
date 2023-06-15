#include "ft_printf.h"

// int ft_printf(const char *format, ...)
// {
//     va_list args;
//     va_start(args, format);

//     int char_count = 0;

//     while (*format != '\0')
//     {
//         if (*format == '%')
//         {
//             format++;
//             handle_format_specifier(format, args);
//         }
//         else
//         {
//             ft_putchar(*format);
//             char_count++;
//         }
//         format++;
//     }

//     va_end(args);
//     return char_count;
// }

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;                              // Move past the '%'
            format_specifier(format, args); // Call the function in format_specifier.c
            // format++;                              // Move past the format specifier character
        }
        else
            // {
            ft_putchar(*format); // Print the non-format character
        format++;                // Move to the next character in the format string
        // }
        char_count++;
    }

    va_end(args);
    return char_count;
}

// int ft_printf(const char *format, ...)
// {
//     va_list args;
//     va_start(args, format);

//     int char_count = 0;

//     while (*format != '\0')
//     {
//         if (*format == '%')
//         {
//             format++;                              // Move past the '%'
//             handle_format_specifier(format, args); // Call the function in format_specifier.c
//             format++;                              // Move past the format specifier character
//         }
//         else
//         {
//             ft_putchar(*format); // Print the non-format character
//             format++;            // Move to the next character in the format string
//         }
//         char_count++;
//     }

//     va_end(args);
//     return char_count;
// }

int main()
{
    printf("\nCHAR\n");
    int c = printf("printf:    %c, %c, %c, %c, %c", 'A', '9', '-', 48, '\0');
    printf("\nReturn value: %d\n", c);

    int ch = ft_printf("ft_printf: %c, %c, %c, %c, %c", 'A', '9', '-', 48, '\0');
    printf("\nReturn value: %d\n", (ch - 3));

    printf("\nPERCENT\n");

    printf("printf:    %%%%\n");
    ft_printf("ft_printf: %%%%\n");

    printf("\nSTRING\n");

    printf("printf:    %s, %s, %s, %s, %s\n", "Apple", "9", "", "-", "\0");
    ft_printf("ft_printf: %s, %s, %s, %s, %s\n", "Apple", "9", "", "-", "\0");

    printf("\nDECIMAL\n");

    int octal_num = 052; // Octal representation of decimal 42
    int hex_num = 0x2A;  // Hexadecimal representation of decimal 42
    printf("printf:    %d, %d, %d, %d, %d, %d, %d, %d\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: %d, %d, %d, %d, %d, %d, %d, %d\n\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nINTERGER\n");
    printf("printf:    %i, %i, %i, %i, %i, %i, %i, %i\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: %i, %i, %i, %i, %i, %i, %i, %i\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nUNSIGNED DECIMAL\n");

    printf("printf:    %u, %u, %u, %u, %u, %u, %u, %u\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: %u, %u, %u, %u, %u, %u, %u, %u\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nHEX UPPERCASE\n");

    printf("printf:    %X, %X, %X, %X, %X, %X, %X, %X\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: %X, %X, %X, %X, %X, %X, %X, %X\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nHEX LOWERCASE\n");

    printf("printf:    %x, %x, %x, %x, %x, %x, %x, %x\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: %x, %x, %x, %x, %x, %x, %x, %x\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nPOINTER\n");
    int x = 50;
    int *ptr = &x;
    printf("printf:    The address is: %p, the value is %d\n", ptr, *ptr);
    ft_printf("ft_printf: The address is: %p, the value is %d\n", ptr, *ptr);

    printf("printf:    %p, %p\n", (void *)0x1234, NULL);
    ft_printf("ft_printf: %p, %p\n", (void *)0x1234, NULL);

    return 0;
}
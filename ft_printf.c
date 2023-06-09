#include "ft_printf.h" // Include your custom header file

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
            handle_format_specifier(format, args); // Call the function in format_specifier.c
            format++;                              // Move past the format specifier character
        }
        else
        {
            putchar(*format); // Print the non-format character
            format++;            // Move to the next character in the format string
        }
        char_count++;
    }

    va_end(args);
    return char_count;
}

int main()
{
    printf("CHAR\n");
    int c = printf("%c, %c, %c,  %c,  %c", 'A', '9', '-', 1, '\0');
    printf("\nReturn value: %d\n", c);

    int ch = ft_printf("%c, %c, %c,  %c,  %c", 'A', '9', '-', 1, '\0');
    printf("\nReturn value: %d\n", ch);

    printf("PERCENT\n");

    printf("Percent: %%\n");
    ft_printf("Percent: %%\n");

    printf("\nSTRING\n");

    printf("%s, %s, %s, %s\n", "Apple", "9", "", "-");
    ft_printf("%s, %s, %s, %s\n", "Apple", "9", "", "-");

    printf("\nDECIMAL\n");

    int octal_num = 052; // Octal representation of decimal 42
    int hex_num = 0x2A;  // Hexadecimal representation of decimal 42
    printf("printf: %d, %d, %d, %d, %d, %d, %d\n", 42, -11, 0, 222, -222, octal_num, hex_num);
    ft_printf("print_dec_int: %d, %d, %d, %d, %d %d, %d\n\n", 42, -11, 0, 222, -222, octal_num, hex_num);

    printf("\nINTERGER\n");
    printf("printf: %i, %i, %i, %i, %i, %i\n", 0, 1000, 222, -222, octal_num, hex_num);
    ft_printf("print_dec_int:%i, %i, %i, %i,  %i, %i\n", 0, 1000, 222, -222, octal_num, hex_num);

    printf("\nUNSIGNED DECIMAL\n");

    printf("%u, %u, %u, %u, %u\n", 42, -11, 0, octal_num, hex_num);
    ft_printf("%u, %u, %u, %u, %u\n\n", 42, -11, 0, octal_num, hex_num);

    printf("\nHEX UPPERCASE\n");

    printf("%X, %X, %X, %X\n", 0, 1000, 222, -222);
    ft_printf("%X, %X, %X, %X\n", 0, 1000, 222, -222);

    printf("\nHEX LOWERCASE\n");

    printf("%x, %x, %x, %x\n", 0, 1000, 222, -222);
    ft_printf("%x, %x, %x, %x\n", 0, 1000, 222, -222);
}
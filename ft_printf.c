#include "ft_printf.h"

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
            char_count += format_specifier(format, args);
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

/*
int ft_printf(const char *format, ...)
{
    va_list args;           // Declare a variable of type va_list to hold the variable arguments
    va_start(args, format); // Initialize the va_list with the variable arguments

    int char_count = 0; // Initialize a counter for the number of characters printed

    while (*format != '\0') // Iterate over each character in the format string
    {
        if (*format == '%') // If the current character is '%', it indicates a format specifier
        {
            format++; // Move past the '%' character

            // Call the function format_specifier to handle the format specifier
            format_specifier(format, args);

            // Note: In the original code, there was an extra format++ here, which is unnecessary and has been commented out
        }
        else
        {
            ft_putchar(*format); // Print the non-format character using ft_putchar
        }

        format++;     // Move to the next character in the format string
        char_count++; // Increment the character count
    }

    va_end(args);      // Clean up the va_list after using it
    return char_count; // Return the total number of characters printed
}
*/

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
//             format_specifier(format, args); // Call the function in format_specifier.c
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
    printf("printf:\n");
    int c = printf("%c, %c, %c, %c, %c", 'A', '9', '-', 48, '\0');

    printf("\nReturn value: %d\n", c);
    printf("\nft_printf:\n");
    int ch = ft_printf("%c, %c, %c, %c, %c", 'A', '9', '-', 48, '\0');
    ft_printf("\nReturn value: %d\n", ch);

    printf("---------------------------------------------------------------------------------------------------------------------");

    printf("\nPERCENT\n");
    printf("printf:\n");
    int p = printf("%%%%");
    printf("\nReturn value: %d\n", p);

    printf("\nft_printf:\n");
    int per = ft_printf("%%%%");
    printf("\nReturn value: %d\n", per);

    printf("---------------------------------------------------------------------------------------------------------------------");

    printf("\nSTRING\n");
    printf("printf:\n");
    int s = printf("%s, %s, %s, %s, %s", "Apple", "9", "", "-", "\0");
    printf("\nReturn value: %d\n", s);

    printf("\nft_printf:\n");
    int str = ft_printf("%s, %s, %s, %s, %s", "Apple", "9", "", "-", "\0");
    ft_printf("\nReturn value: %d\n", str);

    printf("---------------------------------------------------------------------------------------------------------------------");

    printf("\nDECIMAL\n");

    int octal_num = 052; // Octal representation of decimal 42
    int hex_num = 0x2A;  // Hexadecimal representation of decimal 42
    printf("printf:\n");
    int d = printf("%d, %d, %d, %d, %d, %d, %d, %d", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    printf("\nReturn value: %d\n", d);

    printf("\nft_printf:\n");
    int dec = ft_printf("%d, %d, %d, %d, %d, %d, %d, %d", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("\nReturn value: %d\n", dec);

    printf("---------------------------------------------------------------------------------------------------------------------");

    printf("\nINTERGER\n");
    printf("printf:\n");
    int i = printf("%i, %i, %i, %i, %i, %i, %i, %i", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    printf("\nReturn value: %d\n", i);

    printf("\nft_printf:\n");
    int in = ft_printf("%i, %i, %i, %i, %i, %i, %i, %i", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("\nReturn value: %d\n", in);

    printf("---------------------------------------------------------------------------------------------------------------------");

    printf("\nUNSIGNED DECIMAL\n");
    printf("printf:\n");
    int u = printf("%u, %u, %u, %u, %u, %u, %u, %u", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    printf("\nReturn value: %d\n", u);

    printf("\nft_printf:\n");
    int un = ft_printf("%u, %u, %u, %u, %u, %u, %u, %u", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("\nReturn value: %d\n", un);

    printf("---------------------------------------------------------------------------------------------------------------------");

    printf("\nHEX UPPERCASE\n");
    printf("printf:\n");
    int hexu = printf("%X, %X, %X, %X, %X, %X, %X, %X", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    printf("\nReturn value: %d\n", hexu);

    printf("\nft_printf:\n");
    int hexupp = ft_printf("%X, %X, %X, %X, %X, %X, %X, %X", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("\nReturn value: %d\n", hexupp);

    printf("---------------------------------------------------------------------------------------------------------------------");

    printf("\nHEX LOWERCASE\n");
    printf("printf:\n");
    int hexl = printf("%x, %x, %x, %x, %x, %x, %x, %x", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    printf("\nReturn value: %d\n", hexl);

    printf("\nft_printf:\n");
    int hexlo = ft_printf("%x, %x, %x, %x, %x, %x, %x, %x", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("\nReturn value: %d\n", hexlo);

    printf("---------------------------------------------------------------------------------------------------------------------");

    printf("\nPOINTER\n");
    int x = 50;
    int *ptr = &x;
    printf("printf:\n");
    printf("The address is: %p, the value is %d", ptr, *ptr);

    printf("\nft_printf:\n");
    ft_printf("The address is: %p, the value is %d", ptr, *ptr);

    printf("\nprintf:\n");
    int point = printf("%p, %p", (void *)0x1234, NULL);
    printf("\nReturn value: %d\n", point);

    printf("\nft_printf:\n");
    int pointer = ft_printf("%p, %p", (void *)0x1234, NULL);
    ft_printf("\nReturn value: %d\n", pointer);

    printf("\n\n");
    int returna = ft_printf("%x", 10);
    ft_printf("\nreturn value: %d", returna);
    printf("\n");

    int returnb = printf("%x", 10);
    printf("\nreturn value: %d", returnb);
    printf("\n");

    return 0;
}
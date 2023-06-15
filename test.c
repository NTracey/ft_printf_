#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_percent(void)
{
    ft_putchar('%');
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

static size_t get_num_len(int n)
{
    size_t len;

    len = 0;
    if (n <= 0)
        len = 1;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int n)
{
    char *str;
    size_t len;
    unsigned int nbr;

    len = get_num_len(n);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n < 0)
        nbr = -n;
    else
        nbr = n;
    while (len--)
    {
        str[len] = (nbr % 10) + '0';
        nbr /= 10;
    }
    if (n < 0)
        str[0] = '-';
    return (str);
}

void ft_dec_int(int decimal_number)
{
    ft_putstr(ft_itoa(decimal_number));
}

void ft_hex(unsigned long int decimal_number, int lowercase)
{
    // convert_to_ascii(decimal_number, lowercase);
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
}

// int convert_to_ascii(unsigned long int decimal_number, int lowercase)
// {
//     int i;
//     int remainder;
//     char hexa_num[100];

//     i = 0;
//     if (decimal_number == 0)
//         hexa_num[i++] = '0';
//     else // handles positive decimal numbers
//     {
//         while (decimal_number != 0)
//         {
//             remainder = decimal_number % 16;
//             if (remainder < 10)
//                 hexa_num[i++] = remainder + '0'; // Convert to ASCII character
//             else
//                 hexa_num[i++] = remainder + (lowercase ? 'a' : 'A') - 10;
//             decimal_number = decimal_number / 16;
//         }
//     }
//     while (--i >= 0) // Print the hex number in reverse order
//         ft_putchar(hexa_num[i]);
//     return 0;
// }

// void ft_hex(unsigned long int decimal_number, int lowercase)
// {
//     convert_to_ascii(decimal_number, lowercase);
// }

void ft_pointer(const void *ptr)
{
    if (ptr == NULL)
        ft_putstr("(nil)");
    else
    {
        unsigned long int decimal_number = (unsigned long int)ptr;
        ft_putstr("0x");
        // convert_to_ascii(decimal_number, 1);
        ft_hex(decimal_number, 1);
    }
}

static size_t num_len(unsigned int n)
{
    size_t len = 0;
    // changes to only handle if format string in 0
    if (n == 0)
        // return 1 length
        return 1;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return len;
}

// change parameter from int to unsigned int
char *_itoa(unsigned int n)
{
    char *str;
    size_t len;
    // unsigned int	nbr;

    len = num_len(n);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[len] = '\0';
    // if (n < 0)
    // 	nbr = -n;
    // else
    // 	nbr = n;
    while (len--)
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    // if (n < 0)
    // 	str[0] = '-';
    return (str);
}

void ft_unsigned_decimal(int decimal_number)
{
    ft_putstr(_itoa(decimal_number));
}

void handle_format_specifier(const char *format, va_list args)
{
    if (*format == 'c')
        ft_putchar((char)va_arg(args, int));
    else if (*format == '%')
        // parameter is nothing because it does not expect any argument since it's void. It will simple print %
        ft_percent();
    else if (*format == 's')
        ft_putstr(va_arg(args, char *));
    else if (*format == 'd' || *format == 'i')
        ft_dec_int(va_arg(args, int));
    else if (*format == 'u')
        ft_unsigned_decimal(va_arg(args, int));
    else if (*format == 'x' || *format == 'X')
        ft_hex(va_arg(args, unsigned int), *format == 'x');
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
            format++;                              // Move past the '%'
            handle_format_specifier(format, args); // Call the function in format_specifier.c
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

int main()
{
    printf("\nCHAR\n");
    int c = printf("printf: %c, %c, %c, %c, %c", 'A', '9', '-', 48, '\0');
    printf("\nReturn value: %d\n", c);

    int ch = ft_printf("ft_printf: %c, %c, %c, %c, %c", 'A', '9', '-', 48, '\0');
    printf("\nReturn value: %d\n", (ch - 3));

    printf("\nPERCENT\n");

    printf("printf: %%%%\n");
    ft_printf("ft_printf: %%%%\n");

    printf("\nSTRING\n");

    printf("printf: %s, %s, %s, %s, %s\n", "Apple", "9", "", "-", "\0");
    ft_printf("ft_printf: %s, %s, %s, %s, %s\n", "Apple", "9", "", "-", "\0");

    printf("\nDECIMAL\n");

    int octal_num = 052; // Octal representation of decimal 42
    int hex_num = 0x2A;  // Hexadecimal representation of decimal 42
    printf("printf: %d, %d, %d, %d, %d, %d, %d, %d\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: : %d, %d, %d, %d, %d %d, %d, %d\n\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nINTERGER\n");
    printf("printf: %i, %i, %i, %i, %i, %i, %i, %i\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: :%i, %i, %i, %i, %i, %i, %i, %i\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nUNSIGNED DECIMAL\n");

    printf("printf: %u, %u, %u, %u, %u, %u, %u, %u\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: %u, %u, %u, %u, %u, %u, %u, %u\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nHEX UPPERCASE\n");

    printf("printf: %X, %X, %X, %X, %X, %X, %X, %X\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: %X, %X, %X, %X, %X, %X, %X, %X\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nHEX LOWERCASE\n");

    printf("printf: %x, %x, %x, %x, %x, %x, %x, %x\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');
    ft_printf("ft_printf: %x, %x, %x, %x, %x, %x, %x, %x\n", -987654321, 1000000, 222, -222, octal_num, hex_num, 0, '\0');

    printf("\nPOINTER\n");
    int x = 50;
    int *ptr = &x;
    printf("printf: The address is: %p, the value is %d\n", ptr, *ptr);
    ft_printf("ft_printf: The address is: %p, the value is %d\n", ptr, *ptr);

    printf("printf: %p, %p\n", (void *)0x1234, NULL);
    ft_printf("ft_printf: %p, %p\n", (void *)0x1234, NULL);

    return 0;
}

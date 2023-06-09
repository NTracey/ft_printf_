#include <stdio.h>
#include <stdarg.h>

int convert_to_ascii(unsigned int decimal_number)
{
    int i = 0;
    int remainder;
    char hexa_num[100];

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
                hexa_num[i++] = remainder + 'A' - 10; // Convert to uppercase hex letter
            decimal_number = decimal_number / 16;
        }
    }
    while (i-- > 0) // Print the hex number in reverse order
        putchar(hexa_num[i]);
    return (0);
}

void print_hex_uppercase(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'X')
            {
                unsigned int decimal_number;
                decimal_number = va_arg(args, int);
                convert_to_ascii(decimal_number);
            }
        }
        else
            putchar(*format);
        format++;
    }
    va_end(args);
}

int main()
{
    printf("%X, %X, %X, %X\n", 0, 1000, 222, -222);
    print_hex_uppercase("%X, %X, %X, %X\n", 0, 1000, 222, -222);

    return 0;
}
#include <stdio.h>
#include <stdarg.h>

// Function to convert a decimal number to its hexadecimal ASCII representation
int convert_to_ascii(unsigned int decimal_number, int lowercase)
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
                /*
                if (lowercase)
                    hexa_num[i] = remainder + 'a' - 10; // Convert to lowercase hex letter
                else
                    hexa_num[i] = remainder + 'A' - 10; // Convert to uppercase hex letter
                i++;
                 */
                hexa_num[i++] = remainder + (lowercase ? 'a' : 'A') - 10;
            decimal_number = decimal_number / 16;
        }
    }
    while (--i >= 0) // Print the hex number in reverse order
        putchar(hexa_num[i]);
    return (0);
}

void print_hex(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            unsigned int decimal_number;

            decimal_number = va_arg(args, int); // Use unsigned int here
            if (*format == 'x')
                convert_to_ascii(decimal_number, 1); // Lowercase hex
            if (*format == 'X')
                convert_to_ascii(decimal_number, 0); // Uppercase hex
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
    print_hex("%X, %X, %X, %X\n", 0, 1000, 222, -222);
    printf("%x, %x, %x, %x\n", 0, 1000, 222, -222);
    print_hex("%x, %x, %x, %x\n", 0, 1000, 222, -222);

    return 0;
}

#include <stdio.h>
#include <stdarg.h>

void print_hex_lowercase(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int i = 0;
    // unsigned int not int to handle -ve by dropping the '-' in the var_arg code line
    unsigned int decimal_number;
    char hexa_num[100];
    int remainder;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'x')
            {
                // converts -ves to +ves since it's unsigned int
                decimal_number = va_arg(args, int);

                if (decimal_number == 0)
                {
                    hexa_num[i] = '0';
                    i++;
                }

                // handles positive decimal numbers
                else if (decimal_number > 0)
                {
                    while (decimal_number != 0)
                    {
                        remainder = decimal_number % 16;
                        if (remainder < 10)
                            hexa_num[i] = remainder + '0'; // Convert to ASCII character
                        else
                            hexa_num[i] = remainder + 'a' - 10; // Convert to lowercase hex letter
                        decimal_number = decimal_number / 16;
                        i++;
                    }
                }

                // Print the hex number in reverse order
                while (i > 0)
                {
                    i--;
                    putchar(hexa_num[i]);
                }
            }
        }
        else
        {
            putchar(*format);
        }

        format++;
    }
    va_end(args);
}

int main()
{
    printf("%x, %x, %x, %x\n", 0, 1000, 222, -222);
    print_hex_lowercase("%x, %x, %x, %x\n", 0, 1000, 222, -222);

    return 0;
}
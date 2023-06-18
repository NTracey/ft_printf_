// prints the memory address in hexadecimal

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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

// paramters are change to long to handle the long number to print out otherwise it'll just get cut off midway
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
        putchar(hexa_num[i]);
    return 0;
}

void ft_hex(unsigned long int decimal_number, int lowercase)
{
    convert_to_ascii(decimal_number, lowercase);
}

void print_pointer(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            if (*format == 'p')
            {
                // unsigned long int decimal_number;
                // decimal_number = va_arg(args, unsigned long int);
                void *ptr = va_arg(args, void *);
                // unsigned long int decimal_number = (unsigned long int)ptr;
                if (ptr == NULL)
                {
                    // using printf won't change the position of (nil)
                    // but using write(1, "(nil), 5") and ft_putstr("(nil)") will mess up the output position of (nil)
                    putchar('(');
                    putchar('n');
                    putchar('i');
                    putchar('l');
                    putchar(')');
                }
                else
                {
                    unsigned long int decimal_number = (unsigned long int)ptr;
                    // ft_putstr("0x") will move the position of the output of convert_to_ascii(decimal_number, 1);
                    putchar('0');
                    putchar('x');
                    convert_to_ascii(decimal_number, 1);
                }
            }
        }
        else
            putchar(*format);
        format++;
    }
    va_end(args);
}

#include <stdio.h>

int main()
{
    int a = 10;
    int *b = &a;

    print_pointer("%p\n", b);          // Output: 7fffed03bdbc
    printf("%p\n", (void *)b);         // Output: 7fffed03bdbc
    printf("%lx\n", (unsigned long)b); // Output: 7fffed03bdbc

    printf("printf: %p, %p\n", (void *)0x1234, NULL);
    print_pointer("ft_printf: %p, %p\n", (void *)0x1234, NULL);

    return 0;
}

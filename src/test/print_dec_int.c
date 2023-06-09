#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// convert integer to string so it can be printed out
// same structure as print_string
// %d and %i almost prints the same output but in this function they both print the same output the other difference is that this function checks for 'd' not 'i'

void ft_putchar(char c)
{
    write(1, &c, 1);
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

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int print_dec_int(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // int num_count;

    // num_count = 0;
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            int num = va_arg(args, int);
            if (*format == 'd' || *format == 'i')
                ft_putstr(ft_itoa(num));
        }
        else
        {
            ft_putchar(*format);
            // num_count++;
        }
        format++;
    }
    va_end(args);
    // return (num_count);
}

int main()
{
    int octal_num = 052; // Octal representation of decimal 42
    int hex_num = 0x2A;  // Hexadecimal representation of decimal 42
    printf("DECIMAL\nprintf: %d, %d, %d, %d, %d, %d, %d\n", 42, -11, 0, 222, -222, octal_num, hex_num);
    print_dec_int("print_dec_int: %d, %d, %d, %d, %d %d, %d\n\n", 42, -11, 0, 222, -222, octal_num, hex_num);

    printf("INTEGER\nprintf: %i, %i, %i, %i, %i, %i\n", 0, 1000, 222, -222, octal_num, hex_num);
    print_dec_int("print_dec_int:%i, %i, %i, %i,  %i, %i\n", 0, 1000, 222, -222, octal_num, hex_num);
    
    return 0;
}
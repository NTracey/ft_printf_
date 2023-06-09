#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int print_integer(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && *++format == 'i')
        {
            int num;
            num = va_arg(args, int);
            ft_putstr(ft_itoa(num));
        }
        else
            ft_putchar(*format);
        format++;
    }
    va_end(args);
}

int main()
{
    printf("%i, %i, %i, %i\n", 0, 1000, 222, -222);
    print_integer("%i, %i, %i, %i\n", 0, 1000, 222, -222);
    return 0;
}

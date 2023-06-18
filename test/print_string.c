#include <stdarg.h>
#include <unistd.h>


int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
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

int print_string(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && *++format == 's')
        {
            char *str;
            str = va_arg(args, char *);
            ft_putstr(str);
        }
        else
        {
            ft_putchar(*format);
        }
        format++;
    }
    va_end(args);
}

#include <stdio.h>
int main()
{
    int s = printf("%s, %s, %s, %s\n", "Apple", "9", "", "-");
    printf("%d\n", s);
    int str = print_string("%s, %s, %s, %s\n", "Apple", "9", "", "-");
    printf("%d\n", s);

    return 0;
}
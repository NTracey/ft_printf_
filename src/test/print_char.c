#include <stdarg.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int print_char(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
            format++;
        if (*format == 'c')
        {
            int ch;
            ch = va_arg(args, int);
            ft_putchar((char)ch);
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
    int c = printf("%c, %c, %c,  %c,  %c", 'A', '9', '-', 1, '\0');
    printf("\nReturn value: %d\n", c);

    int ch = printf("%c, %c, %c,  %c,  %c", 'A', '9', '-', 1, '\0');
    printf("\nReturn value: %d\n", ch);
    return 0;
}
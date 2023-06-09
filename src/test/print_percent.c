#include <stdarg.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int print_percent(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%' && *++format == '%')
        {
            int ch;
            ch = va_arg(args, int);
            ft_putchar('%');
        }
        else
            ft_putchar(*format);
        format++;
    }
    va_end(args);
}

#include <stdio.h>
int main()
{
    printf("Percent: %%\n");
    print_percent("Percent: %%\n");
    return 0;
}

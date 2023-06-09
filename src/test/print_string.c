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
    int str = print_string("%s, %s, %s, %s\n", "Apple", "9", "", "-");
    return 0;
}

// #include <stdarg.h>
// #include <unistd.h>

// int ft_strlen(const char *str)
// {
//     int i;

//     i = 0;
//     while (str[i] != '\0')
//         i++;
//     return (i);
// }

// void ft_putchar(char c)
// {
//     write(1, &c, 1);
// }

// void ft_putstr(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i] != '\0')
//     {
//         write(1, &str[i], 1);
//         i++;
//     }
// }

// int print_string(const char *format, ...)
// {
//     va_list args;
//     va_start(args, format);

//     int char_count;

//     char_count = 0;
//     while (*format != '\0')
//     {
//         // if (*format == '%')
//         //     format++;
//         // if (*format == 's')
//         // it will increment format then dereference (different from *format++)
//         if (*format == '%' && *++format == 's')
//         {
//             // int j = 0;
//             char *str;
//             str = va_arg(args, char *);

//             /*
//             while (str[j] != '\0')
//             {

//                 ft_putchar(str[j]);
//                 j++;
//                 char_count++;
//             }

//             or

//              while (*str != '\0')
//             {

//                 ft_putchar(*str);
//                 str++;
//                 char_count++;
//             }

//             */
//             // The 2 lines of code below replaces the comment out code above
//             ft_putstr(str);
//             char_count = char_count + ft_strlen(str);
//         }
//         else
//         {
//             ft_putchar(*format);
//             char_count++;
//         }
//         format++;
//     }
//     va_end(args);
//     return (char_count);
// }

// #include <stdio.h>
// int main()
// {
//     int s = printf("%s, %s, %s, %s", "Apple", "9", "", "-");
//     printf("\nReturn value: %d\n", s);

//     int str = print_string("%s, %s, %s, %s", "Apple", "9", "", "-");
//     printf("\nReturn value: %d\n", str);
//     return 0;
// }

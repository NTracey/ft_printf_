#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
        ft_putchar(hexa_num[i]);
    return 0;
}

// const void * since a pointer can be any data type and cannot be modified
// void ft_pointer(const void *ptr)
// {
//     unsigned long int decimal_number = (unsigned long int)ptr;
//     putchar('0');
//     putchar('x');
//     convert_to_ascii(decimal_number, 1);
// }

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

void ft_pointer(const void *ptr)
{
    if (ptr == NULL)
        ft_putstr("(nil)");
    else
    {
        unsigned long int decimal_number = (unsigned long int)ptr;
        ft_putstr("0x");
        convert_to_ascii(decimal_number, 1);
    }
}

#include <stdio.h>

int main()
{
    int a = 10;
    int *b = &a;

    printf("%p\n", (void *)b); // Output: 7fffed03bdbc
    ft_pointer(b);             // Output: 7fffed03bdbc

    printf("\n\n%p\n", NULL); // Output: (nil) (or 0x0 depending on platform)
    ft_pointer(NULL);         // Output: 0

    char *c = "Hello";
    printf("\n\n%p\n", (void *)c); // Output: 0x4006e6
    ft_pointer(c);                 // Output: 0x4006e6

    int arr[] = {1, 2, 3};
    printf("\n\n%p\n", (void *)arr); // Output: 0x7fffed03bdd0
    ft_pointer(arr);                 // Output: 0x7fffed03bdd0

    void (*func_ptr)() = NULL;
    printf("\n\n%p\n", (void *)func_ptr); // Output: (nil) (or 0x0 depending on platform)
    ft_pointer(func_ptr);                 // Output: 0

    return 0;
}
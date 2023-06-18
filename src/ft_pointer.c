#include "../ft_printf.h"

int ft_pointer(const void *ptr)
{
    unsigned long int decimal_number;
    int char_count;

    if (ptr == NULL)
    {
        ft_putstr("(nil)"); // Assuming ft_putstr is defined
        char_count = 5;     // Length of "(nil)"
    }
    else
    {
        decimal_number = (unsigned long int)ptr;
        ft_putstr("0x");
        ft_hex(decimal_number, 1);
        char_count = hex_length(decimal_number) + 2; // 2 for "0x"
    }

    return char_count;
}

// #include "ft_printf.h"
// #include <string.h>

// int ft_pointer(const void *ptr)
// {
//     unsigned long int decimal_number;
//     if (ptr == NULL)
//     {
//         ft_putstr("(nil)");
//         decimal_number = 0;
//     }
//     else
//     {
//         decimal_number = (unsigned long int)ptr;
//         ft_putstr("0x");
//         ft_hex(decimal_number, 1);
//     }
//     char *hex_string = ft_hex(decimal_number, 1);
//     int char_count = strlen(hex_string) + 2;
//     return char_count;
// }

// int ft_pointer(const void *ptr)
// {
//     if (ptr == NULL)
//         ft_putstr("(nil)");
//     else
//     {
//         unsigned long int decimal_number = (unsigned long int)ptr;
//         ft_putstr("0x");
//         ft_hex(decimal_number, 1);
//     }
//     char *hex_string = ft_hex(decimal_number, 1);
//     int char_count = strlen(hex_string) + 2;
//     return char_count;
// }

// #include <stdio.h>

// int main()
// {
//     int a = 10;
//     int *b = &a;

//     printf("%p\n", (void *)b); // Output: 7fffed03bdbc
//     ft_pointer(b);             // Output: 7fffed03bdbc

//     printf("\n\n%p\n", NULL); // Output: (nil) (or 0x0 depending on platform)
//     ft_pointer(NULL);         // Output: 0

//     char *c = "Hello";
//     printf("\n\n%p\n", (void *)c); // Output: 0x4006e6
//     ft_pointer(c);                 // Output: 0x4006e6

//     int arr[] = {1, 2, 3};
//     printf("\n\n%p\n", (void *)arr); // Output: 0x7fffed03bdd0
//     ft_pointer(arr);                 // Output: 0x7fffed03bdd0

//     void (*func_ptr)() = NULL;
//     printf("\n\n%p\n", (void *)func_ptr); // Output: (nil) (or 0x0 depending on platform)
//     ft_pointer(func_ptr);                 // Output: 0

//     return 0;
// }
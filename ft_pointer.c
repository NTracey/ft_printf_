#include "ft_printf.h"

void ft_pointer(const void *ptr)
{
    if (ptr == NULL)
        ft_putstr("(nil)");
    else
    {
        unsigned long int decimal_number = (unsigned long int)ptr;
        ft_putstr("0x");
        ft_hex(decimal_number, 1);
    }
}

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
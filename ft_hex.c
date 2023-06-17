#include "ft_printf.h"
// long is needed for %p since the number is too big to print out

int ft_hex(unsigned long int decimal_number, int lowercase)
{
    // convert_to_ascii(decimal_number, lowercase);
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
    return (i);
}

// int main()
// {
//     printf("%x\n", -222);
//     ft_hex(-222, 0); // 0 -> Uppercase hexadecimal
//     printf("\n");
//     ft_hex(-222, 1); // 1 -> Lowercase hexadecimal
//     printf("\n");

//     return 0;
// }

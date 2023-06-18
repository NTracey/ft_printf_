#include "../ft_printf.h"

int hex_length(unsigned long int decimal_number)
{
    int length;

    length = 0;
    while (decimal_number != 0)
    {
        decimal_number /= 16;
        length++;
    }
    return (length);
}
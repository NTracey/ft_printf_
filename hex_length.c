#include "ft_printf.h"

// remake this helper function
int hex_length(unsigned long nbr)
{
    int length;

    length = 0;
    while (nbr > 0)
    {
        nbr /= 16;
        length++;
    }
    return (length);
}
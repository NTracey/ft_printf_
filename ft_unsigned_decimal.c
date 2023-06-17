#include "ft_printf.h"

// rename getnum and itoa since they changed

// change parameter from int to unsigned int to only handle positive numbers
static size_t num_len(unsigned int n)
{
    size_t len = 0;
    // changes to only handle if format string in 0 and not -ve
    if (n == 0)
        // return 1 length
        return 1;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return len;
}

// change parameter from int to unsigned int
char *_itoa(unsigned int n)
{
    char *str;
    size_t len;
    // unsigned int	nbr;

    len = num_len(n);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[len] = '\0';
    //removed this codes since this part was included to handle -ve integers
    // if (n < 0)
    // 	nbr = -n;
    // else
    // 	nbr = n;
    while (len--)
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    // removed this codes since this part was included to handle -ve integers
    // if (n < 0)
    // 	str[0] = '-';
    return (str);
}

int ft_unsigned_decimal(int decimal_number)
{
    ft_putstr(_itoa(decimal_number));
    int char_count = num_len(decimal_number);
    return (char_count);
}

// int main()
// {
//     ft_unsigned_decimal(-11);
//     return 0;
// }
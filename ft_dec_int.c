#include "ft_printf.h"

// returns the length of the number
static size_t get_num_len(int n)
{
    size_t len;

    len = 0;
    // if n is negative or 0
    if (n <= 0)
        // return 1 for '-' or '0' character
        // zero will skip while loop and go straight to return
        len = 1;
    // loop until n becomes 0
    while (n != 0)
    {
        // divide by 10 to count the number of digits in the number
        // e.g. 50/10
        // loops twice so len is 2
        n = n / 10;
        len++;
    }
    // return the number of digits including '-' if it's -ve
    return (len);
}

char *ft_itoa(int n)
{
    char *str;
    size_t len;
    unsigned int nbr;

    // store the length of digits at len
    len = get_num_len(n);
    // memory allocation for len including null character since it's a string
    str = (char *)malloc((len + 1) * sizeof(char));
    // check memory allocation
    if (!str)
        return (NULL);
    // add '\0' to last index of string since get_num_len counts from 1
    str[len] = '\0';
    // n is -ve store as 
    if (n < 0)
        // converts -ve number to a +ve number
        // same as nbr = -n * -1
        nbr = -n;
    else
        nbr = n;
    while (len--)
    {
        // nbr % 10 takes the remainder of each digit
        // + '0' converts it to the corresponding ASCII number
        str[len] = (nbr % 10) + '0';
        // nbr/10 removes the last digit that's just been converted
        // to help iterate in reverse (the index)
        nbr /= 10;
    }
    if (n < 0)
        str[0] = '-';
    return (str);
}

int ft_dec_int(int decimal_number)
{
    //ft_putstring: print string
    //ft_itoa: converts interger to a string (does not print it)
    ft_putstr(ft_itoa(decimal_number));
    int char_count = get_num_len(decimal_number);
    return (char_count);
}

// int main()
// {
//     ft_dec_int(-11);
//     return 0;
// }

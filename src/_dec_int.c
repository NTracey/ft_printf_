#include "../ft_printf.h"

static size_t get_num_len(int n)
{
    size_t len;

    len = 0;
    if (n <= 0)
        len = 1;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int n)
{
    char *str;
    size_t len;
    unsigned int nbr;

    len = get_num_len(n);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (n < 0)
        nbr = -n;
    else
        nbr = n;
    while (len--)
    {
        str[len] = (nbr % 10) + '0';
        nbr /= 10;
    }
    if (n < 0)
        str[0] = '-';
    return (str);
}

void _dec_int(int decimal_number)
{
    _putstr(ft_itoa(decimal_number));
}

int main()
{
    _dec_int(-11);
    return 0;
}

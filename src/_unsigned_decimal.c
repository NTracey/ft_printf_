#include "../ft_printf.h"

// rename getnum and itoa since they changed

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(const char *str)
{
    while (*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
}

// change parameter from int to unsigned int to only handle positive numbers
static size_t get_num_len(unsigned int n)
{
    size_t len = 0;
    // changes to only handle if format string in 0
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
char *ft_itoa(unsigned int n)
{
    char *str;
    size_t len;
    // unsigned int	nbr;

    len = get_num_len(n);
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[len] = '\0';
    // if (n < 0)
    // 	nbr = -n;
    // else
    // 	nbr = n;
    while (len--)
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    // if (n < 0)
    // 	str[0] = '-';
    return (str);
}

void _unsigned_decimal(int decimal_number)
{
    ft_putstr(ft_itoa(decimal_number));
}

int main()
{
    _unsigned_decimal(-11);
    return 0;
}
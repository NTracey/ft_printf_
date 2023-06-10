#include "ft_printf.h"

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

int main()
{
    ft_putstr("Cat");
}
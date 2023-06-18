#include "../ft_printf.h"

int ft_putstr(char *str)
{
    int i = 0;
    int char_count = 0;

    if (str == NULL)
    {
        ft_putstr("(null)");
        return 6;
    }
    else
    {
        while (str[i] != '\0')
        {
            write(1, &str[i], 1);
            i++;
            char_count++;
        }
    }
    return char_count;
}

// int main()
// {
//     ft_putstr("Cat");
// }
#include <stdio.h> // putchar
#include <unistd.h> // write

void ft_putchar(char c)
{
    write(1, &c, 1);
}

// int _char(int c)
// {
//     // putchar(c);
//     write(1, &c, 1);
// }

#include <stdio.h>
int main()
{
    ft_putchar('C');
    ft_putchar('\n');
    ft_putchar('%');
    ft_putchar('\n');
    return 0;
}
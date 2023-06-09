#include "../ft_printf.h"

void _putchar(char c)
{
    write(1, &c, 1);
}

int main()
{
    _putchar('C');
}
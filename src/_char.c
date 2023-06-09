#include "../ft_printf.h"

void _char(char c)
{
    write(1, &c, 1);
}
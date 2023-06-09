if (*format == 'c' || *format == '%')
{
    int ch = va_arg(args, int);
    _char((char)ch);
}
if (*format == 's')
{
    char *str = va_arg(args, char *);
    _string(str);
}
// if (*format == 'p')
// {
//     int num = va_arg(args, int);
//     _integer(num);
// }
if (*format == 'd' || *format == 'i')
{
    int num = va_arg(args, int);
    _integer(num);
}
if (*format == 'u')
{
    int num = va_arg(args, int);
    _unsigned_decimal(num);
}
if (*format == 'x' || *format == 'X')
{
    unsigned int decimal_number;
    decimal_number = va_arg(args, unsigned int);
    _hex(decimal_number);
}
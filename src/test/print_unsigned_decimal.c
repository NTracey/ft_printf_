#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// convert integer to string so it can be printed out
// same structure as print_string
// %d and %i almost prints the same output but in this function they both print the same output the other difference is that this function checks for 'd' not 'i'

void ft_putchar(char c)
{
    write(1, &c, 1);
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
char	*ft_itoa(unsigned int n)
{
	char			*str;
	size_t			len;
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

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}



int print_unsigned_decimal(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int num_count = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);

                char *str = ft_itoa(num);

                ft_putstr(str);

                // Update the total count separately
                num_count = num_count + get_num_len(num) + 1;

                free(str); // Remember to free the dynamically allocated memory
            }
        }
        else
        {
            ft_putchar(*format);
            num_count++;
        }
        format++;
    }

    va_end(args);

    return num_count;
}


int main() {
    int octal_num = 052;  // Octal representation of decimal 42
    int hex_num = 0x2A;  // Hexadecimal representation of decimal 42
    printf("%u, %u, %u, %u, %u\n", 42, -11, 0, octal_num, hex_num);
    print_unsigned_decimal("%u, %u, %u, %u, %u\n\n", 42, -11, 0, octal_num, hex_num);
    return 0;
}
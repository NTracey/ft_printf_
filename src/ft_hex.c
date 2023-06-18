#include "../ft_printf.h"

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

// long is needed for %p since the number is too big to print out
char *convert_to_hex(unsigned long int decimal_number, int lowercase)
{
    int i;
    int remainder;
    char *hexa_num;

    i = 0;
    hexa_num = (char *)malloc((hex_length(decimal_number) + 1) * sizeof(char));
    if (!hexa_num)
        return (NULL);
    if (decimal_number == '\0')
        hexa_num[i++] = '0';
    else // handles positive decimal numbers
    {
        while (decimal_number != 0)
        {
            remainder = decimal_number % 16;
            if (remainder < 10)
                hexa_num[i++] = remainder + '0'; // Convert to ASCII character
            else
                hexa_num[i++] = remainder + (lowercase ? 'a' : 'A') - 10;
            decimal_number = decimal_number / 16;
        }
    }
    while (--i >= 0) // Print the hex number in reverse order
        ft_putchar(hexa_num[i]);
    hexa_num[i] = '\0';
    return (hexa_num);
}

int ft_hex(unsigned long int decimal_number, int lowercase)
{
    char *hexa_num;
    int char_count;

    hexa_num = convert_to_hex(decimal_number, lowercase);
    // -1 since it counts from 1 not 0
    char_count = ft_strlen(hexa_num) - 1;
    // add this condition because strlen does have a return value for null character
    if (decimal_number == '\0')
        return 1;
    free(hexa_num);
    return (char_count);
}

/*
  68.KO (LEAKS!)
     You can rerun this test with sh test 68
     The function was called like this:
   ft_printf("%x", 0);
69.OK 70.OK 71.OK 72.OK 73.OK 74.OK 75.OK 76.OK 77.OK 78.OK
%X basic:

  79.KO (LEAKS!)
     You can rerun this test with sh test 79
     The function was called like this:
   ft_printf("%X", 0);
*/

// int main()
// {
//     printf("%x\n", -222);
//     // ft_hex(-222, 0); // 0 -> Uppercase hexadecimal
//     printf("\n");
//     ft_hex(-222, 1); // 1 -> Lowercase hexadecimal
//     printf("\n");

//     return 0;
// }

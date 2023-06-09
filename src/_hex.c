#include <stdio.h>
#include <stdarg.h>

// Function to convert a decimal number to its hexadecimal ASCII representation
int convert_to_ascii(unsigned int decimal_number, int lowercase)
{
    int i;
    int remainder;
    char hexa_num[100];

    i = 0;
    if (decimal_number == 0)
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
        putchar(hexa_num[i]);
    return 0;
}

void _hex(unsigned int decimal_number, int lowercase)
{
    convert_to_ascii(decimal_number, lowercase);
}

int main()
{
    _hex(-222, 0); // Uppercase hexadecimal
    printf("\n");
    _hex(-222, 1); // Lowercase hexadecimal

    return 0;
}

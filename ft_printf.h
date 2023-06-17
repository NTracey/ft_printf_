// HEADER GUARDS: #ifndef FT_PRINTF_H and #define FT_PRINTF_H
// They ensure that the contents of the header file are included only once during the compilation process.

// 1. #include "ft_printf.h" will include this header file
// 2. #ifndef will evaluate to true due to header being added the first time and it will include the codes betwwen ifndef and endif
#ifndef FT_PRINTF_H
// 3. #define will be encountered after the code block and it will prevent duplicate inclusion in the file by skipping over ifndef and endif
# define FT_PRINTF_H

// Header file inclusions
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function declarations
int format_specifier(const char *format, va_list args);
void ft_putchar(char c);
void ft_percent(void);
int ft_putstr(char *str);
int ft_dec_int(int decimal_number);
int ft_hex(unsigned long int decimal_number, int lowercase);
int ft_unsigned_decimal(int decimal_number);
int ft_pointer(const void *ptr);

// endif indicates the completion of the code that will be included only once during compilation if the header guards' condition is true.
#endif

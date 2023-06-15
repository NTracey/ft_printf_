// HEADER GUARDS: #ifndef FT_PRINTF_H and #define FT_PRINTF_H
// They ensure that the contents of the header file are included only once during the compilation process.

// #ifndef is responsible for including the code in the header file when the symbol is not defined.
// The code between #ifndef and the corresponding #endif will be included in the compilation.
#ifndef FT_PRINTF_H
// #define is used to define the symbol to prevent duplicate inclusion in subsequent files.
# define FT_PRINTF_H

// Header file inclusions
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function declarations
void format_specifier(const char *format, va_list args);
void ft_putchar(char c);
void ft_percent(void);
void ft_putstr(char *str);
void ft_dec_int(int decimal_number);
void ft_hex(unsigned long int decimal_number, int lowercase);
void ft_unsigned_decimal(int decimal_number);
void ft_pointer(const void *ptr);

// endif indicates the completion of the code that will be included only once during compilation if the header guards' condition is true.
#endif

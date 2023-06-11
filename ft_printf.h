#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    void *content;
    size_t content_size;
    struct s_list *next;
} t_list;

void format_specifier(const char *format, va_list args);
void ft_putchar(char c);
void ft_percent(void);
void ft_putstr(char *str);
void ft_dec_int(int decimal_number);
void ft_hex(unsigned long int decimal_number, int lowercase);
void ft_unsigned_decimal(int decimal_number);
void ft_pointer(const void *ptr);

#endif

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

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

void handle_format_specifier(const char *format, va_list args);
void _putchar(char c);
void _putstr(char *str);
void _dec_int(int decimal_number);
void _hex(unsigned int decimal_number, int lowercase);
void _unsigned_decimal(int decimal_number);

#endif

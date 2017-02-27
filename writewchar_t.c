//
// Created by Mykola Ponomarov on 27.02.17.
//

#include "ft_printf.h"

void writewchar_t(wchar_t c, t_arg *res)
{
    if (c <= 0x7F)
    {
        ft_putchar((char)c);
        res->len += 1;
    }
    else if (c <= 0x7FF)
    {
        ft_putchar((char)((c >> 6) + 0xC0));
        ft_putchar((char)((c & 0x3F) + 0x80));
        res->len += 1;
    }
    else if (c <= 0xFFFF)
    {
        ft_putchar((char)((c >> 12) + 0xE0));
        ft_putchar((char)(((c >> 6) & 0x3F) + 0x80));
        ft_putchar((char)((c & 0x3F) + 0x80));
        res->len += 1;
    }
    else if (c <= 0x10FFFF)
    {
        ft_putchar((char)((c >> 18) + 0xF0));
        ft_putchar((char)(((c >> 12) & 0x3F) + 0x80));
        ft_putchar((char)(((c >> 6) & 0x3F) + 0x80));
        ft_putchar((char)((c & 0x3F) + 0x80));
        res->len += 1;
    }
}
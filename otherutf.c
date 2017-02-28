//
// Created by Mykola Ponomarov on 28.02.17.
//

#include "ft_printf.h"

static int write_t(wchar_t c, t_arg *res)
{
    if (c <= 0x7F && res->press >= 1)
    {
        ft_putchar((char)c);
        res->press -= 1;
        res->len += 1;
        return (1);
    }
    else if (c <= 0x7FF && res->press >= 2)
    {
        ft_putchar((char)((c >> 6) + 0xC0));
        ft_putchar((char)((c & 0x3F) + 0x80));
        res->press -= 2;
        res->len += 2;
        return (1);
    }
    else if (c <= 0xFFFF && res->press >= 3)
    {
        ft_putchar((char)((c >> 12) + 0xE0));
        ft_putchar((char)(((c >> 6) & 0x3F) + 0x80));
        ft_putchar((char)((c & 0x3F) + 0x80));
        res->press -= 3;
        res->len += 3;
        return (1);
    }
    else if (c <= 0x10FFFF && res->press >= 4)
    {
        ft_putchar((char)((c >> 18) + 0xF0));
        ft_putchar((char)(((c >> 12) & 0x3F) + 0x80));
        ft_putchar((char)(((c >> 6) & 0x3F) + 0x80));
        ft_putchar((char)((c & 0x3F) + 0x80));
        res->press -= 4;
        res->len += 4;
        return (1);
    }
    return (0);
}


void otherutf(wchar_t *tmp, t_arg *res)
{
    int i;

    i = 0;
    while ((write_t(tmp[i], res)) == 1)
        i++;
}
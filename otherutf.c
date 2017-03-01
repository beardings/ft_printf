//
// Created by Mykola Ponomarov on 28.02.17.
//

#include "ft_printf.h"

static int write_t(wchar_t c, t_arg *res)
{
    if (c <= 0x7F && res->press >= 1)
    {
        ft_putchar((char)c);
        res->len += 1;
        return (1);
    }
    else if (c <= 0x7FF && res->press >= 2)
    {
        ft_putchar((char)((c >> 6) + 0xC0));
        ft_putchar((char)((c & 0x3F) + 0x80));
        res->len += 2;
        return (2);
    }
    else if (c <= 0xFFFF && res->press >= 3)
    {
        ft_putchar((char)((c >> 12) + 0xE0));
        ft_putchar((char)(((c >> 6) & 0x3F) + 0x80));
        ft_putchar((char)((c & 0x3F) + 0x80));
        res->len += 3;
        return (3);
    }
    else if (c <= 0x10FFFF && res->press >= 4)
    {
        ft_putchar((char)((c >> 18) + 0xF0));
        ft_putchar((char)(((c >> 12) & 0x3F) + 0x80));
        ft_putchar((char)(((c >> 6) & 0x3F) + 0x80));
        ft_putchar((char)((c & 0x3F) + 0x80));
        res->len += 4;
        return (4);
    }
    return (0);
}


void otherutf(wchar_t *tmp, t_arg *res)
{
    int i;
    int k;
    int z;

    i = 0;
    k = 0;
    z = 0;
    while (tmp[i] != '\0')
    {
        if ((z = (write_t(tmp[i], res))) > 0)
        {
            k += z;
            res->press -= z;
        }
        else
            break ;
        i++;
    }
    res->press += k;
}
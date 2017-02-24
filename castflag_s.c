//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

void castflag_s(t_arg *res)
{
    char *tmp;
    int i;

    tmp = (char *)res->tmp;
    i = (int)ft_strlen(tmp);
    if (!(res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
    {
        ft_putstr(tmp);
        res->len += i;
    }
    else if ((res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
    {
        res->width -= i;
        writewidth(res);
        ft_putstr(tmp);
        res->len = res->len + res->width + i;
    }
    else if ((res->width) && (res->minus) && !(res->zero) && (res->press) == -1)
    {
        res->width -= i;
        ft_putstr(tmp);
        writewidth(res);
        res->len = res->len + res->width + i;
    }
    else if ((res->width) && (res->minus) && (res->zero) && (res->press) == -1)
    {
        res->width -= i;
        ft_putstr(tmp);
        writezero(res);
        res->len = res->len + res->width + i;
    }
    else if ((res->width) && !(res->minus) && (res->zero) && (res->press) == -1)
    {
        res->width -= i;
        writezero(res);
        ft_putstr(tmp);
        res->len = res->len + res->width + i;
    }
    else if (res->press)
        castpress_s(res, i, tmp);
    else
    {
        ft_putstr(tmp);
        res->len = res->len + i;
    }
}
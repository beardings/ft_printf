//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

int castflag_s(t_arg *res)
{
    char *tmp;
    int i;

    tmp = (char *)res->tmp;
    i = 0;
    tmp != NULL ? i = (int)ft_strlen(tmp) : 0;
    if (!(res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
    {
        (ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
        res->len += i;
    }
    else if ((res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        res->width > i ? res->width -= i, writewidth(res) : 0;
        (ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp), res->len += i;
    }
    else if ((res->width) && (res->minus) && !(res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        res->width -= i;
        (ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
        writewidth(res);
        res->len += i;
    }
    else if ((res->width) && (res->minus) && (res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        res->width -= i;
        ft_putstr(tmp);
        writezero(res);
        res->len += i;
    }
    else if ((res->width) && !(res->minus) && (res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        res->width -= i;
        writezero(res);
        (ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
        res->len += i;
    }
    else if (res->press)
        castpress_s(res, i, tmp);
    else
    {
        if (res->press == 0 && res->width > 0)
            res->zero > 0 ? writezero(res) : writewidth(res);
        else
        {
            (ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
            res->len = res->len + i;
        }
    }
    return (0);
}
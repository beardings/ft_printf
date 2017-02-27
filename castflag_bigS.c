//
// Created by Mykola Ponomarov on 27.02.17.
//

#include "ft_printf.h"


int lenwchar(wchar_t *tmp)
{
    int i;

    i = 0;
    while (tmp[i] != '\0')
        i++;
    return (i);
}

int castflag_bigS(t_arg *res)
{
    wchar_t *tmp;
    int i;

    i = 0;
    tmp = (wchar_t *)res->tmp;
    tmp != NULL ? i = lenwchar(tmp) : 0;
    if (!(res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
        (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
    else if ((res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        res->width -= i;
        writewidth(res);
        (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        res->len = res->width;
    }
    else if ((res->width) && (res->minus) && !(res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        res->width -= i;
        (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        writewidth(res);
    }
    else if ((res->width) && (res->minus) && (res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        res->width -= i;
        (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        writezero(res);
    }
    else if ((res->width) && !(res->minus) && (res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        res->width -= i;
        writezero(res);
        (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
    }
    else if (res->press)
        castpress_bigS(res, i, tmp);
    else
        (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
    return (0);
}
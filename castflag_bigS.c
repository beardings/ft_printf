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

int utflen(wchar_t *tmp)
{
    int i;
    int k;

    k = 0;
    i = 0;
    while (tmp[k] != '\0')
    {
        if (tmp[k] <= 0x7F)
            i++;
        else if (tmp[k] <= 0x7FF)
            i += 2;
        else if (tmp[k] <= 0xFFFF)
            i += 3;
        else if (tmp[k] <= 0x10FFFF)
            i += 4;
        k++;
    }
    return (i);
}

int castflag_bigS(t_arg *res)
{
    wchar_t *tmp;
    int i;
    int len;

    i = 0;
    len = 0;
    tmp = (wchar_t *)res->tmp;
    tmp != NULL ? i = lenwchar(tmp) : 0;
    tmp != NULL ? len = utflen(tmp) : 0;
    if (!(res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
        (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
    else if ((res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        if (res->width < len)
            writewidth(res);
        else
        {
            res->width -= len;
            writewidth(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
            res->len = res->width + len;
        }
    }
    else if ((res->width) && (res->minus) && !(res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        if (res->width < len)
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        else
        {
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
            res->width -= len;
            writewidth(res);
            res->len = res->width + len;
        }
    }
    else if ((res->width) && !(res->minus) && (res->zero) && (res->press) == -1)
    {
        tmp == NULL ?  res->width = res->width - 6 : 0;
        if (res->width < len)
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        else
        {
            res->width -= len;
            writezero(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
            res->len = res->width + len;
        }
    }
    else if (res->press)
        castpress_bigS(res, i, tmp, len);
    else
        (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
    return (0);
}
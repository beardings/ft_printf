//
// Created by Mykola Ponomarov on 27.02.17.
//

#include "ft_printf.h"


static int lenwchar(wchar_t *tmp)
{
    int i;

    i = 0;
    while (tmp[i] != '\0')
        i++;
    return (i);
}

static void cast_Sn(wchar_t *tmp, int i, int len, t_arg *res)
{
    tmp == NULL ?  res->width = res->width - 6 : 0;
    if (res->width < len)
        (ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
    else
    {
        res->width -= len;
        writewidth(res);
        (ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
        res->len = res->width + len;
    }
}

static void cast_Snn(wchar_t *tmp, int i, int len, t_arg *res)
{
    tmp == NULL ?  res->width = res->width - 6 : 0;
    if (res->width < len)
        (ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
    else
    {
        (ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
        res->width -= len;
        writewidth(res);
        res->len = res->width + len;
    }
}

static void cast_Snnn(wchar_t *tmp, int i, int len, t_arg *res)
{
    tmp == NULL ?  res->width = res->width - 6 : 0;
    if (res->width < len)
        (ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
    else
    {
        res->width -= len;
        writezero(res);
        (ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
        res->len = res->width + len;
    }
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
        (ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
    else if ((res->width) && !(res->minus) && !(res->zero) && (res->press) == -1)
        cast_Sn(tmp, i, len, res);
    else if ((res->width) && (res->minus) && !(res->zero) && (res->press) == -1)
        cast_Snn(tmp, i, len, res);
    else if ((res->width) && !(res->minus) && (res->zero) && (res->press) == -1)
        cast_Snnn(tmp, i, len, res);
    else if (res->press > -1)
        castpress_bigS(res, i, tmp, len);
    else
        (ft_null((char *)tmp, res, 6)) == 1 ? 0 : dowchar_t(tmp, res, i);
    return (0);
}
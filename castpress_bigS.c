//
// Created by Mykola Ponomarov on 27.02.17.
//

#include "ft_printf.h"

void castpress_bigS(t_arg *res, int i, wchar_t *tmp, int len)
{
    if (!(res->width) && !(res->minus) && !(res->zero) && (res->press) > 0)
    {
        if (res->press > len)
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        else
            otherutf(tmp, res);
    }
    else if ((res->width) && !(res->minus) && !(res->zero) && (res->press) > 0)
    {
        if (res->press > len && res->width > len)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= len;
            writewidth(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        }
        else if (res->press > len && res->width < len)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        }
        else if (res->press < len && (res->width < len || res->width > len))
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= (checkcan(tmp, res));
            writewidth(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : otherutf(tmp, res);
        }
    }
    else if ((res->width) && !(res->minus) && (res->zero) && (res->press) > 0)
    {
        if (res->press > len && res->width > len)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= len;
            writezero(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        }
        else if (res->press > len && res->width < len)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        }
        else if (res->press < len && (res->width < len || res->width > len))
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= (checkcan(tmp, res));
            writezero(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : otherutf(tmp, res);
        }
    }
    else if ((res->width) && (res->minus) && !(res->zero) && (res->press) > 0)
    {
        if (res->press > len && res->width > len)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
            res->width -= len;
            writewidth(res);
        }
        else if (res->press > len && res->width < len)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        }
        else if (res->press < len && (res->width < len || res->width > len))
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            (ft_null((char *)tmp, res)) == 1 ? 0 : otherutf(tmp, res);
            res->width -= (checkcan(tmp, res));
            writewidth(res);
        }
    }
    else
        (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
}
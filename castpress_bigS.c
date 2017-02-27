//
// Created by Mykola Ponomarov on 27.02.17.
//

#include "ft_printf.h"

void castpress_bigS(t_arg *res, int i, wchar_t *tmp)
{
    if (!(res->width) && !(res->minus) && !(res->zero) && (res->press))
    {
        if (res->press > i)
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        dowchar_t(tmp, res, res->press);
    }
    else if ((res->width) && !(res->minus) && !(res->zero) && (res->press))
    {
        if (res->press > i)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= i;
            writewidth(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        }
        else
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= res->press;
            writewidth(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, res->press);
        }
    }
    else if ((res->width) && !(res->minus) && (res->zero) && (res->press))
    {
        if (res->press > i)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= i;
            writezero(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        }
        else
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= res->press;
            writezero(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, res->press);
        }
    }
    else if ((res->width) && (res->minus) && !(res->zero) && (res->press))
    {
        if (res->press > i)
        {
            res->width -= i;
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
            writewidth(res);
        }
        else if (res->press < i && res->press != -1)
        {
            res->width -= res->press;
            dowchar_t(tmp, res, res->press);
            writewidth(res);
        }
        else if (res->press < i && res->press == -1)
        {
            dowchar_t(tmp, res, res->press);
            writewidth(res);
        }
    }
    else if (!(res->width) && (res->minus) && !(res->zero) && (res->press))
    {
        if (res->press > i)
        {
            res->width -= i;
            writezero(res);
            (ft_null((char *)tmp, res)) == 1 ? 0 : dowchar_t(tmp, res, i);
        }
        else if (res->press < i)
            dowchar_t(tmp, res, res->press);
    }
}
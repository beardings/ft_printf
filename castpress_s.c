//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

void castpress_s(t_arg *res, int i, char *tmp)
{
    if (!(res->width) && !(res->minus) && !(res->zero) && (res->press))
    {
        if (res->press > i)
        {
            (ft_null(tmp, res)) == 1 ? 0 : ft_putstr(tmp);
            res->len += i;
        }
        else
            ft_putstrnew(tmp, res->press, res);
    }
    else if ((res->width) && !(res->minus) && !(res->zero) && (res->press))
    {
        if (res->press > i)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= i;
            writewidth(res);
            (ft_null(tmp, res)) == 1 ? 0 : ft_putstr(tmp);
            res->len += i;
        }
        else
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= res->press;
            writewidth(res);
            (ft_null(tmp, res)) == 1 ? 0 :  ft_putstrnew(tmp, res->press, res);
        }
    }
    else if ((res->width) && !(res->minus) && (res->zero) && (res->press))
    {
        if (res->press > i)
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= i;
            writezero(res);
            (ft_null(tmp, res)) == 1 ? 0 : ft_putstr(tmp);
            res->len += i;
        }
        else
        {
            tmp == NULL ?  res->width = res->width - 6 : 0;
            res->width -= res->press;
            writezero(res);
            (ft_null(tmp, res)) == 1 ? 0 :  ft_putstrnew(tmp, res->press, res);
        }
    }
    else if ((res->width) && (res->minus) && !(res->zero) && (res->press))
    {
        res->press > i ? res->width -= i, ft_putstr(tmp), writewidth(res), res->len += i : 0;
        res->press < i && res->press != -1 ? res->width -= res->press, ft_putstrnew(tmp, res->press, res), writewidth(res): 0;
        res->press < i && res->press == -1 ? ft_putstrnew(tmp, res->press, res), writewidth(res) : 0;
    }
    else if (!(res->width) && (res->minus) && !(res->zero) && (res->press))
    {
        res->press > i ? res->width -= i, writezero(res), ft_putstr(tmp), res->len += i : 0;
        res->press < i ? ft_putstrnew(tmp, res->press, res) : 0;
    }
}
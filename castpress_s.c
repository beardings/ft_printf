//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

void castpress_s(t_arg *res, int i, char *tmp)
{
    if (!(res->width) && !(res->minus) && !(res->zero) && (res->press))
    {
        res->press > i ? ft_putstr(tmp) : 0;
        ft_putstrnew(tmp, i - res->press);
    }
    if ((res->width) && !(res->minus) && !(res->zero) && (res->press))
    {
        res->press > i ? res->width -= i, writewidth(res), ft_putstr(tmp), res->len = res->len + res->width + i : 0;
        res->press < i ? res->width -= res->press, writewidth(res), ft_putstrnew(tmp, res->press), res->len += res->width  + res->press: 0;
    }
    if ((res->width) && !(res->minus) && (res->zero) && (res->press))
    {
        res->press > i ? res->width -= i, writezero(res), ft_putstr(tmp), res->len = res->len + res->width + i : 0;
        res->press < i ? res->width -= res->press, writezero(res), ft_putstrnew(tmp, res->press), res->len += res->width + res->press : 0;
    }
    if ((res->width) && (res->minus) && !(res->zero) && (res->press))
    {
        res->press > i ? res->width -= i, ft_putstr(tmp), writewidth(res), res->len = res->len + res->width + i : 0;
        res->press < i && res->press != -1 ? res->width -= res->press, ft_putstrnew(tmp, res->press), writewidth(res), res->len += res->width + res->press : 0;
        res->press < i && res->press == -1 ? ft_putstrnew(tmp, res->press), writewidth(res), res->len += res->width : 0;
    }
}
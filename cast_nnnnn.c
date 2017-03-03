//
// Created by Mykola Ponomarov on 03.03.17.
//

#include "ft_printf.h"

void cast_nnnnn(int i, t_arg *res, char *tmp)
{
    if (res->press == 0 && res->width > 0)
        res->zero > 0 ? writezero(res) : writewidth(res);
    else
    {
        (ft_null(tmp, res, 6)) == 1 ? 0 : ft_putstr(tmp);
        res->len = res->len + i;
    }
}
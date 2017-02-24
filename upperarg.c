//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

void upperarg(t_arg *res)
{
    if (res->minus > 0 && res->zero > 0)
        res->zero = 0;
    if (res->plus > 0 && res->space > 0)
        res->space = 0;
}
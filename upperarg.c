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
    if (res->type == 's' && res->flag == 3)
        res->type = 'S';
    if (res->type == 'd' && res->flag == 3)
        res->type = 'D';
}
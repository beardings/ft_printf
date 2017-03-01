//
// Created by Mykola Ponomarov on 22.02.17.
//

#include "ft_printf.h"

void    *do_format(t_arg *res)
{
    upperarg(res);
    //if (res->type == 'D' || res->type == 'd' || res->type == 'i')
        //(res);
    if (res->type == 'o' || res->type == 'O')
        cast_standart_for_base(res);
    if (res->type == 'u' || res->type == 'U')
        cast_standart_for_base(res);
    if (res->type == 'x' || res->type == 'X' || res->type == 'p' )
        cast_standart_for_base(res);
    res->type == 'c' || res->type == 'C' ? castflag_c(res) : 0;
    res->type == 's' ? castflag_s(res) : 0;
    res->type == 'S' ? castflag_bigS(res) : 0;
    return (0);
}
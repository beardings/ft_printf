//
// Created by Mykola Ponomarov on 01.03.17.
//

#include "ft_printf.h"

void    cast_standart_for_base(t_arg *res)
{
    char *tmp;
    int len;

    tmp = cast_mod(res);
    len = (int)ft_strlen(tmp);
    cast_mod_base(tmp, len, res);
}
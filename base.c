//
// Created by Mykola Ponomarov on 01.03.17.
//

#include "ft_printf.h"

char *base(t_arg *res, uintmax_t mun)
{
    char *tmp;

    tmp = NULL;
    if (res->type == 'o' || res->type == 'O')
        tmp = ft_itoa_base(mun, 8, res);
    if (res->type == 'u' || res->type == 'U')
        tmp = ft_itoa_base(mun, 10, res);
    if (res->type == 'x' || res->type == 'X' || res->type == 'p')
        tmp = ft_itoa_base(mun, 16, res);
    return (tmp);
}
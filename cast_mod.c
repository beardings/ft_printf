//
// Created by Mykola Ponomarov on 01.03.17.
//

#include "ft_printf.h"

char    *cast_mod(t_arg *res)
{
    uintmax_t mun;
    char *tmp;

    if (res->flag == 1 && res->type != 'U'  && res->type != 'O' && res->type != 'p')
        mun = (unsigned char)res->tmp;
    else if (res->flag == 2 && res->type != 'U'  && res->type != 'O' && res->type != 'p')
        mun = (unsigned short)res->tmp;
    else if (res->flag == 3 && res->type != 'p')
        mun = (unsigned long)res->tmp;
    else if (res->flag == 4 && res->type != 'p')
        mun = (unsigned long long)res->tmp;
    else if (res->flag == 5 && res->type != 'p')
        mun = (uintmax_t)res->tmp;
    else if (res->flag == 6 && res->type != 'p')
        mun = (size_t)res->tmp;
    else if (res->type == 'x' || res->type == 'o' || res->type == 'u' || res->type == 'X')
        mun = (unsigned int)res->tmp;
    else
        mun = (unsigned long)res->tmp;
    if (mun == 4294967296 && res->type == 'X' && res->flag < 3)
        mun = 0;
    if (res->type == 'p')
        mun = (uintmax_t)res->tmp;
    tmp = base(res, mun);
    return (tmp);
}
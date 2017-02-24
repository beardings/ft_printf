//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

void writezero(t_arg *res)
{
    int i;

    i = 0;
    while (i < res->width && res->width > 0)
    {
        ft_putnbr(0);
        res->len += 1;
        i++;
    }
}
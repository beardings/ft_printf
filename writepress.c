//
// Created by Mykola Ponomarov on 27.02.17.
//

#include "ft_printf.h"

void writepress(t_arg *res)
{
    int i;

    i = 0;
    while (i < res->press && res->press > 0)
    {
        ft_putnbr(0);
        res->len += 1;
        i++;
    }
}
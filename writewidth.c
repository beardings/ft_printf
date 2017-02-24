//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

void writewidth(t_arg *res)
{
    int i;

    i = 0;
    while (i < res->width && res->width > 0)
    {
        write (1, " ", 1);
        res->len += 1;
        i++;
    }
}
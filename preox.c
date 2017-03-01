//
// Created by Mykola Ponomarov on 01.03.17.
//

#include "ft_printf.h"

void preox(t_arg *res)
{
    write (1, "0", 1);
    write (1, "x", 1);
    res->len += 2;
}
//
// Created by Mykola Ponomarov on 26.02.17.
//

#include "ft_printf.h"

int ft_null(char *tmp, t_arg *res)
{
    if (tmp == NULL)
    {
        write(1, "(null)", 6);
        res->len += 4;
        return (1);
    }
    return (0);
}
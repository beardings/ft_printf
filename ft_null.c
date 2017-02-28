//
// Created by Mykola Ponomarov on 26.02.17.
//

#include "ft_printf.h"

int ft_null(char *tmp, t_arg *res, int len)
{
    if (tmp == NULL)
    {
        write(1, "(null)", len);
        res->len += len;
        return (1);
    }
    return (0);
}
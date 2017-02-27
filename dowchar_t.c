//
// Created by Mykola Ponomarov on 27.02.17.
//

#include "ft_printf.h"

void dowchar_t(wchar_t *tmp, t_arg *res, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        writewchar_t(tmp[i], res);
        i++;
    }
}
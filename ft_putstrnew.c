//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

void ft_putstrnew(char *tmp, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        write(1, &tmp[i], 1);
        i++;
    }
}
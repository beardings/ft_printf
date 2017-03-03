//
// Created by Mykola Ponomarov on 03.03.17.
//

#include "ft_printf.h"

int utflen(wchar_t *tmp)
{
    int i;
    int k;

    k = 0;
    i = 0;
    while (tmp[k] != '\0')
    {
        if (tmp[k] <= 0x7F)
            i++;
        else if (tmp[k] <= 0x7FF)
            i += 2;
        else if (tmp[k] <= 0xFFFF)
            i += 3;
        else if (tmp[k] <= 0x10FFFF)
            i += 4;
        k++;
    }
    return (i);
}
//
// Created by Mykola Ponomarov on 01.03.17.
//

#include "ft_printf.h"

static int utflen(wchar_t c)
{
    int i;

    i = 0;
    if (c <= 0x7F)
        i++;
    else if (c <= 0x7FF)
        i += 2;
    else if (c <= 0xFFFF)
        i += 3;
    else if (c <= 0x10FFFF)
        i += 4;
    return (i);
}


void    castflag_bigC(t_arg *res)
{
    wchar_t c;
    int i;

    c = (wchar_t)res->tmp;
    i = utflen(c);
    if (!(res->width) && !(res->minus) && !(res->zero))
        writewchar_t(c, res);
    else if ((res->width) && !(res->minus) && !(res->zero))
    {
        res->width -= i;
        writewidth(res);
        writewchar_t(c, res);
    }
    else if ((res->width) && (res->minus) && !(res->zero))
    {
        writewchar_t(c, res);
        res->width -= i;
        writewidth(res);
    }
    else if ((res->width) && !(res->minus) && (res->zero))
    {
        res->width -= i;
        writezero(res);
        writewchar_t(c, res);
    }
    else
        writewchar_t(c, res);
}
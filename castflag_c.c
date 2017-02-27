//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

void    castflag_c(t_arg *res)
{
    unsigned char c;

    c = (unsigned char)res->tmp;
    if (!(res->width) && !(res->minus) && !(res->zero))
    {
        write (1, &c, 1);
        res->len = res->len + 1;
    }
    else if ((res->width) && !(res->minus) && !(res->zero))
    {
        res->width -= 1;
        writewidth(res);
        write (1, &c, 1);
        res->len = res->width + 1;
    }
    else if ((res->width) && (res->minus) && !(res->zero))
    {
        write (1, &c, 1);
        res->width -= 1;
        writewidth(res);
        res->len = res->width + 1;
    }
    else if ((res->width) && !(res->minus) && (res->zero))
    {
        res->width -= 1;
        writezero(res);
        write(1, &c, 1);
        res->len = res->width + 1;
    }
    else
    {
        write (1, &c, 1);
        res->len = res->len + 1;
    }
}

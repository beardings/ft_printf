//
// Created by Mykola Ponomarov on 24.02.17.
//

#include "ft_printf.h"

void    castflag_c(t_arg *res)
{
    unsigned char c;
    unsigned long C;

    if (res->type == 'c')
        c = (unsigned char)res->tmp;
    else
        C = (unsigned long)res->type;
    if (!(res->width) && !(res->minus) && !(res->zero))
    {
        res->type == 'c' ? write (1, &c, 1) : write (1, &C, 1);
        res->len = res->len + 1;
    }
    else if ((res->width) && !(res->minus) && !(res->zero))
    {
        res->width -= 1;
        writewidth(res);
        res->type == 'c' ? write (1, &c, 1) : write (1, &C, 1);
        res->len = res->width + 1;
    }
    else if ((res->width) && (res->minus) && !(res->zero))
    {
        res->type == 'c' ? write (1, &c, 1) : write (1, &C, 1);
        res->width -= 1;
        writewidth(res);
        res->len = res->width + 1;
    }
    else if ((res->width) && !(res->minus) && (res->zero))
    {
        res->width -= 1;
        writezero(res);
        res->type == 'c' ? write (1, &c, 1) : write (1, &C, 1);
        res->len = res->width + 1;
    }
    else
    {
        res->type == 'c' ? write (1, &c, 1) : write (1, &C, 1);
        res->len = res->len + 1;
    }
}

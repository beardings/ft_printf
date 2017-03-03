//
// Created by Mykola Ponomarov on 03.03.17.
//

#include "ft_printf.h"

static void numnull_next(t_arg *res)
{
    res->plus > 0 ? write (1, "+", 1), res->width -= 1 : 0;
    if (res->press > 1)
    {
        res->space > 0 ? res->width -= res->press + 1 : 0;
        res->space == 0 ? res->width -= res->press : 0;
    }
    else
    {
        res->space == 0 && res->press != 0 ? res->width -= 1 : 0;
        res->space > 0 ? res->width -= 1 + 1 : 0;
    }
    res->space > 0 ? write (1, " ", 1), res->len++ : 0;
    res->press > 0 && res->width < 1 ? res->press -= 1, writepress(res) : 0;
    if (res->width > 0 && (res->zero == 0 || (res->press == 0 && res->zero == 1)))
    {
        writewidth(res);
        res->width -= res->width;
    }
    res->press == -1 && res->zero > 0 ? writezero(res) : 0;
    res->press == 0 && res->zero == 0 ? writewidth(res) : 0;
    res->press == -1 && res->zero == 0 ? writewidth(res) : 0;
    res->press > 0 && res->width > 0 ? writewidth(res) : 0;
    res->plus == 0 && res->press != 0 ? res->len += 1 : 0;
    res->press > 0 && res->zero > 0 ? res->press -= 1, writepress(res) : 0;
    res->plus != 0 ? res->len += 1 + 1 : 0;
    res->press != 0 ? ft_putnbr(0) : 0;
}

int  numnull(t_arg *res)
{
    if (res->minus > 0)
    {
        if (res->space > 0)
        {
            write (1, " ", 1);
            res->width -= 1;
            res->len++;
        }
        if (res->plus > 0)
        {
            write (1, "+", 1);
            res->width -= 1;
            res->len++;
        }
        if (res->press > 1)
            res->width -= res->press;
        else
            res->width -= 1;
        res->press -= 1;
        writepress(res);
        ft_putnbr(0);
        res->len += 1;
        res->press > 1 && res->zero > 0 ? writezero(res) : writewidth(res);
    }
    else
        numnull_next(res);
    return (0);
}
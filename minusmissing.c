//
// Created by Mykola Ponomarov on 03.03.17.
//

#include "ft_printf.h"

static void minus_next(t_arg *res, intmax_t len, intmax_t num)
{
    if (res->minus == 0 && num < 0)
    {
        res->zero > 0 && res->press == -1 ? write (1, "-", 1), res->len += 1 : 0;
        if (res->press > len)
            res->width -= 1 + res->press;
        else
            res->width -= len + 1;
        res->press == -1 && res->zero > 0 ? writezero(res) : writewidth(res);
        res->zero == 0 || res->press > 0 ? write (1, "-", 1), res->len += 1 : 0;
        res->press -= len;
        writepress(res);
        ft_putnbr_new(num, res);
        res->len += len;
    }
}

void minusmissing(t_arg *res, intmax_t len, intmax_t num)
{
    if (res->minus == 0 && num > 0)
    {
        res->zero > 0 && res->press == -1 && res->plus > 0 ? write (1, "+", 1), res->width -= 1 : 0;
        if (res->press > len)
        {
            res->space > 0 ? res->width -= res->press + 1 : 0;
            res->space == 0 ? res->width -= res->press : 0;
        }
        else
        {
            res->space == 0 ? res->width -= len : 0;
            res->space > 0 ? res->width -= len + 1 : 0;
        }
        res->space > 0 ? write (1, " ", 1), res->len++ : 0;
        (res->zero == 0 || res->press > 0) && res->plus > 0 ? res->width -= 1 : 0;
        res->press == -1 && res->zero > 0 ? writezero(res) : writewidth(res);
        (res->zero == 0 || res->press > 0) && res->plus > 0 ? write (1, "+", 1) : 0;
        res->press -= len;
        writepress(res);
        ft_putnbr_new(num, res);
        res->plus == 0 ? res->len += len : 0;
        res->plus != 0 ? res->len += len + 1 : 0;
    }
    minus_next(res, len, num);
}
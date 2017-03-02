//
// Created by Mykola Ponomarov on 22.02.17.
//

#include "ft_printf.h"

void cast_forlenth(t_arg *res)
{
    intmax_t num;

    upperarg(res);
    if (res->flag == 1)
        num = (char)res->tmp;
    else if (res->flag == 2)
        num = (short)res->tmp;
    else if (res->flag == 3)
        num = (long)res->tmp;
    else if (res->flag == 4)
        num = (long long)res->tmp;
    else if (res->flag == 5)
        num = (intmax_t)res->tmp;
    else if (res->flag == 6)
        num = (size_t)res->tmp;
    else if (res->type == 'd' || res->type == 'i')
        num = (int)res->tmp;
    else
        num = (long)res->tmp;
    finishd(num, res);
}

intmax_t lenintmax(intmax_t num)
{
    intmax_t i;

    i = 0;
    while (num)
    {
        num = num / 10;
        i++;
    }
    return (i);
}

void	ft_putnbr_new(intmax_t n, t_arg *res)
{
    intmax_t nb;

    if (n < 0)
    {
        nb = -n;
        res->len += 1;
    }
    else
        nb = n;
    if (nb < 10)
        ft_putchar('0' + nb);
    else
    {
        ft_putnbr_new(nb / 10, res);
        ft_putnbr_new(nb % 10, res);
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
    if (res->minus == 0 && num < 0)
    {
        res->zero > 0 && res->press == -1 ? write (1, "-", 1) : 0;
        if (res->press > len)
            res->width -= 1 + res->press;
        else
            res->width -= len + 1;
        res->press == -1 && res->zero > 0 ? writezero(res) : writewidth(res);
        res->zero == 0 || res->press > 0 ? write (1, "-", 1) : 0;
        res->press -= len;
        writepress(res);
        ft_putnbr_new(num, res);
        res->len += len;
    }
}


void minuspresent(t_arg *res, intmax_t len, intmax_t num)
{
    if (res->minus > 0 && num > 0)
    {
        res->plus > 0 ? write (1, "+", 1), res->width -= 1 : 0;
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
        res->press -= len;
        writepress(res);
        ft_putnbr_new(num, res);
        res->press == -1 ? writezero(res) : writewidth(res);
        res->plus == 0 ? res->len += len : 0;
        res->plus != 0 ? res->len += len + 1 : 0;
    }
    if (res->minus > 0 && num < 0)
    {
        write (1, "-", 1);
        if (res->press > len)
            res->width -= 1 + res->press;
        else
            res->width -= len + 1;
        res->press -= len;
        writepress(res);
        ft_putnbr_new(num, res);
        res->press > len && res->zero > 0 ? writezero(res) : writewidth(res);
        res->len += len;
    }
}

int  numnull(t_arg *res)
{
    res->space > 0 && res->width > 0 ? write (1 , " ", 1), res->width -= 1, res->len += 1 : 0;
    if (res->width > 0 && res->press < 1 )
    {
        res->zero > 0 && res->press != 0 ? writezero(res) : writewidth(res);
        res->width -= res->width;
    }
    if (res->width > 0 && res->press > 1)
    {
        res->width -= res->press;
        writewidth(res);
    }
    if (res->plus > 0)
    {
        write (1, "+", 1);
        res->len++;
        res->width -= 1;
    }
    if (res->press > 1 && res->press--)
        writepress(res);
    res->plus > 0 && res->width > 1 && res->zero > 0 ? res->width -=  1 : 0;
    res->plus > 0 && res->width < 1 && res->zero > 0 ? writezero(res) : 0;
    res->plus == 0 ? res->width -= res->press: 0;
    if ((res->press == 0 || res->press == -1) && res->width == 0 && res->plus == 0)
        return (0);
    else
    {
        ft_putnbr(0);
        res->len += 1;
    }
    return (0);
}

void  finishd(intmax_t num, t_arg *res)
{
    intmax_t len;

    len = lenintmax(num);
    if (res->minus == 0 && num != 0)
        minusmissing(res, len, num);
    if (res->minus != 0 && num != 0)
        minuspresent(res, len, num);
    if (num == 0)
        numnull(res);

}

void    *do_format(t_arg *res)
{
    upperarg(res);
    if (res->type == 'D' || res->type == 'd' || res->type == 'i')
        cast_forlenth(res);
    if (res->type == 'o' || res->type == 'O')
        cast_standart_for_base(res);
    if (res->type == 'u' || res->type == 'U')
        cast_standart_for_base(res);
    if (res->type == 'x' || res->type == 'X' || res->type == 'p' )
        cast_standart_for_base(res);
    res->type == 'c' || res->type == 'C' ? castflag_c(res) : 0;
    res->type == 's' ? castflag_s(res) : 0;
    res->type == 'S' ? castflag_bigS(res) : 0;
    return (0);
}
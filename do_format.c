//
// Created by Mykola Ponomarov on 22.02.17.
//

#include "ft_printf.h"

char *base(t_arg *res, uintmax_t mun)
{
    char *tmp;

    tmp = NULL;
    if (res->type == 'o' || res->type == 'O')
        tmp = ft_itoa_base(mun, 8, res);
    if (res->type == 'u' || res->type == 'U')
        tmp = ft_itoa_base(mun, 10, res);
    if (res->type == 'x' || res->type == 'X')
        tmp = ft_itoa_base(mun, 16, res);
    return (tmp);
}

char    *cast_mod(t_arg *res)
{
    uintmax_t mun;
    char *tmp;

    if (res->flag == 1)
        mun = (unsigned char)res->tmp;
    else if (res->flag == 2)
        mun = (unsigned short)res->tmp;
    else if (res->flag == 3)
        mun = (unsigned long)res->tmp;
    else if (res->flag == 4)
        mun = (unsigned long long)res->tmp;
    else if (res->flag == 5)
        mun = (uintmax_t)res->tmp;
    else if (res->flag == 6)
        mun = (size_t)res->tmp;
    else if (res->type == 'x' || res->type == 'o' || res->type == 'u')
        mun = (unsigned int)res->tmp;
    else
        mun = (unsigned long)res->tmp;
    tmp = base(res, mun);
    return (tmp);
}

void writepress(t_arg *res)
{
    int i;

    i = 0;
    while (i < res->press && res->press > 0)
    {
        ft_putnbr(0);
        res->len += 1;
        i++;
    }
}


void cast_mod_base(char *tmp, int len, t_arg *res)
{
    if (!(res->width) && (res->press) == -1 && !(res->zero) && !(res->minus) && !(res->hesh))
    {
        res->len += len;
        ft_putstr(tmp);
    }
    else if ((res->width) && (res->press) == -1 && !(res->zero) && !(res->minus) && !(res->hesh))
    {
        res->width -= len;
        writewidth(res);
        ft_putstr(tmp);
        res->len += res->width + len;
    }
    else if ((res->width) && (res->press) && !(res->zero) && !(res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->width -= res->press;
            writewidth(res);
            res->width = res->press - len;
            writezero(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->width -= len;
            writewidth(res);
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if ((res->width) && (res->press) && (res->zero) && !(res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->width -= res->press;
            writewidth(res);
            res->width = res->press - len;
            writezero(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->width -= len;
            writezero(res);
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if ((res->width) && (res->press) && !(res->zero) && (res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->width -= res->press + len;
            writewidth(res);
            res->len += len;
        }
        else
        {
            ft_putstr(tmp);
            res->width -= len;
            writewidth(res);
            res->len += len;
        }
    }
    else if ((res->width) && (res->press) && !(res->zero) && (res->minus) && (res->hesh))
    {
        if (res->press > len)
        {
            printhesh(res);
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->width -= res->press + len + res->hesh;
            writewidth(res);
            res->len += len;
        }
        else
        {
            printhesh(res);
            ft_putstr(tmp);
            res->width -= len + res->hesh;
            writewidth(res);
            res->len += len;
        }
    }
}

void    cast_standart_for_base(t_arg *res)
{
    char *tmp;
    int len;

    tmp = cast_mod(res);
    len = (int)ft_strlen(tmp);
    cast_mod_base(tmp, len, res);
}

void    *do_format(t_arg *res)
{
    upperarg(res);
    //if (res->type == 'D' || res->type == 'd' || res->type == 'i')
        //(res);
    if (res->type == 'o' || res->type == 'O')
        cast_standart_for_base(res);
    if (res->type == 'u' || res->type == 'U')
        cast_standart_for_base(res);
    if (res->type == 'x' || res->type == 'X')
        cast_standart_for_base(res);
    res->type == 'c' || res->type == 'C' ? castflag_c(res) : 0;
    res->type == 's' ? castflag_s(res) : 0;
    //res->type == 'p' ? castflag_p(res) : 0;
    //res->type == 'S' ? castflag_S(res) : 0;
    return (0);
}
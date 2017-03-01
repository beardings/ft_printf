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
    if (res->type == 'x' || res->type == 'X' || res->type == 'p')
        tmp = ft_itoa_base(mun, 16, res);
    return (tmp);
}

char    *cast_mod(t_arg *res)
{
    uintmax_t mun;
    char *tmp;

    if (res->flag == 1 && res->type != 'U' && res->type != 'X' && res->type != 'O' && res->type != 'p')
        mun = (unsigned char)res->tmp;
    else if (res->flag == 2 && res->type != 'U' && res->type != 'X' && res->type != 'O' && res->type != 'p')
        mun = (unsigned short)res->tmp;
    else if (res->flag == 3 && res->type != 'p')
        mun = (unsigned long)res->tmp;
    else if (res->flag == 4 && res->type != 'p')
        mun = (unsigned long long)res->tmp;
    else if (res->flag == 5 && res->type != 'p')
        mun = (uintmax_t)res->tmp;
    else if (res->flag == 6 && res->type != 'p')
        mun = (size_t)res->tmp;
    else if (res->type == 'x' || res->type == 'o' || res->type == 'u' || res->type == 'X')
        mun = (unsigned int)res->tmp;
    else
        mun = (unsigned long)res->tmp;
    if (mun == 4294967296 && res->type == 'X' && res->flag < 3)
        mun = 0;
    if (res->type == 'p')
        mun = (uintmax_t)res->tmp;
    tmp = base(res, mun);
    return (tmp);
}


void preox(t_arg *res)
{
    write (1, "0", 1);
    write (1, "x", 1);
    res->len += 2;
}

int cast_mod_base(char *tmp, int len, t_arg *res)
{
    if (res->press == -1 && res->zero == 2 && tmp[0] == '0' && tmp[1] == '\0')
    {
        ft_putstr(tmp);
        res->len += len;
    }
    else if (!(res->width) && (res->press) == -1 && !(res->zero) && !(res->minus) && !(res->hesh))
    {
        res->len += len;
        res->type == 'p' ? preox(res): 0;
        ft_putstr(tmp);
    }
    else if ((res->width) && (res->press) == -1 && !(res->zero) && !(res->minus) && !(res->hesh))
    {
        res->type == 'p' ? preox(res): 0;
        res->width -= len;
        writewidth(res);
        if ((tmp[0] == '0' && tmp[1] == '\0') && (res->type == 'x' || res->type == 'o' || res->type == 'u'))
            write (1, " ", 1);
        else
            ft_putstr(tmp);
        res->len += len;
    }
    else if ((res->width) && (res->press)  && !(res->zero) && !(res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            res->width -= res->press;
            writewidth(res);
            res->width = res->press - len;
            writezero(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? res->width -= len + 2 : 0;
            writewidth(res);
            res->type == 'p' ? preox(res) : 0;
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if ((res->width) && (res->press) && (res->zero) && !(res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            res->width -= res->press;
            writewidth(res);
            res->width = res->press - len;
            writezero(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? res->width -= len + 2 : 0;
            res->type != 'p' ? res->width -= len : 0;
            tmp[0] != '0' && tmp[1] != '\0' && res->type != 'p' ? writezero(res) : writewidth(res);
            if ((tmp[0] == '0' && tmp[1] == '\0') && (res->type == 'x' || res->type == 'o' || res->type == 'u'))
                write (1, " ", 1);
            else
            {
                res->type == 'p' ? preox(res) : 0;
                ft_putstr(tmp);
            }
            res->len += len;
        }
    }
    else if ((res->width) && (res->press) && !(res->zero) && (res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->width -= res->press + len;
            writewidth(res);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? preox(res) : 0;
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
            res->type == 'p' ? preox(res): 0;
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
            res->type == 'p' ? preox(res) : 0;
            printhesh(res);
            ft_putstr(tmp);
            res->width -= len + res->hesh;
            writewidth(res);
            res->len += len;
        }
    }
    else if (!(res->width) && (res->press) && !(res->zero) && !(res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? preox(res) : 0;
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if (!(res->width) && (res->press) && (res->zero) && !(res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? preox(res) : 0;
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if (!(res->width) && (res->press) && !(res->zero) && (res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? preox(res) : 0;
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if (!(res->width) && (res->press) && !(res->zero) && (res->minus) && (res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            printhesh(res);
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? preox(res) : 0;
            printhesh(res);
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if (!(res->width) && (res->press) && (res->zero) && !(res->minus) && (res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? preox(res) : 0;
            tmp[0] != '0' ? printhesh(res): 0;
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if (!(res->width) && (res->press) == -1 && !(res->zero) && !(res->minus) && (res->hesh))
    {
        res->type == 'p' ? preox(res) : 0;
        tmp[0] != '0' ? printhesh(res): 0;
        ft_putstr(tmp);
        res->len += len;
    }
    else if ((res->width) && (res->press) == -1 && !(res->zero) && !(res->minus) && (res->hesh))
    {
        if (res->type == 'x' || res->type == 'X')
            res->width -= len + res->hesh + 1;
        else if (res->type != 'p')
            res->width -= len + res->hesh;
        res->type == 'p' ? preox(res) : 0;
        writewidth(res);
        printhesh(res);
        ft_putstr(tmp);
        res->len += len;
    }
    else if ((res->width) && (res->press) && !(res->zero) && !(res->minus) && (res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            printhesh(res);
            res->press -= len;
            //res->width -= len + res->press;
            //writezero(res);
            writepress(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            if (res->type == 'x' || res->type == 'X' || res->type != 'p')
                res->width -= len + res->hesh + 1;
            else if (res->type != 'p')
                res->width -= len + res->hesh;
            res->type == 'p' ? preox(res) : 0;
            writewidth(res);
            printhesh(res);
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if ((res->width) && (res->press) > -1 && (res->zero) && !(res->minus) && (res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            printhesh(res);
            if (res->type != 'o' || res->type != 'O' || res->type != 'u' || res->type != 'U' || res->type != 'p')
                res->width += res->hesh - 1;
            if (res->type != 'x' && res->type != 'X' && res->type != 'p')
            {
                res->width -= res->press;
                writewidth(res);
            }
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            if (res->type != 'o' || res->type != 'O' || res->type != 'u' || res->type != 'U' || res->type != 'p')
                res->width += res->hesh + 1;
            res->type != 'p' ? res->width -= len + res->hesh + 3 : 0;
            res->type == 'p' ? preox(res) : 0;
            writewidth(res);
            printhesh(res);
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if (!(res->width) && (res->press) && !(res->zero) && !(res->minus) && (res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' ? preox(res) : 0;
            printhesh(res);
            res->press -= len;
            writepress(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? preox(res) : 0;
            printhesh(res);
            ft_putstr(tmp);
            res->len += len;
        }
    }
    else if ((res->width) && (res->press) == -1 && (res->zero) && !(res->minus) && (res->hesh))
    {
        res->type == 'p' ? preox(res) : 0;
        printhesh(res);
        if (res->type != 'x' && res->type != 'X' && res->type != 'p')
        {
            res->width -= len;
            writewidth(res);
        }
        else if (res->type != 'p' && (res->type == 'x' || res->type == 'X'))
        {
            res->width -= len + res->hesh;
            writezero(res);
        }
        res->type == 'p' ? preox(res) : 0;
        ft_putstr(tmp);
        res->len += len;
    }
    else if (!(res->width) && (res->press) == 0 && !(res->zero) && !(res->minus) && (res->hesh))
    {
        res->type == 'p' ? preox(res) : 0;
        res->type != 'x' ? printhesh(res) : 0;
        tmp[0] != '0' ? ft_putstr(tmp), res->len += len : 0;

    }
    else if (!(res->width) && (res->press) == 0 && (res->zero) && !(res->minus) && (res->hesh))
    {
        res->type == 'p' ? preox(res) : 0;
        res->type != 'x' ? printhesh(res) : 0;
        tmp[0] != '0' ? ft_putstr(tmp), res->len += len : 0;

    }
    else if ((res->width) && (res->press) == 0 && !(res->zero) && !(res->minus) && !(res->hesh))
    {
        res->type == 'p' ? preox(res) : 0;
        writewidth(res);
        tmp[0] != '0' ? ft_putstr(tmp), res->len += len : 0;
    }
    else if ((res->width) && (res->press) == 0 && (res->zero) && !(res->minus) && !(res->hesh))
    {
        res->type == 'p' ? preox(res) : 0;
        writewidth(res);
        tmp[0] != '0' ? ft_putstr(tmp), res->len += len : 0;
    }
    else if (!(res->width) && (res->press) == 0 && !(res->minus) && !(res->hesh))
    {
        res->type == 'p' ? preox(res) : 0;
        res->zero > 0 ? writezero(res) : writewidth(res);
        tmp[0] != '0' ? ft_putstr(tmp), res->len += len : 0;
    }
    return (0);
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
    if (res->type == 'x' || res->type == 'X' || res->type == 'p' )
        cast_standart_for_base(res);
    res->type == 'c' || res->type == 'C' ? castflag_c(res) : 0;
    res->type == 's' ? castflag_s(res) : 0;
    res->type == 'S' ? castflag_bigS(res) : 0;
    return (0);
}
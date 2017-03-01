//
// Created by Mykola Ponomarov on 01.03.17.
//

#include "ft_printf.h"

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
        res->type == 'p' ? res->width -= len + 2 : 0;
        res->type != 'p' ? res->width -= len : 0;
        writewidth(res);
        res->type == 'p' ? preox(res): 0;
        ft_putstr(tmp);
        res->len += len;
    }
    else if ((res->width) && (res->press)  && !(res->zero) && !(res->minus) && !(res->hesh))
    {
        if (res->press > len)
        {
            res->type == 'p' && tmp[0] == '0' ? res->width -= 2 : 0;
            res->type == 'p' && tmp[0] != '0' ? res->width -= len + 2 : 0;
            res->width -= res->press;
            writewidth(res);
            res->width = res->press - len;
            res->type == 'p' ? preox(res) : 0;
            writezero(res);
            ft_putstr(tmp);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? res->width -= len + 2 : 0;
            res->type != 'p' ?res->width -= len : 0;
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
            if ((tmp[0] == '0' && tmp[1] == '\0') && (res->type == 'x' || res->type == 'o' || res->type == 'u'))
                write (1, " ", 1);
            else
            {
                res->type == 'p' ? preox(res) : 0;
                writezero(res);
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
            res->type == 'p' ? res->width -= len + 2 : 0;
            res->type != 'p' ? res->width -= len : 0;
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
            res->type != 'p' ? res->width -= res->press + len + res->hesh : 0;
            res->type == 'p' ? res->width -= res->press + len : 0;
            writewidth(res);
            res->len += len;
        }
        else
        {
            res->type == 'p' ? preox(res) : 0;
            printhesh(res);
            ft_putstr(tmp);
            res->type != 'p' ? res->width -= len + res->hesh : 0;
            res->type == 'p' ? res->width -= len + 2 : 0;
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
        res->type == 'p' ? res->width -= len + 2: 0;
        writewidth(res);
        printhesh(res);
        res->type == 'p' ? preox(res) : 0;
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
            res->type == 'p' ? res->width -= len + 2 : 0;
            writewidth(res);
            printhesh(res);
            res->type == 'p' ? preox(res) : 0;
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
            if (res->type != 'o' && res->type != 'O' && res->type != 'u' && res->type != 'U' && res->type != 'p')
                res->width += res->hesh + 1;
            res->type != 'p' ? res->width -= len + res->hesh + 3 : 0;
            res->type == 'p' ? res->width -= len + 2: 0;
            writewidth(res);
            res->type == 'p' ? preox(res) : 0;
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
        res->type == 'p' ? res->width -= len + 2: 0;
        res->type == 'p' ? writezero(res) : 0;
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
        res->type == 'p' && tmp[0] == '0' ? res->width -= 2 : 0;
        res->type == 'p' && tmp[0] != '0' ? res->width -= len + 2 : 0;
        res->type != 'p' && tmp[0] != '0' ? res->width -= len  : 0;
        writewidth(res);
        res->type == 'p' ? preox(res) : 0;
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
//
// Created by Mykola Ponomarov on 22.02.17.
//

#include "ft_printf.h"

void upperarg(t_arg *res)
{
    if (res->minus > 0 && res->zero > 0)
        res->zero = 0;
    if (res->plus > 0 && res->space > 0)
        res->space = 0;
}

uintmax_t castarg_uint_m()
{
    return (0);
}

/*intmax_t castflag(t_arg *res)
{
    intmax_t num;

    num = 0;
    if (res->flag == 1)
        num = (char)res->tmp;
    if (res->flag == 2)
        num = (short)res->tmp;
    if (res->flag == 3)
        num = (long)res->tmp;
    if (res->flag == 4)
        num = (long long)res->tmp;
    if (res->flag == 5)
        num = (intmax_t)res->tmp;
    if (res->flag == 6)
        num = (size_t)res->tmp;
    return (num);
}*/

intmax_t castarg_int_m()
{
    //intmax_t num;

    /*if (res->type == 'D')
    {
        res->flag > 0 ? num = castflag(res) : num = (long)res->tmp;
        return (num);
    }
    else
    {
        res->flag > 0 ? num = castflag(res) : num = (int)res->tmp;
        return (num);
    }*/
    return (0);
}

void writezero(t_arg *res)
{
    int i;

    i = 0;
    while (i < res->width)
    {
        ft_putnbr(0);
        i++;
    }
}

void writewidth(t_arg *res)
{
    int i;

    i = 0;
    while (i < res->width)
    {
        write (1, " ", 1);
        i++;
    }
}
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
        write(1, &c, 1);
        res->len = res->len + res->width + 1;
    }
    else if ((res->width) && (res->minus) && !(res->zero))
    {
        write(1, &c, 1);
        res->width -= 1;
        writewidth(res);
        res->len = res->len + res->width + 1;
    }
    else if ((res->width) && !(res->minus) && (res->zero))
    {
        res->width -= 1;
        writezero(res);
        write(1, &c, 1);
        res->len = res->len + res->width + 1;
    }
    else
    {
        write (1, &c, 1);
        res->len = res->len + 1;
    }
}

void ft_putstrnew(char *tmp, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        write(1, &tmp[i], 1);
        i++;
    }
}

void castpress(t_arg *res, int i, char *tmp)
{
    if (!(res->width) && !(res->minus) && !(res->zero) && (res->press))
    {
        res->press > i ? ft_putstr(tmp) : 0;
        ft_putstrnew(tmp, i - res->press);
    }
    if ((res->width) && !(res->minus) && !(res->zero) && (res->press))
    {
        res->press > i ? res->width -= i, writewidth(res), ft_putstr(tmp), res->len = res->len + res->width + i : 0;
        res->press < i ? res->width -= res->press, writewidth(res), ft_putstrnew(tmp, res->press), res->len += res->width  + res->press: 0;
    }
    if ((res->width) && !(res->minus) && (res->zero) && (res->press))
    {
        res->press > i ? res->width -= i, writezero(res), ft_putstr(tmp), res->len = res->len + res->width + i : 0;
        res->press < i ? res->width -= res->press, writezero(res), ft_putstrnew(tmp, res->press), res->len += res->width + res->press : 0;
    }
    if ((res->width) && (res->minus) && !(res->zero) && (res->press))
    {
        res->press > i ? res->width -= i, ft_putstr(tmp), writewidth(res), res->len = res->len + res->width + i : 0;
        res->press < i && res->press != -1 ? res->width -= res->press, ft_putstrnew(tmp, res->press), writewidth(res), res->len += res->width + res->press : 0;
        res->press < i && res->press == -1 ? ft_putstrnew(tmp, res->press), writewidth(res), res->len += res->width : 0;
    }
}


void castflag_s(t_arg *res)
{
    char *tmp;
    int i;

    tmp = (char *)res->tmp;
    i = (int)ft_strlen(tmp);
    if (!(res->width) && !(res->minus) && !(res->zero) && !(res->press))
    {
        ft_putstr(tmp);
        res->len += i;
    }
    else if ((res->width) && !(res->minus) && !(res->zero) && !(res->press))
    {
        res->width -= i;
        writewidth(res);
        ft_putstr(tmp);
        res->len = res->len + res->width + i;
    }
    else if ((res->width) && (res->minus) && !(res->zero) && !(res->press))
    {
        res->width -= i;
        ft_putstr(tmp);
        writewidth(res);
        res->len = res->len + res->width + i;
    }
    else if ((res->width) && (res->minus) && (res->zero) && !(res->press))
    {
        res->width -= i;
        ft_putstr(tmp);
        writezero(res);
        res->len = res->len + res->width + i;
    }
    else if ((res->width) && !(res->minus) && (res->zero) && !(res->press))
    {
        res->width -= i;
        writezero(res);
        ft_putstr(tmp);
        res->len = res->len + res->width + i;
    }
    else if (res->press)
        castpress(res, i, tmp);
    else
    {
        ft_putstr(tmp);
        res->len = res->len + i;
    }
}

void castflag_p()
{
    char p[2];
    int i;

    i = 0;
    p[0] = '0';
    p[1] = 'x';
    while (i < 2)
    {
        write(1, &p[i], 1);
        i++;
    }
}

// нужно кастить сначала к модификатору после в пресижин и длинне и после учитывать все +-# и потом уже выводить на екран.
void    *do_format(t_arg *res)
{
    upperarg(res);
    //if (res->type == 'D' || res->type == 'd' || res->type == 'i')
        //castarg_int_m();
    if (res->type == 'o' || res->type == 'O')
        castarg_uint_m();
    if (res->type == 'u' || res->type == 'U')
        castarg_uint_m();
    if (res->type == 'x' || res->type == 'X')
        castarg_uint_m();
    res->type == 'c' || res->type == 'C' ? castflag_c(res) : 0;
    res->type == 's' ? castflag_s(res) : 0;
    res->type == 'p' ? castflag_p() : 0;
    return (0);
}
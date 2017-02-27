/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:35:29 by mponomar          #+#    #+#             */
/*   Updated: 2017/02/16 22:35:53 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int number(const char *format, size_t i)
{
    int num;
    char *tmp;
    int k;
    size_t c;

    c = i;
    k = 0;
    while (format[c] > 47 && format[c] < 58)
    {
        k++;
        c++;
    }
    tmp = ft_strnew((size_t)k);
    c = 0;
    while (k)
    {
        tmp[c] = format[i];
        c++;
        i++;
        k--;
    }
    num = ft_atoi(tmp);
    return (num);
}


int         checktype(size_t i, const char *format, t_arg *res)
{
    char *types;
    size_t k;

    k = 0;
    types = "sSpdDioOuUxXcC";
    while (types[k] != '\0')
    {
        if (format[i] == types[k])
        {
            res->type = format[i];
            return (1);
        }
        k++;
    }
    return (0);
}

int         checkflags(size_t i, const char *format, t_arg *res)
{
    int k;

    k = 0;
    if (format[i] == 'h' && format[i + 1] == 'h')
        res->flag < 1 ? res->flag = 1, k += 2 : 0;
    if (format[i] == 'h' && format[i + 1] != 'h')
        res->flag < 2 ? res->flag = 2, k++ : 0;
    if (format[i] == 'l' && format[i + 1] != 'l')
        res->flag < 3 ? res->flag = 3, k++ : 0;
    if (format[i] == 'l' && format[i + 1] == 'l')
        res->flag < 4 ? res->flag = 4, k += 2 : 0;
    if (format[i] == 'j')
        res->flag < 5 ? res->flag = 5, k++ : 0;
    if (format[i] == 'z')
        res->flag < 6 ? res->flag = 6, k++ : 0;
    return (res->flag > 0 && k != 0 ? k : 0);
}

int         checkhzmp(size_t i, const char *format, t_arg *res)
{
    int k;

    k = 0;
    format[i] == '#' ? res->hesh = 1, k++ : 0;
    format[i] == '+' ? res->plus = 1, k++ : 0;
    format[i] == '0' ? res->zero = 1, k++ : 0;
    format[i] == '-' ? res->minus = 1, k++ : 0;
    format[i] == ' ' ? res->space = 1, k++ : 0;
    format[i] == '.' ? k = 1 : 0;
    format[i] == '.' && (format[i + 1] > 48 && format[i + 1] < 58) ? res->press = number(format, i + 1), k = 1 + ft_lenint(res->press) : 0;
    (format[i] > 48 && format[i] < 58) && format[i - 1] != '.' ? res->width = number(format, i), k = ft_lenint(res->width) : 0;
    return (k > 0 ? k : 0);
}

size_t      startformat(size_t i, const char *format, t_arg *res)
{
    size_t k;

    while (format[i] != '%' && format[i] != '\0')
    {
        k = 0;
        if (!(checktype(i, format, res)) && !(k = (size_t)checkflags(i, format, res)) && !(k = (size_t)checkhzmp(i, format, res)))
            return (i);
        k != 0 ? i += k : i++;
        if (res->type != '\0')
            return (i);
    }
    return (i);
}

// ******* нужно учесть применение флагов до %
size_t      searcharg(const char *format, va_list arg, t_arg *res)
{
    size_t  i;
    size_t  len;

    i = 0;
    len = 0;
    res->tmp = va_arg(arg, void *);
    while (format[i] != '\0')
    {
        while (format[i] == '%' && format[i + 1] != '%' && format[i + 1] != '\0')
        {
            i = (startformat(i + 1, format, res));
            res->type != '\0' ? do_format(res), free(res), len +=res->len, res = createres(), res->tmp = va_arg(arg, void *) : 0;
        }
        if (format[i] == '%' && format[i + 1] == '%')
            i++;
        if (format[i] == '\0')
            break ;
        if (res->type == '\0' && res->width > 0)
        {
            upperarg(res);
            if (res->minus > 0)
            {
                ft_putchar(format[i]);
                res->width -= 1;
                writewidth(res);
                len +=res->len;
            }
            else
            {
                res->zero > 0 ? res->width -= 1,  writezero(res) : 0;
                res->zero == 0 ? res->width -= 1, writewidth(res) : 0;
                ft_putchar(format[i]);
                len +=res->len;
            }
        }
        else
            ft_putchar(format[i]);
        len++;
        i++;
    }
    return (len);
}

// (***) нужно добавить бонус с *  and n
t_arg *createres()
{
    t_arg   *res;

    res = malloc(sizeof(t_arg));
    res->len = 0;
    res->type = '\0';
    res->flag = 0;
    res->space = 0;
    res->minus = 0;
    res->plus = 0;
    res->hesh = 0;
    res->zero = 0;
    res->press = -1;
    res->width = 0;
    return (res);
}

// *** не забыть нужно обрабатывать так же и лаги если они стоят на первом месте даже до %
int         ft_printf(const char *format, ...)
{
    va_list arg;
    size_t  len;
    t_arg   *res;

    len = 0;
    res = createres();
    if (format)
    {
        va_start(arg, format);
        len = searcharg(format, arg, res);
        va_end(arg);
    }
/*    printf("\n");
    printf("\nres_len: %d", res->len);
    printf("\nflag: %d", res->flag);
    printf("\nspace: %d", res->space);
    printf("\nhesh: %d", res->hesh);
    printf("\ntype: %c", res->type);
    printf("\nzero: %d", res->zero);
    printf("\nplus: %d", res->plus);
    printf("\nmin: %d", res->minus);
    printf("\npre: %d", res->press);
    printf("\nwidth: %d", res->width);*/
    //printf("\nlen: %d", (int)len);
    //printf("\n");
    return ((int)len);
}
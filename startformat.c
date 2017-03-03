//
// Created by Mykola Ponomarov on 03.03.17.
//

#include "ft_printf.h"

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
    {
        if (res->flag <= 1)
        {
            res->flag = 1;
            k += 2;
        }
    }
    if (format[i] == 'h' && format[i + 1] != 'h')
    {
        if (res->flag <= 2)
        {
            res->flag = 2;
            res->h++;
            k++;
        }
    }
    if (format[i] == 'l' && format[i + 1] != 'l')
        if (res->flag <= 3)
        {
            res->flag = 3;
            k++;
        }
    if (format[i] == 'l' && format[i + 1] == 'l')
        res->flag <= 4 ? res->flag = 4, k += 2 : 0;
    if (format[i] == 'j')
        res->flag <= 5 ? res->flag = 5, k++ : 0;
    if (format[i] == 'z')
        res->flag <= 6 ? res->flag = 6, k++ : 0;
    if (res->h > 0 && (res->h % 2) > 0)
        res->flag <= 2 ? res->flag = 2 : 0;
    if (res->h > 0 && (res->h % 2) == 0)
        res->flag <= 2 ? res->flag = 1 : 0;
    if (res->flag > 0 && k == 0)
        k++;
    return (res->flag > 0 || k != 0 ? k : 0);
}

int         checkhzmp(size_t i, const char *format, t_arg *res)
{
    int k;

    k = 0;
    format[i] == '#' ? res->hesh = 1, k++ : 0;
    format[i] == '+' ? res->plus = 1, k++ : 0;
    format[i] == '0' ? res->zero = 1, k++ : 0;
    format[i] == '-' ? res->minus = 1, k++ : 0;
    format[i] == ' ' && format[i] != '\t' ? res->space = 1, k++ : 0;
    format[i] == '.' ? res->press = 0, k = 1 : 0;
    if (format[i] == '.' && (format[i + 1] > 48 && format[i + 1] < 58))
    {
        res->press = number(format, i + 1);
        k = 1 + ft_lenint(res->press);
    }
    if ((format[i] > 48 && format[i] < 58) && format[i - 1] != '.')
    {
        res->width = number(format, i);
        k = ft_lenint(res->width);
    }
    return (k > 0 ? k : 0);
}

size_t      startformat(size_t i, const char *format, t_arg *res)
{
    size_t k;

    while (format[i] != '%' && format[i] != '\0')
    {
        k = 0;
        if (!(checktype(i, format, res)))
            if (!(k = (size_t)checkhzmp(i, format, res)))
                if (!(k = (size_t)checkflags(i, format, res)))
                    return (i);
        k != 0 ? i += k : i++;
        if (res->type != '\0')
            return (i);
    }
    return (i);
}
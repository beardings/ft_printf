//
// Created by Mykola Ponomarov on 03.03.17.
//

#include "ft_printf.h"

static size_t minnull(size_t i, size_t len, const char *format, t_arg *res)
{
    if (res->zero > 0)
    {
        res->width -= 1;
        writezero(res);
    }
    if (res->zero == 0)
    {
        res->width -= 1;
        writewidth(res);
    }
    if (format[i - 1] == '%' && res->pro > 0)
    {
        write (1, "%", 1);
        len += 1;
    }
    len += res->len;
    res->width -= res->width;
    ft_putchar(format[i]);
    res->press -=res->press;
    res->len -= res->len;
    return (len);
}

static size_t print_serch(size_t i, size_t len, const char *format, t_arg *res)
{
    upperarg(res);
    if (res->minus > 0)
    {
        if (format[i - 1] != '%')
        {
            ft_putchar(format[i]);
            res->type = '$';
        }
        else
            write (1, "%", 1);
        res->width -= 1;
        writewidth(res);
        res->width -= res->width;
        res->type != '$' ? ft_putchar(format[i]) : 0;
        len += res->len;
        res->type != '$' ? len++ : 0;
        res->minus -=1;
        res->press -=res->press;
        res->len -= res->len;
        res->type == '$' ? res->type = '\0' : 0;
    }
    else
        len = minnull(i, len, format, res);
    return (len);
}

/*static size_t findpro(size_t i, size_t len, const char *format, t_arg *res, va_list arg)
{
    res->pro = (int)i;
    i = (startformat(i + 1, format, res));
    res->pro == (int)i ? res->pro = 1 : 0;
    if (res->type != '\0')
    {
        do_format(res);
        free(res);
        len +=res->len;
        res = createres();
        res->tmp = va_arg(arg, void *);
    }
    return (len);
}*/

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
            res->pro = (int)i;
            i = (startformat(i + 1, format, res));
            res->pro == (int)i ? res->pro = 1 : 0;
            if (res->type != '\0')
            {
                do_format(res);
                free(res);
                len +=res->len;
                res = createres();
                res->tmp = va_arg(arg, void *);
            }
        }
        if (format[i] == '%' && format[i + 1] == '%')
            i++;
        if (format[i] == '\0')
            break ;
        if (res->type == '\0' && (res->width > 0 || res->space > 0 || res->flag > 0))
            len = print_serch(i, len, format, res);
        else if (format[i] == '%' && format[i + 1] == '\0' && !(format[i - 1]))
            return (len);
        else if (format[i] == '%' && len > 0 && format[i + 1] == '\0' && format[i - 1] != '%')
            return (len);
        else
            ft_putchar(format[i]);
        len++;
        i++;
    }
    free(res);
    return (len);
}
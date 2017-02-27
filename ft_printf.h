/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:36:50 by mponomar          #+#    #+#             */
/*   Updated: 2017/02/16 22:36:54 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct  s_arg
{
    int         width;
    int         press;
    int         zero;
    int         hesh;
    int         plus;
    int         minus;
    int         space;
    int         flag;
    char        type;
    void        *tmp;
    int         len;
}               t_arg;


int             ft_printf(const char *format, ...);
size_t          searcharg(const char *format, va_list arg, t_arg *res);
size_t          startformat(size_t i, const char *format, t_arg *res);
int             checkflags(size_t i, const char *format, t_arg *res);
int             checktype(size_t i, const char *format, t_arg *res);
int             checkhzmp(size_t i, const char *format, t_arg *res);
int             number(const char *format, size_t i);
void            *do_format(t_arg *res);
void            upperarg(t_arg *res);
t_arg           *createres();

void            writewidth(t_arg *res);
void            castflag_c(t_arg *res);
void            writezero(t_arg *res);
void            ft_putstrnew(char *tmp, int len, t_arg *res);
void            printhesh(t_arg *res);
int             castflag_s(t_arg *res);
void            castpress_s(t_arg *res, int i, char *tmp);
char            *ft_itoa_base(uintmax_t value, uintmax_t base, t_arg *res);
int             ft_null(char *tmp, t_arg *res);
void            writewchar_t(wchar_t c, t_arg *res);
int             castflag_bigS(t_arg *res);
void            dowchar_t(wchar_t *tmp, t_arg *res, int len);
void            writepress(t_arg *res);
void            castpress_bigS(t_arg *res, int i, wchar_t *tmp);

#endif
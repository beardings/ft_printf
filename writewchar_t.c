/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writewchar_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 23:21:33 by mponomar          #+#    #+#             */
/*   Updated: 2017/03/03 23:25:29 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define A() ft_putchar((char)((c >> 6) + 0xC0)), ft_putchar((char)((c & 0x3F) + 0x80))

void	writewchar_t(wchar_t c, t_arg *res)
{
	if (c <= 0x7F)
	{
		ft_putchar((char)c);
		res->len += 1;
	}
	else if (c <= 0x7FF)
	{
		A();
		res->len += 2;
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((char)((c >> 12) + 0xE0));
		A();
		res->len += 3;
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((char)((c >> 18) + 0xF0));
		ft_putchar((char)(((c >> 12) & 0x3F) + 0x80));
		A();
		res->len += 4;
	}
}

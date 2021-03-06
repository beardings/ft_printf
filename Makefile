#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 22:32:07 by mponomar          #+#    #+#              #
#    Updated: 2017/03/04 17:56:53 by mponomar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c \
		libft/ft_putchar.c \
		libft/ft_atoi.c \
		libft/ft_strnew.c \
		libft/ft_bzero.c \
		libft/ft_memset.c \
		libft/ft_lenint.c \
		do_format.c \
		libft/ft_strlen.c \
		libft/ft_putstr.c \
		libft/ft_strdup.c \
		libft/ft_putnbr.c \
		libft/ft_putchar_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		ft_itoa_base.c \
		castflag_s.c \
		castpress_s.c \
		castflag_c.c \
		ft_putstrnew.c \
		writewidth.c \
		writezero.c \
		upperarg.c \
		printhesh.c \
		ft_null.c \
		writewchar_t.c \
		castflag_bigs.c \
		writepress.c \
		dowchar_t.c \
		castpress_bigs.c \
		otherutf.c \
		checkcan.c \
		cast_mod.c \
		cast_standart_for_base.c \
		preox.c \
		cast_mod_base.c \
		base.c \
		minusmissing.c \
		minuspresent.c \
		numnull.c \
		cast_nnnnn.c \
		createres.c \
		startformat.c \
		searcharg.c \
		utflen.c \
		checktype.c \
		cast_mod_cont.c \
		cast_mod_b.c \
		cast_mod_contn.c \
		cast_modnex.c \
		cast_mod_next.c \
		cast_mod_contnext.c

OBJECTS = $(SOURCE:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

rmf:
	rm *~
	rm \#*
	rm *.out
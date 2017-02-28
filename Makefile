#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 22:32:07 by mponomar          #+#    #+#              #
#    Updated: 2017/02/28 16:19:39 by mponomar         ###   ########.fr        #
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
		castflag_bigS.c \
		writepress.c \
		dowchar_t.c \
		castpress_bigS.c \
		otherutf.c \
		checkcan.c

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
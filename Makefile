#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 22:36:27 by mponomar          #+#    #+#              #
#    Updated: 2017/02/16 22:36:29 by mponomar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c /
        function.c /
        function.c

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
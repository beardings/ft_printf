cmake_minimum_required(VERSION 3.6)
project(4ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES main.c /
        ft_printf.c /
        libft/ft_putchar.c /
        libft/ft_atoi.c /
        libft/ft_strnew.c /
        libft/ft_bzero.c /
        libft/ft_memset.c /
        libft/ft_lenint.c /
        do_format.c /
        libft/ft_strlen.c /
        libft/ft_putstr.c /
        libft/ft_putchar.c /
        libft/ft_strdup.c
        libft/ft_putnbr.c /
        libft/ft_putnbr_fd.c /
        libft/ft_putchar_fd /
        libft/ft_putstr_fd.c)
add_executable(get ${SOURCE_FILES})
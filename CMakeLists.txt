cmake_minimum_required(VERSION 3.6)
project(4ft_printf)

set(CMAKE_C_FLAGS )

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
        libft/ft_putstr_fd.c
        ft_itoa_base.c /
        castflag_s.c /
        castpress_s.c /
        castflag_c.c
        ft_putstrnew.c /
        writewidth.c /
        writezero.c /
        upperarg.c /
        printhesh.c /
        ft_null.c /
        writewchar_t.c /
        castflag_bigs.c /
        writepress.c /
        dowchar_t.c /
        castpress_bigs.c /
        otherutf.c /
        checkcan.c /
        cast_mod.c /
        cast_standart_for_base.c /
        preox.c /
        cast_mod_base.c /
        base.c /
        minusmissing.c /
        minuspresent.c /
        numnull.c /
        cast_nnnnn.c /
        createres.c /
        startformat.c /
        searcharg.c /
        utflen.c /
        checktype.c /
        cast_mod_cont.c /
        cast_mod_b.c /
        cast_mod_contn.c)
add_executable(get ${SOURCE_FILES})
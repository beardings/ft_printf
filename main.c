//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"
#include "locale.h"
#include "limits.h"
# define CNV "u"
int main(void)
{
    printf("\n");
    printf("|len: %i", ft_printf("my: |%5hh"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN));
    printf("\n");
    printf("|len: %i", printf("or: |%5hh"CNV"|\t|%20l l"CNV"|", SHRT_MIN,LONG_MIN));
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"
}
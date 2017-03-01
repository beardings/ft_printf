//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"
#include "locale.h"
#include "limits.h"
# define CNV "u"
int main(void)
{
    char c;
    printf("\n");
    printf("|len: %i", ft_printf("my: %#08x", 42));
    printf("\n");
    printf("|len: %i", printf("or: %#08x", 42));
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"
}
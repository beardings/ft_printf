//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"
#include "locale.h"
#include "limits.h"

int main(void)
{
    printf("\n");
    printf("|len: %i", ft_printf("my: %.d %.0d", 0, 0));
    printf("\n");
    printf("|len: %i", printf("or: %.d %.0d", 0, 0));
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"
}
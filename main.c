//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"
#include "locale.h"
#include "limits.h"

int main(void)
{
    printf("\n");
    printf("|len: %i", ft_printf("my: %+04d", 42));
    printf("\n");
    printf("|len: %i", printf("or: %+04d", 42));
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"
}
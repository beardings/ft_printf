//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"
#include "locale.h"
#include "limits.h"

int main(void)
{
    printf("\n");
    printf("|len: %i", ft_printf("my: %hD, %hD", 0, USHRT_MAX));
    printf("\n");
    printf("|len: %i", printf("or: %hD, %hD", 0, USHRT_MAX));
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"
}
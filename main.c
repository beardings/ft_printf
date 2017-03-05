//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"
#include "locale.h"
#include "limits.h"
int main(void)
{
    setlocale(LC_CTYPE, "");
    printf("\n");
    printf("|len: %i", ft_printf("%10s is a string", ""));
    printf("\n");
    printf("|len: %i", printf("%10s is a string", ""));
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"

}

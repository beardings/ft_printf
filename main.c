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
    printf("|len: %i", ft_printf("{%S}", L"O™"));
    printf("\n");
    printf("|len: %i", printf("{%S}", L"O™"));
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"

}

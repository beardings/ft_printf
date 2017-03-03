//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"
#include "locale.h"
#include "limits.h"
int main(void)
{
    printf("\n");
    printf("|len: %i", ft_printf("|%-6%|   |%6%|   |%6.2%|   |%-06%|   |%-06.3%|"));
    printf("\n");
    printf("|len: %i", printf("|%-6%|   |%6%|   |%6.2%|   |%-06%|   |%-06.3%|"));
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"

}

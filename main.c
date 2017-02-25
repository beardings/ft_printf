//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"

int main(void)
{
    //unsigned long  i = 4294967296;
    //long long k = 4999999999;
    //ft_printf("\n(FT_): %%%-+z 04.12d end  Hello!");
    //ft_printf("\n(FT_): %04.2s %-15.0s|", str, res);
    ft_printf("\n(FT_): %5u|", "4294967295");
    printf("\n(PT_): %5u|", "4294967295");
    //ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
    //printf("Hallo Nikolas%%% -20.47dhellogame", 12);
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"
}
//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"

int main(void)
{
    int i = 45;
    int k = -45;
    //ft_printf("\n(FT_): %%%-+z 04.12d end  Hello!");
    //ft_printf("\n(FT_): %04.2s %-15.0s|", str, res);
    ft_printf("\n(FT_): %-#12.4X %015.12o|", i, k);
    printf("\n(PT_): %-#12.4X %015.12o|", i, k);
    //printf("Hallo Nikolas%%% -20.47dhellogame", 12);
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"
}
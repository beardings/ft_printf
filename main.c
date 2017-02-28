//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"
#include "locale.h"

int main(void)
{
    const wchar_t B[] = L"ድመቶች ሰዎች አልወደውም.";
    //int i;
    //unsigned long  i = 4294967296;
    //long long k = 4999999999;
    //ft_printf("\n(FT_): %%%-+z 04.12d end  Hello!");
    //ft_printf("\n(FT_): %04.2s %-15.0s|", str, res);
     setlocale(LC_ALL, "");
    printf("\n");
    printf("|len: %i", ft_printf("my: |%5.3S|\t\t|%3.5S|\t\t|%7S|\t\t|%7.3S|",B, B,B,L""));
    //ft_printf("%S", L"米");
    printf("\n");
    printf("|len: %i", printf("or: |%5.3S|\t\t|%3.5S|\t\t|%7S|\t\t|%7.3S|",B, B,B,L""));
    //printf("%S", L"米");
    //ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
    //printf("Hallo Nikolas%%% -20.47dhellogame", 12);
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"
}
//
// Created by Mykola Ponomarov on 23.02.17.
//

#include <ft_printf.h>
#define A(x) ((x) < 0 ? -(x) : (x))

void f(int value,  int base, char *str, int *i)
{
    char tmp[] = "0123456789ABCDEF";

    if (value <= -base || value >= base)
        f(value / base, base, str, i);
    str[(*i)++] = tmp[a(value % base)];
}

char *ft_itoa_base(int value, int base)
{
    int i;
    char *str;

    i = 0;
    if (bace < 2 || bace > 16 || !(str = (char*)malloc(32)))
        return (0);
    if (base == 10 && value < 0)
        str[i++] = '-';
    f(value, base, str, &i);
    str[i] = '\0';
    return (str);
    
}

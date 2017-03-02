//
// Created by Mykola Ponomarov on 16.02.17.
//

#include "ft_printf.h"
#include "locale.h"
#include "limits.h"

int main(void)
{
    printf("\n");
    printf("|len: %i", ft_printf("{% 03d}", 0));
    printf("\n");
    printf("|len: %i", printf("{% 03d}", 0));
    //"${CMAKE_C_FLAGS} -Wall -Wextra -Werror"
}
/*


    assert_printf("{% 03d}", 0);

    assert_printf("{%0-3d}", 0);
*/

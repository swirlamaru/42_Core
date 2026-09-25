#include "../libft.h"
#include <stdio.h>

int main(void)
{
    printf("call ft_strlen(\"Hello World\") ? %zu\n", ft_strlen("Hello World"));
    printf("call ft_strlen(\"0123456789\") ? %zu\n", ft_strlen("0123456789"));
    printf("call ft_strlen(\" \") ? %zu\n", ft_strlen(" "));
    return (0);
}
#include "../libft.h"
#include <stdio.h>

int main(void)
{
    printf("call ft_isalpha('a') ? %d\n", ft_isalpha('a'));
    printf("call ft_isalpha('Z') ? %d\n", ft_isalpha('Z'));
    printf("call ft_isalpha('1') ? %d\n", ft_isalpha('1'));
    printf("call ft_isalpha(' ') ? %d\n", ft_isalpha(' '));
    return (0);
}
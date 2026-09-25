#include "../libft.h"
#include <stdio.h>

int main(void)
{
    printf("call ft_isalnum('a') ? %d\n", ft_isalnum('a'));
    printf("call ft_isalnum(':') ? %d\n", ft_isalnum(':'));
    printf("call ft_isalnum('1') ? %d\n", ft_isalnum('1'));
    printf("call ft_isalnum('Z') ? %d\n", ft_isalnum('Z'));
    printf("call ft_isalnum(' ') ? %d\n", ft_isalnum(' '));
    return (0);
}
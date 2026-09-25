#include "../libft.h"
#include <stdio.h>

int main(void)
{
    printf("call ft_isprint('A') ? %d\n", ft_isprint('A'));
    printf("call ft_isprint('5') ? %d\n", ft_isprint('5'));
    printf("call ft_isprint('~') ? %d\n", ft_isprint('~'));
    printf("call ft_isprint(' ') ? %d\n", ft_isprint(' '));
    printf("call \"Ctrl-A\" ft_isprint(1) ? %d\n", ft_isprint(1));
    printf("call \"DEL\" ft_isprint(127) ? %d\n", ft_isprint(127));
    return (0);
}
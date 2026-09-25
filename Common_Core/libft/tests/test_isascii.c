#include "../libft.h"
#include <stdio.h>

int main(void)
{
    printf("call ft_isascii('A') ? %d\n", ft_isascii('A'));
    printf("call ft_isascii('5') ? %d\n", ft_isascii('5'));
    printf("call ft_isascii('~') ? %d\n", ft_isascii('~'));
    printf("call \"Extended char 0x80\" ft_isascii(0x80) ? %d\n", ft_isascii(0x80));
    printf("call \"Negative value\" ft_isascii(-1) ? %d\n", ft_isascii(-1));
    return (0);
}
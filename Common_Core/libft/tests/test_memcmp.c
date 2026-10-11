#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
	printf("1. Result = %d (attendu 0)\n", ft_memcmp("abc", "abc", 3));
	printf("2. Result = %d (attendu < 0)\n", ft_memcmp("abc", "abd", 3));
	printf("3. Result = %d (attendu 0)\n", ft_memcmp("abd", "abc", 2));
	printf("4. Result = %d (attendu > 0)\n", ft_memcmp("\x80", "\x01", 1));
	return (0);
}

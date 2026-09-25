#include "../libft.h"
#include <stdio.h>

int main(void)
{
	int	result;

	result = ft_atoi("123");
	printf("ft_atoi(\"123\") → %d\n", result);

	result = ft_atoi("-123");
	printf("ft_atoi(\"-123\") → %d\n", result);

	result = ft_atoi("   456");
	printf("ft_atoi(\"   456\") → %d\n", result);

	result = ft_atoi("   -789");
	printf("ft_atoi(\"   -789\") → %d\n", result);

	result = ft_atoi("123abc");
	printf("ft_atoi(\"123abc\") → %d\n", result);

	result = ft_atoi("abc123");
	printf("ft_atoi(\"abc123\") → %d\n", result);

	result = ft_atoi("");
	printf("ft_atoi(\"\") → %d\n", result);

	result = ft_atoi("   ");
	printf("ft_atoi(\"   \") → %d\n", result);

	return (0);
}
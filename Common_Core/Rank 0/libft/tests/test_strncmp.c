#include "../libft.h"
#include <stdio.h>

int main(void)
{
	int	result;

	result = ft_strncmp("Hello", "Hello", 5);
	printf("ft_strncmp(\"Hello\", \"Hello\", 5) → %d\n", result);

	result = ft_strncmp("Hello", "Help", 5);
	printf("ft_strncmp(\"Hello\", \"Help\", 5) → %d\n", result);

	result = ft_strncmp("Help", "Hello", 5);
	printf("ft_strncmp(\"Help\", \"Hello\", 5) → %d\n", result);

	result = ft_strncmp("Hello", "Hello", 10);
	printf("ft_strncmp(\"Hello\", \"Hello\", 10) → %d\n", result);

	result = ft_strncmp("abc", "abd", 3);
	printf("ft_strncmp(\"abc\", \"abd\", 3) → %d\n", result);

	return (0);
}
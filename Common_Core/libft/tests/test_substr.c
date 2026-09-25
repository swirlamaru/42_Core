#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *sub;

	sub = ft_substr("Hello World", 6, 5);
	printf("ft_substr(\"Hello World\", 6, 5) → %s\n", sub ? sub : "(null)");
	free(sub);

	sub = ft_substr("Hello", 2, 3);
	printf("ft_substr(\"Hello\", 2, 3) → %s\n", sub ? sub : "(null)");
	free(sub);

	sub = ft_substr("Hello", 10, 5);
	printf("ft_substr(\"Hello\", 10, 5) → %s\n", sub ? sub : "(null)");
	free(sub);

	sub = ft_substr("Hello", 0, 0);
	printf("ft_substr(\"Hello\", 0, 0) → %s\n", sub ? sub : "(null)");
	free(sub);

	sub = ft_substr(NULL, 0, 5);
	printf("ft_substr(NULL, 0, 5) → %s\n", sub ? sub : "(null)");

	return (0);
}
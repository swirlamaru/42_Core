#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *dup;

	dup = ft_strdup("Hello");
	printf("ft_strdup(\"Hello\") → %s\n", dup ? dup : "(null)");
	free(dup);

	dup = ft_strdup("");
	printf("ft_strdup(\"\") → %s\n", dup ? dup : "(null)");
	free(dup);

	dup = ft_strdup(NULL);
	printf("ft_strdup(NULL) → %s\n", dup ? dup : "(null)");

	return (0);
}
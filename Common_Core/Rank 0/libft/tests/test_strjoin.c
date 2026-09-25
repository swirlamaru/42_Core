#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char*joined;

	joined = ft_strjoin("Hello", "World");
	printf("ft_strjoin(\"Hello\", \"World\") → %s\n", joined ? joined : "(null)");
	free(joined);

	joined = ft_strjoin("", "World");
	printf("ft_strjoin(\"\", \"World\") → %s\n", joined ? joined : "(null)");
	free(joined);

	joined = ft_strjoin("Hello", "");
	printf("ft_strjoin(\"Hello\", \"\") → %s\n", joined ? joined : "(null)");
	free(joined);

	joined = ft_strjoin(NULL, "World");
	printf("ft_strjoin(NULL, \"World\") → %s\n", joined ? joined : "(null)");

	joined = ft_strjoin("Hello", NULL);
	printf("ft_strjoin(\"Hello\", NULL) → %s\n", joined ? joined : "(null)");

	return (0);
}
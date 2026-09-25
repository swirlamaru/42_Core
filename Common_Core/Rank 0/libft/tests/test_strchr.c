#include "../libft.h"
#include <stdio.h>

int main(void)
{
	char *ptr;

	ptr = ft_strchr("Hello", 'l');
	printf("ft_strchr(\"Hello\", 'l') → %s\n", ptr ? ptr : "(null)");

	ptr = ft_strchr("Hello", '\0');
	printf("ft_strchr(\"Hello\", '\\0') → %s\n", ptr ? ptr : "(null)");

	ptr = ft_strchr("Hello", 'x');
	printf("ft_strchr(\"Hello\", 'x') → %s\n", ptr ? ptr : "(null)");

	return (0);
}

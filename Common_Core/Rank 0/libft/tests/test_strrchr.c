#include "../libft.h"
#include <stdio.h>

int main(void)
{
	char *ptr;

	ptr = ft_strrchr("Hello", 'l');
	printf("ft_strrchr(\"Hello\", 'l') → %s\n", ptr ? ptr : "(null)");

	ptr = ft_strrchr("Hello", '\0');
	printf("ft_strrchr(\"Hello\", '\\0') → %s\n", ptr ? ptr : "(null)");

	ptr = ft_strrchr("Hello", 'x');
	printf("ft_strrchr(\"Hello\", 'x') → %s\n", ptr ? ptr : "(null)");

	ptr = ft_strrchr("abcbc", 'b');
	printf("ft_strrchr(\"abcbc\", 'b') → %s\n", ptr ? ptr : "(null)");

	return (0);
}
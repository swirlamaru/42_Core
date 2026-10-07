#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
	void *ptr;

	ptr = ft_memchr("Hello", 'o', 5);
	printf("ft_memchr(\"Hello\", 'o', 5) → %s\n", ptr ? (char *)ptr : "(null)");

	ptr = ft_memchr("Hello", 'l', 5);
	printf("ft_memchr(\"Hello\", 'l', 5) → %s\n", ptr ? (char *)ptr : "(null)");

	ptr = ft_memchr("Hello", '\0', 6);
	printf("ft_memchr(\"Hello\", '\\0', 6) → %s\n", ptr ? (char *)ptr : "(null)");

	ptr = ft_memchr("Hello", 'x', 5);
	printf("ft_memchr(\"Hello\", 'x', 5) → %s\n", ptr ? (char *)ptr : "(null)");

	return (0);
}

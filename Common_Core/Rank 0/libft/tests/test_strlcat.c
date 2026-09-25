#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	dst[10] = "Hello";
	size_t	len;

	len = ft_strlcat(dst, "World", 10);
	printf("ft_strlcat(dst, \"World\", 10) → dst = \"%s\", len = %zu\n", dst, len);

	len = ft_strlcat(dst, "!", 10);
	printf("ft_strlcat(dst, \"!\", 10) → dst = \"%s\", len = %zu\n", dst, len);

	len = ft_strlcat(dst, "TooLong", 10);
	printf("ft_strlcat(dst, \"TooLong\", 10) → dst = \"%s\", len = %zu\n", dst, len);

	return (0);
}
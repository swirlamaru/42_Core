#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	dst[10];
	size_t	len;
    
    printf("before ft_strlcpy dst = \"%s\"\n", dst);

	len = ft_strlcpy(dst, "Hello", 10);
	printf("ft_strlcpy(dst, \"Hello\", 10) → dst = \"%s\", len = %zu\n", dst, len);

	len = ft_strlcpy(dst, "World", 4);
	printf("ft_strlcpy(dst, \"World\", 4) → dst = \"%s\", len = %zu\n", dst, len);

	len = ft_strlcpy(dst, "", 5);
	printf("ft_strlcpy(dst, \"\", 5) → dst = \"%s\", len = %zu\n", dst, len);

	return (0);
}
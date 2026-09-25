#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char src[10] = "Hello";
	char dest[10] = "-----";
	printf("before: src[10] => %s\n", src);
    printf("before: dest[10] => %s\n", dest);

	ft_memcpy(dest, src, 5);
	printf("ft_memcpy(dest, src, 5) => dest = \"%s\"\n", dest);
	
    printf("before: 'ft_memcpy(dest, \"World\", 5);' after 'ft_memcpy(dest, \"Hello\", 5);' dest[10]%s\n", dest);

	ft_memcpy(dest, "World", 5);
	printf("ft_memcpy(dest, \"World\", 5) => dest = \"%s\"\n", dest);
	
	return (0);
}
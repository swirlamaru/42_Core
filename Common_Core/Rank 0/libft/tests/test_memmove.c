#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[10] = "Hello";
	
	ft_memmove(buf + 2, buf, 3);
	printf("ft_memmove(buf + 2, buf, 3) → buf = \"%s\"\n", buf);
	
	ft_memmove(buf, buf + 2, 3);
	printf("ft_memmove(buf, buf + 2, 3) → buf = \"%s\"\n", buf);
	
	return (0);
}
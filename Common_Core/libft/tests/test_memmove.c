#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[8] = "1234567";
	
	ft_memmove(buf + 2, buf, 3);
	printf("ft_memmove(buf + 2, buf, 3) → buf = \"%s\"\n", buf);
	
	ft_memmove(buf, buf + 2, 7);
	printf("ft_memmove(buf, buf + 2, 3) → buf = \"%s\"\n", buf);
	
	return (0);
}

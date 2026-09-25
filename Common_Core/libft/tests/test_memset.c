#include "../libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[10] = "Hello";
	
	ft_memset(buf, 'A', 5);
	printf("call ft_memset(buf, 'A', 5) → buf = \"%s\"\n", buf);
	
	ft_memset(buf, 0, 10);
	printf("call ft_memset(buf, 0, 10) → buf[0-4] = '%c%c%c%c%c'\n", buf[0], buf[1], buf[2], buf[3], buf[4]);
	
	return (0);
}
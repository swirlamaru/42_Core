#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	buf[10] = "Hello";
	
    printf("before ft_bzero(buf, 5) → buf[0-4] = '%c%c%c%c%c'\n", buf[0], buf[1], buf[2], buf[3], buf[4]);
	ft_bzero(buf, 5);
	printf("ft_bzero(buf, 5) → buf[0-4] = '%c%c%c%c%c'\n", buf[0], buf[1], buf[2], buf[3], buf[4]);
	
    printf("before ft_bzero(buf, 10) → buf[0-9] = '%c%c%c%c%c%c%c%c%c%c'\n", 
		buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9]);
	ft_bzero(buf, 10);
	printf("ft_bzero(buf, 10) → buf[0-9] = '%c%c%c%c%c%c%c%c%c%c'\n", 
		buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9]);
	
	return (0);
}

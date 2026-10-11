#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
	char str[] = "  x xxxx  x  xx  xxxtripo   xxxuillxx x   x  x xx xxx";
	printf("Result = %s", ft_strtrim(str, " x"));
	return (0);
}

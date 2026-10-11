#include "../libft/libft.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	setbuf(stdout, NULL);
	printf("/* 1 */ Result = ");
	ft_putnbr_fd(0, 1);
	printf("  (attendu 0)\n");
	printf("/* 2 */ Result = ");
	ft_putnbr_fd(-42, 1);
	printf("  (attendu -42)\n");
	printf("/* 3 */ Result = ");
	ft_putnbr_fd(INT_MIN, 1);
	printf("  (attendu -2147483648)\n");
	return (0);
}

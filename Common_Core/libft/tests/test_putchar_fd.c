#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
	setbuf(stdout, NULL);
	printf("1. Result = ");
	ft_putchar_fd('4', 1);
	ft_putchar_fd('2', 1);
	printf(" (est attendu 42)\n");
	printf("3. Result = ");
	ft_putchar_fd('\n', 1);
	printf("(on attend un saut de ligne)\n");
	return (0);
}

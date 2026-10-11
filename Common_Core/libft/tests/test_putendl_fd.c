#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
	setbuf(stdout, NULL);
	printf("/* 1 */ Result = ");
	ft_putendl_fd("42", 1);
	printf("(attendu 42 suivi d'un saut de ligne)\n");
	printf("/* 2 */ Result = ");
	ft_putendl_fd("", 1);
	printf("(attendu un saut de ligne seul)\n");
	return (0);
}

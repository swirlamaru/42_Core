#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
	setbuf(stdout, NULL);
	printf("1. Result = ");
	ft_putstr_fd("42", 1);
	printf("  (est attendu 42)\n");
	printf("2. Result = ");
	ft_putstr_fd("Hello World", 1);
	printf("  (est attendu Hello World)\n");
	printf("3. Result = ");
	ft_putstr_fd(NULL, 1);
	printf("  (rien est attendu)\n");
	return (0);
}

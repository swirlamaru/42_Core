#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	c = ft_lstnew("c");
	printf("/* 1 */ Result = %d (attendu 0)\n", ft_lstsize(NULL));
	printf("/* 2 */ Result = %d (attendu 1)\n", ft_lstsize(a));
	a->next = b;
	b->next = c;
	printf("/* 3 */ Result = %d (attendu 3)\n", ft_lstsize(a));
	free(a);
	free(b);
	free(c);
	return (0);
}

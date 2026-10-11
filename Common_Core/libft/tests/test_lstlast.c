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
	printf("/* 1 */ Result = %p (attendu (nil))\n", (void *)ft_lstlast(NULL));
	printf("/* 2 */ Result = %s (attendu a)\n", (char *)ft_lstlast(a)->content);
	a->next = b;
	b->next = c;
	printf("/* 3 */ Result = %s (attendu c)\n", (char *)ft_lstlast(a)->content);
	free(a);
	free(b);
	free(c);
	return (0);
}

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;

	lst = NULL;
	a = ft_lstnew("a");
	b = ft_lstnew("b");
	ft_lstadd_front(&lst, a);
	printf("/* 1 */ Result = %s (attendu a)\n", (char *)lst->content);
	ft_lstadd_front(&lst, b);
	printf("/* 2 */ Result = %s (attendu b)\n", (char *)lst->content);
	printf("/* 3 */ Result = %s (attendu a)\n", (char *)lst->next->content);
	free(a);
	free(b);
	return (0);
}

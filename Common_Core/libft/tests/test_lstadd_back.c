#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	lst = NULL;
	a = ft_lstnew("a");
	b = ft_lstnew("b");
	c = ft_lstnew("c");
	ft_lstadd_back(&lst, a);
	printf("/* 1 */ Result = %s (attendu a)\n", (char *)lst->content);
	ft_lstadd_back(&lst, b);
	ft_lstadd_back(&lst, c);
	printf("/* 2 */ Result = %s (attendu c)\n", (char *)ft_lstlast(lst)->content);
	printf("/* 3 */ Result = %d (attendu 3)\n", ft_lstsize(lst));
	free(a);
	free(b);
	free(c);
	return (0);
}

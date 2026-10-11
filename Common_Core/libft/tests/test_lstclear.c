#include "../libft/libft.h"
#include <stdio.h>

static void	del(void *content)
{
	printf("[del] %s\n", (char *)content);
}

int main(void)
{
	t_list	*lst;

	lst = ft_lstnew("a");
	lst->next = ft_lstnew("b");
	lst->next->next = ft_lstnew("c");
	printf("/* 1 */ Result (attendu [del] a, b, c) :\n");
	ft_lstclear(&lst, del);
	printf("/* 2 */ Result = %p (attendu (nil))\n", (void *)lst);
	return (0);
}

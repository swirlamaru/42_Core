#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_list	*node;

	node = ft_lstnew("42");
	printf("/* 1 */ Result = %s (attendu 42)\n", (char *)node->content);
	printf("/* 2 */ Result = %p (attendu (nil))\n", (void *)node->next);
	free(node);
	return (0);
}

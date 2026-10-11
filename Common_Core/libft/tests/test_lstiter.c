#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	print_str(void *content)
{
	printf("%s ", (char *)content);
}

int main(void)
{
	t_list	*lst;
	t_list	*b;

	lst = ft_lstnew("a");
	b = ft_lstnew("b");
	lst->next = b;
	b->next = ft_lstnew("c");
	printf("/* 1 */ Result = ");
	ft_lstiter(lst, print_str);
	printf(" (attendu a b c)\n");
	printf("/* 2 */ Result = ");
	ft_lstiter(NULL, print_str);
	printf(" (attendu rien)\n");
	return (0);
}

#include "../libft/libft.h"
#include <stdio.h>

static void	del(void *content)
{
	printf("[del] %s\n", (char *)content);
}

int main(void)
{
	t_list	*a;

	a = ft_lstnew("a");
	printf("/* 1 */ Result (attendu [del] a) :\n");
	ft_lstdelone(a, del);
	return (0);
}

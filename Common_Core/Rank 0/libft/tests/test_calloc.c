#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	void *ptr;
	size_t	i;

	ptr = ft_calloc(3, 4);
	if (!ptr)
	{
		printf("ft_calloc(3, 4) → allocation failed\n");
		return (1);
	}
	printf("ft_calloc(3, 4) → allocated %p\n", ptr);
	for (i = 0; i < 12; i++)
		printf("%02x ", ((unsigned char *)ptr)[i]);
	printf("\n");
	free(ptr);

	ptr = ft_calloc(0, 5);
	if (!ptr)
	{
		printf("ft_calloc(0, 5) → allocation failed\n");
		return (1);
	}
	printf("ft_calloc(0, 5) → allocated %p (can be freed)\n", ptr);
	free(ptr);

	ptr = ft_calloc(1000000000, 1000000000);
	if (!ptr)
		printf("ft_calloc(1000000000, 1000000000) → allocation failed (overflow)\n");
	else
	{
		printf("ft_calloc(1000000000, 1000000000) → allocated %p\n", ptr);
		free(ptr);
	}

	return (0);
}
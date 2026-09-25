#include <stdio.h>
#include "../libft.h"

void	my_modifier(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = 'X'; // Dereference pointer to change the actual character
}

int	main(void)
{
	char str[] = "Hello World"; // Array, so it's writable

	printf("Before: %s\n", str);
	
	// No return value, str is modified directly
	ft_striteri(str, my_modifier); 
	
	printf("After:  %s\n", str);
}

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "../libft.h"

// Example function: Convert to uppercase if index is even, lowercase if odd
char	my_transform(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (toupper(c));
	return (tolower(c));
}

int	main(void)
{
	char	*result;
	char	*input = "Hello World";

	result = ft_strmapi(input, my_transform);
	
	if (result)
	{
		printf("Original: %s\n", input);
		printf("Modified: %s\n", result);
		// Expected: "HeLlO wOrLd"
		free(result);
	}
	return (0);
}

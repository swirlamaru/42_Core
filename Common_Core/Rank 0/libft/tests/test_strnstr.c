#include "../libft.h"
#include <stdio.h>

int main(void)
{
	char *ptr;

	ptr = ft_strnstr("Hello World", "World", 11);
	printf("ft_strnstr(\"Hello World\", \"World\", 11) → %s\n", ptr ? ptr : "(null)");

	ptr = ft_strnstr("Hello World", "Hello", 5);
	printf("ft_strnstr(\"Hello World\", \"Hello\", 5) → %s\n", ptr ? ptr : "(null)");

	ptr = ft_strnstr("Hello World", "World", 5);
	printf("ft_strnstr(\"Hello World\", \"World\", 5) → %s\n", ptr ? ptr : "(null)");

	ptr = ft_strnstr("Hello World", "", 11);
	printf("ft_strnstr(\"Hello World\", \"\", 11) → %s\n", ptr ? ptr : "(null)");

	ptr = ft_strnstr("Hello World", "NotHere", 11);
	printf("ft_strnstr(\"Hello World\", \"NotHere\", 11) → %s\n", ptr ? ptr : "(null)");

	return (0);
}
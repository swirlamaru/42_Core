#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Prototype of your function
char	*ft_itoa(int n);

// Helper to print test results clearly
void	test_case(const char *name, int input, const char *expected)
{
	char	*result = ft_itoa(input);
	int		passed = 0;

	if (!result && !expected)
		passed = 1; // Both NULL (unlikely for itoa unless malloc fails)
	else if (result && expected && strcmp(result, expected) == 0)
		passed = 1;
	
	printf("[%s] ", name);
	if (passed)
		printf("\033[32mPASS\033[0m\n"); // Green
	else
	{
		printf("\033[31mFAIL\033[0m\n"); // Red
		if (result)
			printf("  Expected: \"%s\"\n  Got:      \"%s\"\n", expected, result);
		else
			printf("  Expected: \"%s\"\n  Got:      NULL (malloc failed?)\n", expected);
	}
	if (result)
		free(result); // Important: free memory allocated by ft_itoa
}

int	main(void)
{
	char	buffer[50]; // For generating expected values with sprintf

	printf("=== Testing ft_itoa ===\n\n");

	// 1. Basic Cases
	sprintf(buffer, "%d", 0);
	test_case("Zero", 0, buffer);

	sprintf(buffer, "%d", 42);
	test_case("Positive Simple", 42, buffer);

	sprintf(buffer, "%d", -42);
	test_case("Negative Simple", -42, buffer);

	// 2. Large Numbers
	sprintf(buffer, "%d", 2147483647);
	test_case("INT_MAX", INT_MAX, buffer);

	sprintf(buffer, "%ld", -2147483648);
	test_case("INT_MIN", INT_MIN, buffer);

	// 3. Edge Cases & Patterns
	sprintf(buffer, "%d", 1);
	test_case("Positive One", 1, buffer);

	sprintf(buffer, "%d", -1);
	test_case("Negative One", -1, buffer);

	sprintf(buffer, "%d", 123456789);
	test_case("Large Positive", 123456789, buffer);

	sprintf(buffer, "%d", -987654321);
	test_case("Large Negative", -987654321, buffer);

	sprintf(buffer, "%d", 10);
	test_case("Ten", 10, buffer);

	sprintf(buffer, "%d", -10);
	test_case("Minus Ten", -10, buffer);

	printf("\n=== Tests Complete ===\n");
	return (0);
}

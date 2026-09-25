#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../libft.h" // Make sure this includes your t_list definition and prototypes

/* --- Helper Functions --- */

// Function 'f': Converts a string to UPPERCASE
// It allocates new memory for the transformed string
void	*to_uppercase(void *content)
{
	char	*str;
	char	*new_str;
	int		i;

	str = (char *)content;
	if (!str)
		return (NULL);

	// Allocate memory for the new string
	new_str = malloc(sizeof(char) * (strlen(str) + 1));
	if (!new_str)
		return (NULL);

	i = 0;
	while (str[i])
	{
		new_str[i] = toupper((unsigned char)str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// Function 'del': Frees the content (which is a char *)
void	del_content(void *content)
{
	if (content)
		free(content);
}

// Helper to print the list
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("[%s] -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

// Helper to create a node with a string (wrapper around ft_lstnew)
t_list	*create_node(char *str)
{
	// We must strdup because ft_lstnew stores the pointer directly.
	// If we pass a literal or stack variable, it might be unsafe if freed later.
	return (ft_lstnew(ft_strdup(str)));
}

/* --- Main Test --- */
int	main(void)
{
	t_list	*source_list;
	t_list	*new_list;

	printf("=== Testing ft_lstmap ===\n\n");

	// 1. Create Source List: "hello", "world", "42"
	source_list = create_node("hello");
	source_list->next = create_node("world");
	source_list->next->next = create_node("42");

	printf("Source List: \n");
	print_list(source_list);

	// 2. Apply ft_lstmap
	// Transforms every string to UPPERCASE
	new_list = ft_lstmap(source_list, to_uppercase, del_content);

	printf("\nNew List (Uppercased): \n");
	if (new_list)
		print_list(new_list);
	else
		printf("Mapping failed (allocation error simulated or real)\n");

	// 3. Verification
	// Check if the source list is untouched
	printf("\nSource List (Should be unchanged): \n");
	print_list(source_list);

	// 4. Cleanup
	// Free the new list (content + nodes)
	printf("\nCleaning up new list...\n");
	ft_lstclear(&new_list, del_content);

	// Free the source list (content + nodes)
	// Note: create_node used ft_strdup, so content must be freed.
	printf("Cleaning up source list...\n");
	ft_lstclear(&source_list, free); // Using standard free because content is char* from strdup

	printf("\nTest complete. Check Valgrind for leaks!\n");

	return (0);
}

#include "../libft.h"                                                                          
#include <stdio.h>                                                                             
#include <stdlib.h>                                                                            
                                                                                               
void	print_arr(char **arr)                                                                  
{                                                                                              
	int	i;                                                                                     
                                                                                               
	i = 0;                                                                                     
	while (arr[i])                                                                             
	{                                                                                          
		printf("  [%d] \"%s\"\n", i, arr[i]);                                                  
		i++;                                                                                   
	}                                                                                          
	if (arr)                                                                                   
		free(arr[i]); // Free the last element (NULL) isn't needed, but free strings if tested 
}                                                                                              
                                                                                               
int main(void)                                                                                 
{                                                                                              
	char	**ptr;                                                                             
                                                                                               
	// 1. Normal case                                                                          
	printf("TEST 1: Normal string\n");                                                         
	ptr = ft_split("Hello world, this is a test.", ' ');                                       
	if (ptr)                                                                                   
	{                                                                                          
		print_arr(ptr);                                                                        
		// Note: In a real test, you would free each string and the array                      
	}                                                                                          
	else                                                                                       
		printf("  FAILED: Returned NULL\n");                                                   
	printf("\n");                                                                              
                                                                                               
	// 2. Empty string                                                                         
	printf("TEST 2: Empty string\n");                                                          
	ptr = ft_split("", ' ');                                                                   
	if (!ptr)                                                                                  
		printf("  Passed: Returned NULL (empty array)\n");                                     
	else                                                                                       
	{                                                                                          
		print_arr(ptr);                                                                        
	}                                                                                          
	printf("\n");                                                                              
                                                                                               
	// 3. String with only delimiters                                                          
	printf("TEST 3: Only delimiters\n");                                                       
	ptr = ft_split("   ...   ", '.');                                                          
	if (!ptr)                                                                                  
		printf("  Passed: Returned NULL (empty array)\n");                                     
	else                                                                                       
	{                                                                                          
		print_arr(ptr);                                                                        
	}                                                                                          
	printf("\n");                                                                              
                                                                                               
	// 4. Leading and trailing delimiters                                                      
	printf("TEST 4: Leading and trailing delimiters\n");                                       
	ptr = ft_split("   word   another   ", ' ');                                               
	if (ptr)                                                                                   
	{                                                                                          
		print_arr(ptr);                                                                        
		// Should find: "word", "another"                                                      
	}                                                                                          
	else                                                                                       
		printf("  FAILED: Returned NULL\n");                                                   
	printf("\n");                                                                              
                                                                                               
	// 5. Single word (no delimiters)                                                          
	printf("TEST 5: Single word\n");                                                           
	ptr = ft_split("SingleWord", ' ');                                                         
	if (ptr)                                                                                   
	{                                                                                          
		print_arr(ptr);                                                                        
		// Should find: "SingleWord"                                                           
	}                                                                                          
	else                                                                                       
		printf("  FAILED: Returned NULL\n");                                                   
	printf("\n");                                                                              
                                                                                               
	// 6. NULL input                                                                           
	printf("TEST 6: NULL input\n");                                                            
	ptr = ft_split(NULL, ' ');                                                                 
	if (!ptr)                                                                                  
		printf("  Passed: Returned NULL\n");                                                   
	else                                                                                       
		printf("  FAILED: Should return NULL\n");                                              
	printf("\n");                                                                              
                                                                                               
	// 7. Consecutive delimiters                                                               
	printf("TEST 7: Consecutive delimiters (should skip)\n");                                  
	ptr = ft_split("word1  word2   word3", ' ');                                               
	if (ptr)                                                                                   
	{                                                                                          
		print_arr(ptr);                                                                        
		// Should find: "word1", "word2", "word3" (3 items)                                    
	}                                                                                          
	else                                                                                       
		printf("  FAILED: Returned NULL\n");                                                   
	printf("\n");                                                                              
                                                                                               
	// 8. Last character is a delimiter                                                        
	printf("TEST 8: Ends with delimiter\n");                                                   
	ptr = ft_split("word1 word2 ", ' ');                                                       
	if (ptr)                                                                                   
	{                                                                                          
		print_arr(ptr);                                                                        
	}                                                                                          
	else                                                                                       
		printf("  FAILED: Returned NULL\n");                                                   
                                                                                               
	return (0);                                                                                
}                                                                                              


















































































































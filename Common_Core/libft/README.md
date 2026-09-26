*This project has been created as part of the 42 curriculum by [sspirig](https://profile-v3.intra.42.fr/users/sspirig)*
```
      ,.¬:=*¨´				    	   
   ,+::+´ ˍ.-:+:.ˍ   		    	:::    ::::::::      
 ,+:+` ,:*´     `'+:.             :+:    :+:     :+:   
,+#+ ,#'  ,'´¨*+, `+#+.         +:+  +:+       +:+
+#+	 ;:   `-'   .:  +#+  	  +#+   +:+      +#+
#+#	 `#:.     ˍ.;' ,+#´    +#+#+#+#+#+   +#+		    
`#+#.  `*+##+^*  ,#+#´		      #+#    #+#
  `#$#&x.    .x&#$#´			 ###   ########	      
     `*#$&%%&$#*´
```   
-----------------------
# Libft
-----------------------

*A Common Core project by **sspirig***
*Completed the 25 September 2026, Evaluated the 5 October 2026*

## Description

**The library "libft" provides general utility functions, such as libc functions, allocation and manipulation of linked lists**

**Program Name :** **`libft.a`**

**Files to submit :** **`ft_\*.c, libft.h, Makefile`**

**Overview :** Library with functions to manipulate valid ascii characters, integers, strings, memory areas and bytes, converting integer to string or the reverse, allocate new memory to store something, manipulate arrays, manipulate a linked list.

**Goal :** Create our own library, reimplement a set a functions from the libc, Implement additional functions and a struct t_list which is a linked list. 9 functions comes with the linked list. The files must be 42 norm compliant.

**Technical considerations :** No global variables, define helper functions as static files must be placed at the root of the repository, Don't submit unused files, Every C files must correclty compile with the flags `-Wall -Wextra -Werror` (treating warnings as errors), use the `ar` command to create the library. use of `libtool` is forbidden and the `libft.a` must be created at the root of the repo.

## Instructions

### Compilation

1. **Open a new terminal at the libft repository path**
2. **Enter the command `make`**
3. **The `libft.a` static compiled library will be created at the root of the repository**

### Installation

**No installation is required. To use the library in a C project :**
1. **Ensure `libft.h` is included in your source code: `#include "libft.h"`**
2. **Complie your program by linking the library located in the current directory**
*Command:* `cc script.c -L. -lft -o program_name` (***-L*** flag tells the compiler to look in the current dir, ***-lft*** links `libft.a`)

### Execution

**Since the libft is a static library, it cannot be execute directly, it must be linked to a C program containing a main() function.**
**Once linked (as shown in the Installation section), run your compiled executable with `./program_name`.**

### Cleaning

**Use the following `make` commands to manage build files :**
- **Remove object files**
*Command:* `make clean`
- **Remove object files and the library (`libft.a`)**
*Command:* `make fclean`
- **Recompile the library from scratch**
*Command:* `make re`

## Resources

- ***Exercices made in the 42 pool of August 2026***
- **Website resources**: *w3schools.com, stackoverflow.com, apprendrelec.com, man.freebsd.org*

AI Notice: *AI was used to generate test files and to explain the logic of a function by the manual on FreeBSD.*

## Detailed description
**In the list below, a *string* is a *char ** variable.**

### Part 1. Libc functions

- **ft_isalpha** :
*Returns 1 if the given integer is an alphabetic character, 0 if false. ('a'-'z' & 'A'-'Z')*
*Prototype*: `int ft_isalpha(int c);`

- **ft_isdigit** :
*Returns 1 if the given integer is a valid ascii digit, 0 if false. (0-9)*
*Prototype*: `int ft_isdigit(int c);`

- **ft_isalnum** :
*Returns 1 if the given integer is an alphanumeric character, 0 if false. ('0'-'9' & 'a'-'z' & 'A'-'Z')*
*Prototype*: `int ft_isalnum(int c);`

- **ft_isascii** :
*Returns 1 if the given integer is a valid ascii character, 0 if false. (0-127)*
*Prototype*: `int ft_isascii(int c);`

- **ft_isprint** :
*Returns 1 if the given integer is a valid printable ascii character, 0 if false. (32-126)*
*Prototype*: `int ft_isprint(int c);`

- **ft_strlen** :
*Returns the length of the **string** string as a **size_t** unsigned integer.*
*Prototype*: `size_t ft_strlen(const char *s);`

- **ft_memset** :
*Fills the **n** first bytes of the memory pointed to by **s** with the **c** integer.*
*Prototype*: `void *ft_memset(void *s, int c, size_t n);`

- **ft_bzero** :
*Fills the **n** first bytes of the memory pointed to by **s** with the NULL character '\0'. (same as memset(s, '\0', n))*
*Prototype*: `void ft_bzero(void *s, size_t n);`

- **ft_memcpy** :
*Copies **n** bytes onto the memory pointed by **dest** with the bytes pointed by **src**.*
*Prototype*: `void *ft_memcpy(void *dest, const void *src, size_t n);`

- **ft_memmove** :
*Similar function to ft_memcpy but the areas may overlap.*
*Prototype*: `void *ft_memmove(void *dest, const void *src, size_t n);`

- **ft_strlcpy** :
*Copies **size** bytes of the source **string** onto the **string** pointed by **dst**, returns **the total length of the string** they tried to create, as if truncation didn't happend.*
*Prototype*: `size_t ft_strlcpy(char *dst, const char *src, size_t size);`

- **ft_strlcat** :
*Catenates **size** bytes of the source **string**, returns **the total length of the string** they tried to create, as if truncation didn't happend.*
*Prototype*: `size_t ft_strlcat(char *dst, const char *src, size_t size);`

- **ft_toupper** :
*Returns the given alphabetical character but as uppercase letters.*
*Prototype*: `int ft_toupper(int c);`

- **ft_tolower** :
*Returns the given alphabetical character but as lowercase letters.*
*Prototype*: `int ft_tolower(int c);`

- **ft_strchr** :
*Returns a pointer at the first occurence of the **c** character in the **s** string, **NULL** if the character is not found.*
*Prototype*: `char *ft_strchr(const char *s, int c);`

- **ft_strrchr** :
*Returns a pointer at the last occurence of the **c** character in the **s** string, **NULL** if the character is not found.*
*Prototype*: `char *ft_strrchr(const char *s, int c);`

- **ft_strncmp** :
*Compares **s1** and **s2** strings, returns an integer less than, equal to or greater than zero if the first **n** bytes of **s1** is found,*
*respectively, to be less than, to match or to be greater than the first **n** bytes of **s2**.*
*Similar to strcmp and memcmp, it compares only the first (at most) **n** bytes of **s1** and **s2**.*
*Prototype*: `int ft_strncmp(const char *s1, const char *s2, size_t n);`

- **ft_memchr** :
*Searches the first instance of the **c** character by scanning the initial **n** bytes of the memory area pointed to by **s**.*
*Prototype*: `void *ft_memchr(const void *s, int c, size_t n);`

- **ft_memcmp** :
*Similar to strncmp, it compares the first **n** bytes of the two memory areas pointed to by **s1** and **s2**.*
*For a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes that differ in s1 and s2.*
*Returns the difference or 0 if **n** is zero.*
*Prototype*: `int ft_memcmp(const void *s1, const void *s2, size_t n);`

- **ft_strnstr** :
*Locates the first occurence of the **little** substring in the **big** string, where no more than **len** characters are searched.*
*Characters that appear after a null character '\0' are not searched. (Original function is from FreeBSD)*
*Returns **big** if **little** is empty, returns **NULL** if **little** occurs nowhere in **big** otherwise returns a pointer to the first character of the first occurence of **little**.*
*Prototype*: `char *ft_strnstr(const char *big, const char *little, size_t len);`

- **ft_atoi** :
*Converts if possible the ascii characteurs of the string to a positive or negative integer, returns the converted value or 0 on error.*
*Prototype*: `int ft_atoi(const char *nptr);`

- **ft_calloc** :
*Allocates memory for an array of **nmemb** elements of **size** bytes and returns a pointer to the allocated memory, NULL if an error occured.*
*The memory is set to zero. If **nmemb** or **size** is 0, than it returns a unique pointer value that can later be successfully passed to free(3).*
*Prototype*: `void *ft_calloc(size_t nmemb, size_t size);`
*External Function*: **malloc(3)** from the **<stdlib.h>** library.

- **ft_strdup** :
*Returns a pointed to the newly duplicated string of the **s** string on success, memory for the new string is obtained and allocated by malloc(3), and can be freed by free(3). It returns **NULL** if insufficient memory was available.*
*Prototype*: `char *ft_strdup(const char *s);`
*External Function*: **malloc(3)** from the **<stdlib.h>** library.

### Part 2. Additional functions

- **ft_substr** :
*Allocates memory (using malloc(3)) and returns a substring from the string **s**.
The substring starts at index **start** and has a maximum length of **len**.*
*Returns the **substring** or **NULL** if the allocation fails.*
*Prototype*: `char *ft_substr(char const *s, unsigned int start, size_t len);`
*External Function*: **malloc(3)** from the **<stdlib.h>** library.

- **ft_strjoin** :
*Allocates memory (using malloc(3)) and returns a new string, which is the result of concatenating **s1** and **s2**.*
*Returns the **new string** or **NULL** if the allocation fails.*
*Prototype*: `char *ft_strjoin(char const *s1, char const *s2);`
*External Function*: **malloc(3)** from the **<stdlib.h>** library.

- **ft_strtrim** :
*Allocates memory (using malloc(3)) and returns a copy of **s1** with characters from **set** removed from the beginning and the end.*
*Returns the **trimmed string** or **NULL** if the allocation fails.*
*Prototype*: `char *ft_strtrim(char const *s1, char const *set);`
*External Function*: **malloc(3)** from the **<stdlib.h>** library.

- **ft_split** :
*Allocates memory (using malloc(3)) and returns an array of strings obtained by splitting **s** using the character **c** as a delimiter. The array must end with a NULL pointer.*
*Returns the **array** of new string resulting from the split or **NULL** if the allocation fails.*
*Prototype*: `char **ft_split(char const *s, char c);`
*External Functions*: **malloc(3)**, **free(3)** from the **<stdlib.h>** library.

- **ft_itoa** :
*Allocates memory (using malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.*
*Returns the **string representing the integer** or **NULL** if the allocation fails.*
*Prototype*: `char *ft_itoa(int n);`
*External Function*: **malloc(3)** from the **<stdlib.h>** library.

- **ft_strmapi** :
*Applies the function f to each character of the string s, passing its index as the first argument and the character itself as the second.*
*A new string is created (using malloc(3)) to store the results from the successive applications of **f**.*
*Returns the string created from the successive applications of **f** or **NULL** if the allocation fails.*
*Prototype*: `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`
*External Function*: **malloc(3)** from the **<stdlib.h>** library.

- **ft_striteri** :
*Applies the function **f** to each character of the string passed as argument, passing its index as the first argument.*
*Each character is passed by address to **f** so it can be modified if necessary.*
*Prototype*: `void ft_striteri(char *s, void (*f)(unsigned int, char *));`

- **ft_putchar_fd** :
*Outputs the character **c** to the specified file descriptor **fd**.*
*Prototype*: `void ft_putchar_fd(char c, int fd);`
*External Function*: **write(3)** from the **<stddef.h>** library.

- **ft_putstr_fd** :
*Outputs the string **s** to the specified file descriptor **fd**.*
*Prototype*: `void ft_putstr_fd(char *s, int fd);`
*External Function*: **write(3)** from the **<stddef.h>** library.

- **ft_putendl_fd** :
*Outputs the string **s** to the specified file descriptor **fd** followed by a newline.*
*Prototype*: `void ft_putendl_fd(char *s, int fd);`
*External Function*: **write(3)** from the **<stddef.h>** library.

- **ft_putnbr_fd** :
*Outputs the integer **n** to the specified file descriptor **fd**.*
*Prototype*: `void ft_putnbr_fd(int n, int fd);`
*External Function*: **write(3)** from the **<stddef.h>** library.

### Part 3. Linked list

***In this part, its was necessary to following structure to manipulate a linked list and to implement the last functions of the libft.***

```c
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```

<u>The members of the **t_list** struct are</u> :
	• **content**: The data contained in the node. Using void * allows you to store any type of data.
	• **next**: The address of the next node, or NULL if the current node is the last one.

- **ft_lstnew** :
*Allocates memory (using malloc(3)) and returns a new node. The **content** member variable is initialized with the given parameter **content**.*
*The variable **next** is initialized to **NULL**.*
*Returns a pointer to the new node.*
*Prototype*: `t_list *ft_lstnew(void *content);`
*External Function*: **malloc(3)** from the **<stdlib.h>** library.

- **ft_lstadd_front** :
*Adds the node **new** at the beginning of the list **lst** points at.*
*Prototype*: `void ft_lstadd_front(t_list **lst, t_list *new);`

- **ft_lstsize** :
*Counts the number of nodes in the list **lst** points at. Returns the length of the list*
*Prototype*: `int ft_lstsize(t_list *lst);`

- **ft_lstlast** :
*Returns the last node of the list.*
*Prototype*: `t_list *ft_lstlast(t_list *lst);`

- **ft_lstadd_back** :
*Adds the nods **new** at the end of the list.*
*Prototype*: `void ft_lstadd_back(t_list **lst, t_list *new);`

- **ft_lstdelone** :
*Takes a node as parameter and frees its content using the function **del**. Free the node itself but does **NOT** free the next node.*
*Prototype*: `void ft_lstdelone(t_list *lst, void (*del)(void *));`
*External Function*: **free(3)** from the **<stdlib.h>** library.

- **ft_lstclear** :
*Deletes and frees the given node and all its successors, using the function **del** and free(3). Finally, set the pointer to the list to **NULL**.*
*Prototype*: `void ft_lstclear(t_list **lst, void (*del)(void *));`
*External Function*: **free(3)** from the **<stdlib.h>** library.

- **ft_lstiter** :
*Iterates through the list **lst** and applies the function **f** to the content of each node*
*Prototype*: `void ft_lstiter(t_list *lst, void (*f)(void *));`

- **ft_lstmap** :
*Iterates through the list **lst**, applies the function **f** to each node’s content, and creates a new list resulting of the successive applications of the function **f**.*
*The **del** function is used to delete the content of a node if needed.*
*Returns the **new list** or **NULL** if the allocation fails.*
*Prototype*: `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`
*External Functions*: **malloc(3)**, **free(3)** from the **<stdlib.h>** library.

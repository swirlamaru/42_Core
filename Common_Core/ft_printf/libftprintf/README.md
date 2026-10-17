*This project has been created as part of the 42 curriculum by [sspirig](https://profile-v3.intra.42.fr/users/sspirig)*
```
      ,.¬:=*¨
   ,+::+´  ˍ.-:+:.ˍ   			  :::    ::::::::
 ,+:+`   ,:*´     `'+:.             :+:    :+:     :+:
,+:+   ,+'  ,'´¨*+. `+#+.         +:+  +:+       +:+
+#+	 ;:   `-'   ;:  +#+  	  +#+   +:+      +#+
#+#	 `#:.     ,;'  ,+#´    +#+#+#+#+#+    +#+
`#+#.    `*+##+*´  ,#+#´            #+#    #+#
  `#$#&x.      .x&#$#´		     ###   ########
      `*#$&%%&$#*´

# ft_printf

***Common Core Rank 1***
*Completed the 17 October 2026*

## Description

**The library "libftprintf" provides a custom implementation of the standard libc `printf` function, handling variadic arguments and formatted conversion outputs.**

**Program Name :** **`libftprintf.a`**

**Files to submit :** **`Makefile, *.h, */*.h, *.c, */*.c`**

**Overview :** Static library containing `ft_printf`, a function designed to replicate the behavior of the standard C library function `printf(3)` from `<stdio.h>`. It processes format strings, converts dynamic arguments into character sequences, and outputs them to the standard output while returning the total character count printed.

**Goal :** Reimplement the famous `printf()` function from libc. The project explores variadic functions in C using macros from `<stdarg.h>`, manages multiple data type conversions (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`), and integrates seamlessly with our previous `libft` library. All files must be 42 norm compliant.

**Technical considerations :** No global variables are permitted, helper functions must be appropriately structured, and files must be organized cleanly in the repository. Don't submit unused files. Every C file must correctly compile with the flags `-Wall -Wextra -Werror` (treating warnings as errors). The library must be created using the `ar` command (`ar rcs`). The use of `libtool` is forbidden, and `libftprintf.a` must be generated at the root of the repository.

## Instructions

### Compilation

1. **Open a new terminal at the ft_printf repository path**
2. **Enter the command `make`**
3. **The `libftprintf.a` static compiled library will be created at the root of the repository**

### Installation

**No installation is required. To use the library in a C project :**
1. **Ensure `ft_printf.h` is included in your source code: `#include "ft_printf.h"`**
2. **Compile your program by linking the library located in the current directory**
*Command:* `cc main.c -L. -lftprintf -o program_name` (***-L.*** flag tells the compiler to look in the current directory, ***-lftprintf*** links `libftprintf.a`)

### Execution

**Since libftprintf is a static library, it cannot be executed directly, it must be linked to a C program containing a main() function.**
**Once linked (as shown in the Installation section), run your compiled executable with `./program_name`.**

### Cleaning

**Use the following `make` commands to manage build files :**
- **Remove object files**
*Command:* `make clean`
- **Remove object files and the library (`libftprintf.a`)**
*Command:* `make fclean`
- **Recompile the library from scratch**
*Command:* `make re`

## Resources

- ***Subject 42 - ft_printf (Common Core)***
- ***Libft library (Common Core Rank 0)***
- **Manual pages**: *man 3 printf, man 3 stdarg, man 3 va_start, man 3 va_arg, man 3 va_end, man 3 va_copy*
- **Website resources**: *w3schools.com, stackoverflow.com, apprendrelec.com, man7.org, geeksforgeeks.org*
- **AI Assistance**: *This README.md file was generated and adapted from the Libft README using AI.*

## Detailed description

### Part 1. Format Specifiers (Conversions)

**The `ft_printf` function handles the following conversions specified by `%` followed by a conversion character :**

- **`%c`** :
*Prints a single character.*

- **`%s`** :
*Prints a string of characters (as defined by standard C convention). If the string pointer is `NULL`, outputs `(null)`.*

- **`%p`** :
*Prints a `void *` memory address in hexadecimal format prefixed with `0x`. If the pointer is `NULL`, outputs `(nil)`.*

- **`%d`** :
*Prints a signed decimal number (base 10).*

- **`%i`** :
*Prints an integer in base 10 (identical behavior to `%d`).*

- **`%u`** :
*Prints an unsigned decimal number (base 10).*

- **`%x`** :
*Prints an unsigned integer as a hexadecimal number (base 16) in lowercase format (`0123456789abcdef`).*

- **`%X`** :
*Prints an unsigned integer as a hexadecimal number (base 16) in uppercase format (`0123456789ABCDEF`).*

- **`%%`** :
*Prints a single literal percent sign character (`%`).*

---

### Part 2. Main and Parsing Functions

- **ft_printf** :
*Formats and prints data to standard output according to the format string **str**, handling variadic arguments.*
*Returns the total number of characters printed, or `-1` if an error occurs or if **str** is NULL.*
*Prototype*: `int ft_printf(const char *str, ...);`
*Variadic Macros*: **va_start**, **va_end** from `<stdarg.h>`.

- **parse_loop** :
*Iterates through the format string **str**, writes literal characters directly to stdout, and delegates format conversions preceded by `%` to `parse_argtype`.*
*Returns the accumulated character count, or `-1` upon error.*
*Prototype*: `int parse_loop(const char *str, va_list args);`
*External Function*: **write(2)** from `<unistd.h>`.

- **parse_argtype** :
*Evaluates the specifier character **c** following a `%` sign and dispatches to the corresponding printing helper function with the argument extracted from **args**.*
*Returns the number of characters printed for the specifier, or `-1` if the specifier is unsupported.*
*Prototype*: `int parse_argtype(char c, va_list args);`
*Variadic Macro*: **va_arg** from `<stdarg.h>`.

---

### Part 3. Printing Helper Functions

- **print_char** :
*Writes a single character **ch** to standard output.*
*Returns `1` (the number of printed characters).*
*Prototype*: `int print_char(int ch);`
*External Function*: **write(2)** from `<unistd.h>`.

- **print_str** :
*Outputs the string **str** to standard output. If **str** is NULL, writes `(null)`.*
*Returns the number of characters printed.*
*Prototype*: `int print_str(char *str);`
*Libft Functions*: **ft_putstr_fd**, **ft_strlen**.

- **print_ptr** :
*Outputs the memory address pointed to by **ptr** in hexadecimal notation preceded by `0x`. If **ptr** is NULL, writes `(nil)`.*
*Returns the total number of characters printed.*
*Prototype*: `int print_ptr(void *ptr);`
*Helper Function*: **convert_to_hex**.

- **print_int** :
*Converts the integer **n** into an ASCII string representation using `ft_itoa` and writes it to standard output.*
*Returns the number of characters printed.*
*Prototype*: `int print_int(int n);`
*Libft Functions*: **ft_itoa**, **ft_putstr_fd**, **ft_strlen**.
*External Function*: **free(3)** from `<stdlib.h>`.

- **print_unsigned_int** :
*Recursively decomposes and prints the unsigned integer **n** in base 10 to standard output.*
*Returns the number of digits printed.*
*Prototype*: `int print_unsigned_int(unsigned int n);`
*External Function*: **write(2)** from `<unistd.h>`.

- **print_hex_num** :
*Converts and prints the unsigned integer **n** in base 16 (hexadecimal). Uses lowercase digits if **is_upcase** is 0, or uppercase digits if **is_upcase** is 1.*
*Returns the number of characters printed.*
*Prototype*: `int print_hex_num(unsigned int n, int is_upcase);`
*Helper Function*: **convert_to_hex**.

- **convert_to_hex** :
*Recursively converts a `size_t` value **n** into hexadecimal base 16 and prints it using the appropriate lookup table depending on **is_upcase**.*
*Returns the total count of hexadecimal digits written.*
*Prototype*: `int convert_to_hex(size_t n, int is_upcase);`
*External Function*: **write(2)** from `<unistd.h>`.

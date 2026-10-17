# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:   # 
#                                                     +:+ +:+         +:+      #
#    By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/21 14:45:25 by sspirig           #+#    #+#              #
#    Updated: 2026/10/11 15:42:26 by sspirig          ###   ########.fr       # 
#                                                                              #
# **************************************************************************** #

# Name
NAME = libft.a

# Complier
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source of files
SRC = ft_isalpha.c ft_lstadd_back.c ft_lstlast.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
	ft_atoi.c ft_isascii.c ft_lstadd_front.c ft_lstmap.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
	ft_bzero.c ft_isdigit.c ft_lstclear.c ft_lstnew.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
	ft_calloc.c ft_isprint.c ft_lstdelone.c ft_lstsize.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
	ft_isalnum.c ft_itoa.c ft_lstiter.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c

# Storing objects files from .c srcfiles
OBJ = $(SRC:.c=.o)

# Archive tool
AR = ar
ARFLAGS = rcs
# 'r' => insert or replace files in archive
# 'c' => create archive if don't already exists
# 's' => create index for symbols

## BUILDING THE LIB

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(ARFLAGS) $@ $^
		@echo "[libft] '$(NAME)' was created successfully !"
# '$@' => Target name (libft.a)
# '$^' => All dependencies (all obj files .o)


# Compiling every src files to obj files (also if header file changed)
%.o: %.c libft.h
		$(CC) $(CFLAGS) -c $< -o $@
# '$<' => first dependency (.c file)
# '$@' => target file (.o file)

clean:
		rm -f $(OBJ)
		@echo "[libft] Object files removed !"

fclean: clean
		rm -f $(NAME)
		@echo "[libft] Library removed (full cleanup) !"

re: fclean all
		@echo "[libft] Rebuild complete !"

.PHONY: all clean fclean re

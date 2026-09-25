# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/21 14:45:25 by sspirig           #+#    #+#              #
#    Updated: 2026/07/21 15:04:34 by sspirig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name
NAME = libft.a

# Complier
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source of files
SRC = ft_strlen.c \
			ft_strcpy.c \

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
		@echo "$(NAME) was created successfully !"
# '$@' => Target name (libft.a)
# '$^' => All dependencies (all obj files .o)


# Compiling every src files to obj files
%.o: %.c
		@echo "[libft] Compiling files ..."
		$(CC) $(CFLAGS) -c $< $@
		@echo "[libft] Compiled: $<"
# '$<' => first dependency (.c file)
# '$@' => target file (.o file)

clean:
		rm -f $(OBJ)
		@echo "[libft] Object files removed !"

fclean: clean
		rm -f $(NAME)
		@echo "[libft] Library removed (full cleanup) !"

re: fclean all
		@echo "[libft] Rebuildi complete !"

# Declare non-file target names
.PHONY: all clean fclean re

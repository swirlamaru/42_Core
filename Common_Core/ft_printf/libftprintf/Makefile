#  ************************************************************************** # 
#                                                                             # 
#                                                         :::      ::::::::   # 
#    Makefile                                           :+:      :+:    :+:   # 
#                                                     +:+ +:+         +:+     # 
#    By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        # 
#                                                 +#+#+#+#+#+   +#+           # 
#    Created: 2026/10/15 23:33:06 by sspirig           #+#    #+#             # 
#    Updated: 2026/10/15 23:33:06 by sspirig          ###   ########.fr       # 
#                                                                             # 
#  ************************************************************************** # 

# Name
NAME = libftprintf.a

# Complier
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source of files
SRC = ft_printf.c print_chars.c print_numbers.c

# Storing objects files from .c srcfiles
OBJ = $(SRC:.c=.o)

# Libft
LIBFT_DIR = ./libft
LIBFT = libft/libft.a

# Archive tool
AR = ar
ARFLAGS = rcs
# 'r' => insert or replace files in archive
# 'c' => create archive if don't already exists
# 's' => create index for symbols

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_DIR)
		cp $(LIBFT) $(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJ)
		@echo "[ft_printf] '$(NAME)' was created successfully !"
# '$@' => Target name (libftprintf.a)
# '$^' => All dependencies (all obj files .o)


%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@
# '$<' => first dependency (.c file)
# '$@' => target file (.o file)

clean:
		make -C $(LIBFT_DIR) clean
		rm -f $(OBJ)
		@echo "[ft_printf] Object files removed !"

fclean: clean
		make -C $(LIBFT_DIR) fclean
		rm -f $(NAME)
		@echo "[ft_printf] Library removed (full cleanup) !"

re: fclean all
		@echo "[ft_printf] Rebuild complete !"

.PHONY: all clean fclean re

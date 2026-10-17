/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 20:15:08 by sspirig           #+#    #+#             */
/*   Updated: 2026/10/17 00:36:37 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	convert_to_hex(size_t n, int is_upcase);
int	print_char(int ch);
int	print_str(char *str);
int	print_ptr(void *ptr);
int	print_int(int nb);
int	print_unsigned_int(unsigned int nb);
int	print_hex_num(unsigned int n, int is_upcase);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 23:44:14 by sspirig           #+#    #+#             */
/*   Updated: 2026/10/16 17:15:00 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	count = write(1, "0x", 2);
	count += convert_to_hex(addr, 0);
	return (count);
}

int	print_int(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	print_unsigned_int(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_unsigned_int(n / 10);
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}

int	print_hex_num(unsigned int n, int is_upcase)
{
	return (convert_to_hex((size_t)n, is_upcase));
}

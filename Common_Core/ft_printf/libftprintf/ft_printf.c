/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 20:13:51 by sspirig           #+#    #+#             */
/*   Updated: 2026/10/17 02:20:19 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_to_hex(size_t n, int is_upcase)
{
	char	*lookup;
	int		count;

	count = 0;
	if (!is_upcase)
		lookup = "0123456789abcdef";
	else
		lookup = "0123456789ABCDEF";
	if (n >= 16)
		count += convert_to_hex(n / 16, is_upcase);
	count += write(1, &lookup[n % 16], 1);
	return (count);
}

int	parse_argtype(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_str(va_arg(args, char *)));
	else if (c == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsigned_int(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hex_num(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (print_hex_num(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	parse_loop(const char *str, va_list args)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	len = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = parse_argtype(str[++i], args);
			if (len == -1)
				return (va_end(args), -1);
			count += len;
		}
		else
			count += write(1, &str[i], 1);
		if (str[i])
			i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	count = 0;
	va_start(args, str);
	count = parse_loop(str, args);
	va_end(args);
	return (count);
}

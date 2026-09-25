/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 00:31:20 by sspirig           #+#    #+#             */
/*   Updated: 2026/09/23 17:12:01 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_putnbr_recursive(long nb)
{
	char	c;

	if (nb >= 10)
		ft_putnbr_recursive(nb / 10);
	c = (char)('0' + (nb % 10));
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb)
{
	long	lnb;

	lnb = nb;
	if (lnb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (lnb < 0)
	{
		write(fd, "-", 1);
		lnb = -lnb;
	}
	ft_putnbr_recursive(lnb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:19:14 by sspirig           #+#    #+#             */
/*   Updated: 2026/10/11 15:48:39 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(int negative)
{
	if (negative)
		return ((int)LONG_MIN);
	return ((int)LONG_MAX);
}

static int	skip_whitespace(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t'
		|| nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		negative;
	int		i;
	long	keep;

	negative = 0;
	keep = 0;
	i = skip_whitespace(nptr);
	if (nptr[i] == 43)
		i++;
	else if (nptr[i] == 45)
	{
		negative = 1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (keep > (LONG_MAX - (nptr[i] - 48)) / 10)
			return (overflow(negative));
		keep = (keep * 10) + (nptr[i] - 48);
		i++;
	}
	if (negative)
		return (-keep);
	return (keep);
}

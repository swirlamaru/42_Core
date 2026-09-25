/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:19:14 by sspirig           #+#    #+#             */
/*   Updated: 2026/07/22 01:41:52 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	negative;
	int	i;
	int	keep;

	negative = 0;
	i = 0;
	keep = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t'
		|| nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r')
	{
		if (str[i] == 45)
			negative = 1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		keep = (keep * 10) + (nptr[i] - 48);
		i++;
	}
	if (negative)
		return (-keep);
	return (keep);
}

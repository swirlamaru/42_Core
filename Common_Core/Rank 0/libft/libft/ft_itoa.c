/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 15:55:12 by sspirig           #+#    #+#             */
/*   Updated: 2026/09/11 15:55:12 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	manage_sign(int n, long *temp_num)
{
	if (n < 0)
	{
		*temp_num = -(long)n;
		return (1);
	}
	*temp_num = n;
	return (0);
}

static int	count_digits(long temp_num)
{
	int	count;

	count = 0;
	if (temp_num == 0)
		count = 1;
	else
	{
		while (temp_num != 0)
		{
			temp_num /= 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		negative;
	int		count;
	long	temp_num;
	int		i;
	char	*result;

	negative = manage_sign(n, &temp_num);
	count = count_digits(temp_num);
	result = malloc(sizeof(char) * (count + negative + 1));
	if (!result)
		return (0);
	result[count + negative] = '\0';
	i = count + negative - 1;
	if (temp_num == 0)
		result[i] = '0';
	while (temp_num > 0)
	{
		result[i] = (temp_num % 10) + '0';
		temp_num /= 10;
		i--;
	}
	if (negative)
		result[0] = '-';
	return (result);
}

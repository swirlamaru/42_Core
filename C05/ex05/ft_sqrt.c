/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 22:29:41 by sspirig           #+#    #+#             */
/*   Updated: 2026/07/08 22:29:44 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb == 0 || nb < 0)
		return (0);
	i = 1;
	while (i < nb / i)
	{
		if (i * i == nb)
			return (i * i);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	int nb = 4;
	printf("%d\n", ft_sqrt(nb));
	return (1);
}*/

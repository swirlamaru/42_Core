/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:52:40 by sspirig           #+#    #+#             */
/*   Updated: 2026/07/09 10:42:34 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (!nb || nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i <= nb)
	{
		result *= nb;
		nb--;
		i++;
	}
	return (result);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_iterative_factorial(3));
	return (0);
} */
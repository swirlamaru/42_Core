/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <email@test.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:49:59 by username          #+#    #+#             */
/*   Updated: 2026/09/04 10:09:04 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	while (s1[j])
		j++;
	result = malloc((sizeof(char) * j) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				result[i] = s1[i];
			j++;
		}
		i++;
	}
}

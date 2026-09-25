/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:53:45 by sspirig           #+#    #+#             */
/*   Updated: 2026/07/24 01:03:54 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (start >= i)
	{
		ptr = malloc(1);
		if (ptr)
			*(char *)ptr = '\0';
		return (ptr);
	}
	if (len > i - start)
		len = i - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
		ptr[i] = s[start + i++];
	ptr[i] = '\0';
	return (ptr);
}

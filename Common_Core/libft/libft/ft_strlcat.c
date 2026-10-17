/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:45:23 by sspirig           #+#    #+#             */
/*   Updated: 2026/10/13 04:40:05 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size == 0)
		return ((dlen + slen) - 1);
	i = 0;
	while (src[i] && (dlen + i) < size - 1)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	if (size > 0)
		dest[dlen + i] = '\0';
	return (dlen + slen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:45:23 by sspirig           #+#    #+#             */
/*   Updated: 2026/10/09 13:09:08 by sspirig          ###   ########.fr       */
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
		return (slen);
	i = 0;
	if (size <= dlen)
		return (size + slen);
	while (src[i] && (dlen + i) < size - 1)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	if (size > 0)
		dest[dlen + i] = '\0';
	return (dlen + slen);
}

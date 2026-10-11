/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: sspirig <sspirig@42lausanne.ch>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/07/24 02:00:19 by sspirig		   #+#	  #+#			  */
/*   Updated: 2026/10/08 17:38:07 by sspirig          ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

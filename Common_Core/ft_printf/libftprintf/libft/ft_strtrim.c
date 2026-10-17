/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <email@test.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:49:59 by username          #+#    #+#             */
/*   Updated: 2026/10/11 15:48:59 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*push_ptr(const char *ptr, int reverse)
{
	if (reverse)
		return (--ptr);
	return (++ptr);
}

static int	in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static const char	*trim(const char *s1, const char *set, int reverse)
{
	const char	*start_ptr;
	const char	*end_ptr;

	end_ptr = s1 + (ft_strlen(s1));
	start_ptr = s1;
	if (reverse)
		start_ptr = end_ptr;
	while (!reverse && start_ptr < end_ptr && in_set(*start_ptr, set))
		start_ptr = push_ptr(start_ptr, reverse);
	while (reverse && start_ptr > s1 && in_set(*(start_ptr - 1), set))
		start_ptr = push_ptr(start_ptr, reverse);
	return (start_ptr);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char const	*rev_ptr;
	char const	*start_ptr;

	if (!s1 || !set)
		return (NULL);
	start_ptr = trim(s1, set, 0);
	rev_ptr = trim(s1, set, 1);
	if (rev_ptr < start_ptr)
		rev_ptr = start_ptr;
	return (ft_substr(s1, start_ptr - s1, rev_ptr - start_ptr));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 10:10:52 by sspirig           #+#    #+#             */
/*   Updated: 2026/09/11 02:39:47 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**malloc_arr(size_t s)
{
	char	**arr;
	size_t	i;

	arr = malloc((s + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (i <= s)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

char	*retrieve_word(char const *s, size_t start_i, size_t end_i)
{
	size_t	s_i;
	size_t	i;
	char	*str;

	str = malloc((end_i - start_i) + 1);
	if (!str)
		return (0);
	i = 0;
	s_i = start_i;
	while (s_i < end_i)
	{
		str[i] = s[s_i];
		s_i++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	fill_arr(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	start;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			arr[count++] = retrieve_word(s, start, i);
		}
		else
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = malloc_arr(count_words(s, c));
	if (!arr)
		return (0);
	fill_arr(arr, s, c);
	return (arr);
}

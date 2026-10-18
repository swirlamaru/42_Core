/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:25:05 by sspirig           #+#    #+#             */
/*   Updated: 2026/10/18 21:36:42 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_end(char *buf)
{
	if (!buf)
		return (0);
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

int	read_line(int fd, char *buf, size_t count)
{
	int	return_value;

	return_value = read(fd, buf, count);
	if (return_value < 0)
		return (-1);
	buf[return_value] = '\0';
	if (return_value == 0)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = 0;
	len2 = 0;
	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;
	i = len1 + len2;
	result = malloc(i + 1);
	if (!result)
		return (free(s1), NULL);
	result[i] = '\0';
	while (len2)
		result[--i] = s2[--len2];
	while (len1)
		result[--i] = s1[--len1];
	free(s1);
	return (result);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	size_t	len;

	len = 0;
	if (!stash || !*stash)
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (len--)
		line[len] = stash[len];
	return (line);
}

char	*ft_update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	while (stash[i + len])
		len++;
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (free(stash), NULL);
	new_stash[len] = '\0';
	while (len--)
		new_stash[len] = stash[i + len];
	free(stash);
	return (new_stash);
}

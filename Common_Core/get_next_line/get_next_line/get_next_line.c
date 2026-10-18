/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:57:26 by sspirig           #+#    #+#             */
/*   Updated: 2026/10/18 21:28:17 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			read_rtnvalue;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!is_end(stash))
	{
		read_rtnvalue = read_line(fd, buf, BUFFER_SIZE);
		if (read_rtnvalue < 0)
			return (free(buf), free(stash), stash = NULL, NULL);
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free(buf), NULL);
		if (read_rtnvalue == 1)
			break ;
	}
	free(buf);
	line = ft_get_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}

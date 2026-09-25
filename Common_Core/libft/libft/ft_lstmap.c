/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspirig <sspirig@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:12:32 by sspirig           #+#    #+#             */
/*   Updated: 2026/09/23 17:09:58 by sspirig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	manage_headntail(t_list *newnode, t_list *newhead, t_list *newtail)
{
	if (!newhead)
		newhead = newnode;
	else
		newtail->next = newnode;
	newtail = newnode;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newhead;
	t_list	*newtail;
	t_list	*newnode;
	void	*newcontent;

	if (!lst || !f || !del)
		return (NULL);
	newhead = NULL;
	newtail = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			del(newcontent);
			ft_lstclear(&newhead, del);
			return (NULL);
		}
		manage_headntail(newnode, newhead, newtail);
		lst = lst->next;
	}
	return (newhead);
}

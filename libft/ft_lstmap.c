/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:36:53 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/07 21:23:30 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*start;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (start);
}

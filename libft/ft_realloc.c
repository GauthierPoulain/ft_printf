/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:47:57 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/07 21:23:30 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *s, size_t size)
{
	char	*new;
	char	*old;
	size_t	i;

	old = s;
	if (!(new = malloc(size)))
		return (NULL);
	i = 0;
	while (old[i] && i < size)
	{
		new[i] = old[i];
		i++;
	}
	new[i] = 0;
	free(s);
	return (new);
}

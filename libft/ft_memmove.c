/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:56:59 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/07 21:23:30 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*bdst;
	const char	*bsrc;

	if (!dst && !src)
		return (NULL);
	i = 0;
	bsrc = src;
	bdst = dst;
	if (src > dst)
	{
		while ((unsigned long)i < len)
		{
			bdst[i] = bsrc[i];
			i++;
		}
	}
	else
		while (len--)
			bdst[len] = bsrc[len];
	return (dst);
}

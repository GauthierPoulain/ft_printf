/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:36:12 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/07 21:23:30 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*castd;
	unsigned char	*casts;

	castd = (unsigned char *)dst;
	casts = (unsigned char *)src;
	while (n--)
	{
		*castd = *casts;
		if (*castd == (unsigned char)c)
			return (castd + 1);
		castd++;
		casts++;
	}
	return (NULL);
}

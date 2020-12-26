/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 07:40:35 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/16 13:50:00 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *casts1;
	unsigned char *casts2;

	casts1 = (unsigned char *)s1;
	casts2 = (unsigned char *)s2;
	while (n--)
	{
		if (*casts1 != *casts2)
			return (*casts1 - *casts2);
		casts1++;
		casts2++;
	}
	return (0);
}

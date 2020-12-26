/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 08:53:31 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/16 13:48:23 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char casts1;
	unsigned char casts2;

	while (n-- > 0)
	{
		casts1 = *s1++;
		casts2 = *s2++;
		if (casts1 != casts2)
			return (casts1 - casts2);
		if (!casts1)
			return (0);
	}
	return (0);
}

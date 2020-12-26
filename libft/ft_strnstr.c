/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:00:38 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/07 21:23:30 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;

	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	i = -1;
	while (haystack[++i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[j] && i + j < len)
		{
			j++;
			if (!needle[j])
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}

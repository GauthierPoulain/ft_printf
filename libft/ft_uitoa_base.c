/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 13:31:17 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/26 15:04:09 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_base_u(unsigned long hexa, int base, char *str, int i)
{
	while (hexa != 0)
	{
		if ((hexa % base) < 10)
			str[i - 1] = (hexa % base) + '0';
		else
			str[i - 1] = (hexa % base) + 87;
		hexa /= base;
		i--;
	}
	return (str);
}

char		*ft_uitoa_base(unsigned long nbr, int base)
{
	char			*str;
	unsigned long	hexa;
	int				i;

	str = NULL;
	i = 0;
	hexa = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = 0;
	str = set_base_u(hexa, base, str, i);
	return (str);
}

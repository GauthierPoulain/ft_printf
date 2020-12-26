/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:25:17 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/13 10:12:46 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int			ft_atoi_base(char *str, char *base)
{
	int		s;
	int		i;
	int		res;
	int		negative;
	int		base_length;

	base_length = 0;
	while (base[base_length])
		++base_length;
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t' || str[s] == '\r'
		|| str[s] == '\n' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	negative = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) ||
		(str[i] != '-' && str[i] != '+')))
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_length) + (get_nb(str[i], base));
	return (res * negative);
}

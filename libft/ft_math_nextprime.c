/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_nextprime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:44:09 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/07 21:23:30 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_find_next_prime(int nb)
{
	int		i;

	i = nb;
	while (ft_math_isprime(i) == 0)
		i++;
	return (i);
}

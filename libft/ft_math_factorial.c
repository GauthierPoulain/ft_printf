/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_factorial.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:36:19 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/05 18:39:12 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_math_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb > 1)
		return (nb * ft_math_factorial(nb - 1));
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:37:43 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/05 18:39:31 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_math_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power < 1)
		return (1);
	else
		return (nb * ft_math_power(nb, power - 1));
}

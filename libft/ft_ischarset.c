/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:44:50 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/13 10:13:04 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_ischarset(int c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

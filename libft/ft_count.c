/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 20:20:17 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/13 20:22:40 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_count(char *str, int c)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			count++;
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:18:28 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/11 12:23:59 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_rev_tab(char *tab)
{
	int			i;
	int			size;

	size = 0;
	while (tab[size])
		size++;
	i = size / 2;
	while (--i >= 0)
		ft_swap(&tab[i], &tab[size - 1 - i]);
}

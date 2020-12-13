/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:15:38 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/13 13:42:53 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		fill(int zero, size_t size, int fd)
{
	size_t	i;
	
	i = 0;
	while (i < size)
	{
		if (zero)
			ft_putchar_fd('0', fd);
		else
			ft_putchar_fd(' ', fd);
		i++;
	}

}
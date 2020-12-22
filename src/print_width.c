/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:36:23 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/22 14:22:46 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_width(int width, int i, int zero, t_flags *flags)
{
	while (width - i > 0)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		width--;
		flags->print++;
	}
}

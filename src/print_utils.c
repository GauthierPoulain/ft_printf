/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:36:23 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/26 14:32:50 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		print_width(int width, int i, int zero, t_flags *flags)
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

void		print_spaces(t_flags *flags, char *tmp)
{
	if (flags->minus)
	{
		flags->print += ft_putstr_fd(tmp, 1);
		print_width(flags->width, ft_strlen(tmp), 0, flags);
	}
	else if (flags->zero && !(flags->has_dot))
	{
		print_width(flags->width, ft_strlen(tmp), 1, flags);
		flags->print += ft_putstr_fd(tmp, 1);
	}
	else
	{
		print_width(flags->width, ft_strlen(tmp), 0, flags);
		flags->print += ft_putstr_fd(tmp, 1);
	}
}

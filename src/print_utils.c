/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:36:23 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/28 19:01:04 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		print_width(int width, int i, int zero, t_flags *flags)
{
	while (width-- - i > 0)
	{
		if (zero)
			flags->print += ft_putchar_fd('0', 1);
		else
			flags->print += ft_putchar_fd(' ', 1);
	}
}

void		print_spaces(t_flags *flags, char *str)
{
	if (flags->minus)
	{
		flags->print += ft_putstr_fd(str, 1);
		print_width(flags->width, ft_strlen(str), 0, flags);
	}
	else if (flags->zero && !(flags->has_dot))
	{
		print_width(flags->width, ft_strlen(str), 1, flags);
		flags->print += ft_putstr_fd(str, 1);
	}
	else
	{
		print_width(flags->width, ft_strlen(str), 0, flags);
		flags->print += ft_putstr_fd(str, 1);
	}
}

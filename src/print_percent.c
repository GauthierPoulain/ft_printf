/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:20:17 by gapoulai          #+#    #+#             */
/*   Updated: 2021/01/03 01:46:03 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

static void	print_percent_zero(t_flags *flags, char c)
{
	print_width(flags->width, flags->zero, 1, flags);
	// else if (flags->width > flags->dot && flags->dot > 0)
	// 	print_width(flags->width, 1, 0, flags);
	// else
	// 	print_width(flags->width, 1, flags->zero, flags);
	print_width(flags->dot, 1, 1, flags);
	flags->print += ft_putchar_fd(c, 1);
}


void		print_percent(t_flags *flags)
{
	if (flags->zero)
		print_percent_zero(flags, '%');
	else
		print_char(flags, '%');
}

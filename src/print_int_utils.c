/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:52:17 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/28 19:01:04 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

static void	longerthadot(t_flags *flags, char *str)
{
	if (flags->width > flags->dot && flags->dot > 0)
		print_width(flags->width, ft_strlen(str), 0, flags);
	else if (flags->zero)
	{
		flags->print += ft_putchar_fd('-', 1);
		print_width(flags->width, ft_strlen(str), 1, flags);
		flags->print += ft_putstr_fd(str + 1, 1);
		return ;
	}
	else
		print_width(flags->width, ft_strlen(str), 0, flags);
	flags->print += ft_putstr_fd(str, 1);
}

static void	print_nb_neg(t_flags *flags, char *str)
{
	if ((int)ft_strlen(str) > flags->dot)
		longerthadot(flags, str);
	else
	{
		if (flags->dot)
			print_width(flags->width, flags->dot + 1, 0, flags);
		else
			print_width(flags->width, ft_strlen(str), 0, flags);
		flags->print += ft_putchar_fd('-', 1);
		print_width(flags->dot, ft_strlen(str) - 1, 1, flags);
		flags->print += ft_putstr_fd(str + 1, 1);
	}
}

void		int_print_dot(t_flags *flags, int nb, char *str)
{
	if (nb < 0)
		print_nb_neg(flags, str);
	else
	{
		if ((int)ft_strlen(str) < flags->dot)
			print_width(flags->width, flags->dot, 0, flags);
		else if (flags->width > flags->dot && flags->dot > 0)
			print_width(flags->width, ft_strlen(str), 0, flags);
		else
			print_width(flags->width, ft_strlen(str), flags->zero, flags);
		print_width(flags->dot, ft_strlen(str), 1, flags);
		flags->print += ft_putstr_fd(str, 1);
	}
}

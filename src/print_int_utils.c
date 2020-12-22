/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:52:17 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/22 15:00:09 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	int_print_dot_utils_utils(t_flags *flags, char *tmp)
{
	if (flags->width > flags->dot && flags->dot > 0)
		print_width(flags->width, ft_strlen(tmp), 0, flags);
	else if (flags->zero)
	{
		flags->type += ft_putchar_fd('-', 1);
		print_width(flags->width, ft_strlen(tmp), 1, flags);
		flags->print += ft_putstr_fd(tmp + 1, 1);
		return ;
	}
	else
		print_width(flags->width, ft_strlen(tmp), 0, flags);
	flags->print += ft_putstr_fd(tmp, 1);
}

static void	int_print_dot_utils(t_flags *flags, char *tmp)
{
	if ((int)ft_strlen(tmp) > flags->dot)
		int_print_dot_utils_utils(flags, tmp);
	else
	{
		if (flags->dot)
			print_width(flags->width, flags->dot + 1, 0, flags);
		else
			print_width(flags->width, ft_strlen(tmp), 0, flags);
		flags->print += ft_putchar_fd('-', 1);
		print_width(flags->dot, ft_strlen(tmp) - 1, 1, flags);
		flags->print += ft_putstr_fd(tmp + 1, 1);
	}
}

void		int_print_dot(t_flags *flags, int nb, char *tmp)
{
	if (nb < 0)
		int_print_dot_utils(flags, tmp);
	else
	{
		if ((int)ft_strlen(tmp) < flags->dot)
			print_width(flags->width, flags->dot, 0, flags);
		else if (flags->width > flags->dot && flags->dot > 0)
			print_width(flags->width, ft_strlen(tmp), 0, flags);
		else
			print_width(flags->width, ft_strlen(tmp), flags->zero, flags);
		print_width(flags->dot, ft_strlen(tmp), 1, flags);
		flags->print += ft_putstr_fd(tmp, 1);
	}
}

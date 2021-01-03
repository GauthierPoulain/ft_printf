/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:52:22 by gapoulai          #+#    #+#             */
/*   Updated: 2021/01/03 02:43:40 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

static void		ft_minus(t_flags *flags, char *tmp, unsigned int nbr)
{
	if (flags->has_dot)
	{
		if (!(flags->dot) && nbr == 0)
			print_width(flags->width, flags->dot, 0, flags);
		else
		{
			print_width(flags->dot, ft_strlen(tmp), 1, flags);
			flags->print += ft_putstr_fd(tmp, 1);
			if ((int)ft_strlen(tmp) < flags->dot)
				print_width(flags->width, flags->dot, 0, flags);
			else
				print_width(flags->width, ft_strlen(tmp), 0, flags);
		}
	}
	else
		print_spaces(flags, tmp);
}

static void		ft_print_dot(t_flags *flags, char *tmp)
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

void			print_base(t_flags *flags, int base, unsigned int nbr, int caps)
{
	char *tmp;

	tmp = ft_itoa_base(nbr, base);
	if (caps)
		ft_touppercase(tmp);
	if (flags->minus)
		ft_minus(flags, tmp, nbr);
	else
	{
		if (!(flags->dot) && flags->has_dot && nbr == 0)
			print_width(flags->width, flags->dot, 0, flags);
		else if (flags->dot)
			ft_print_dot(flags, tmp);
		else
			print_spaces(flags, tmp);
	}
	free(tmp);
}

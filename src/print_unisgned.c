/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unisgned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:12:19 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/28 19:01:04 by gapoulai         ###   ########lyon.fr   */
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

void			print_unsigned(t_flags *flags, unsigned int nbr)
{
	char *tmp;

	tmp = ft_uitoa(nbr);
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

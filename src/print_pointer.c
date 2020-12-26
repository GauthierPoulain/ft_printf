/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:31:20 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/26 13:58:11 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	void	print_other(t_flags *flags, char *tmp)
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

static void		ft_minus(t_flags *flags, char *tmp, unsigned long nbr)
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
		print_other(flags, tmp);
}

static void		ft_not_minus(t_flags *flags, char *tmp, int nbr)
{
	if (!(flags->dot) && flags->has_dot && nbr == 0)
		print_width(flags->width, flags->dot, 0, flags);
	else if (flags->dot)
	{
		if ((int)ft_strlen(tmp) < flags->dot)
			print_width(flags->width, flags->dot, 0, flags);
		else
			print_width(flags->width, ft_strlen(tmp), 0, flags);
		print_width(flags->dot, ft_strlen(tmp), 1, flags);
		flags->print += ft_putstr_fd(tmp, 1);
	}
	else
		print_other(flags, tmp);
}

void			print_pointer(t_flags *flags, size_t adr)
{
	char	*tmp;
	char	*res;

	tmp = ft_uitoa_base(adr, 16);
	ft_tolowercase(tmp);
	res = ft_strjoin("0x", tmp);
	free(tmp);
	if (flags->minus)
		ft_minus(flags, res, adr);
	else
		ft_not_minus(flags, res, adr);
	free(res);
}

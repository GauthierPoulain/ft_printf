/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:21:26 by gapoulai          #+#    #+#             */
/*   Updated: 2021/01/03 01:51:47 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

static void	str_print_dot(t_flags *flags, char *str, size_t len)
{
	if (!len && (ft_strlen(str) > (size_t)flags->dot))
		print_width(flags->width, 0, 0, flags);
	else if (flags->minus)
	{
		flags->print += ft_putstrn_fd(str, flags->dot, 1);
		print_width(flags->width, flags->dot, 0, flags);
	}
	else
	{
		print_width(flags->width, flags->dot, 0, flags);
		flags->print += ft_putstrn_fd(str, flags->dot, 1);
	}
}

void		print_string(t_flags *flags, char *str)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->dot >= 0 && (size_t)flags->dot > ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->minus)
	{
		if (flags->dot >= 0 && flags->has_dot == 1)
			str_print_dot(flags, str, len);
		else
		{
			flags->print += ft_putstr_fd(str, 1);
			print_width(flags->width, ft_strlen(str), 0, flags);
		}
	}
	else if (flags->dot >= 0 && flags->has_dot == 1)
		str_print_dot(flags, str, len);
	else
	{
		print_width(flags->width, ft_strlen(str), 0, flags);
		flags->print += ft_putstr_fd(str, 1);
	}
}

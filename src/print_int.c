/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:33:17 by gapoulai          #+#    #+#             */
/*   Updated: 2021/01/03 02:12:17 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

static void	int_print_minus(t_flags *flags, char *tmp)
{
	if ((int)ft_strlen(tmp) > flags->dot)
	{
		flags->print += ft_putstr_fd(tmp, 1);
		print_width(flags->width, ft_strlen(tmp), 0, flags);
	}
	else
	{
		flags->print += ft_putchar_fd('-', 1);
		print_width(flags->dot, ft_strlen(tmp) - 1, 1, flags);
		flags->print += ft_putstr_fd(tmp + 1, 1);
		if (flags->dot)
			print_width(flags->width, flags->dot + 1, 0, flags);
		else
			print_width(flags->width, ft_strlen(tmp), 0, flags);
	}
}

static void	int_minus(t_flags *flags, int nb, char *tmp)
{
	if (!(flags->dot) && nb == 0)
		print_width(flags->width, flags->dot, 0, flags);
	else if (nb < 0)
		int_print_minus(flags, tmp);
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

static void	int_print_zero(t_flags *flags, int nb, char *tmp)
{
	if (nb < 0)
	{
		if (flags->has_dot)
		{
			print_width(flags->width, ft_strlen(tmp), 0, flags);
			flags->print += ft_putstr_fd(tmp, 1);
		}
		else
		{
			flags->print += ft_putchar_fd('-', 1);
			print_width(flags->width, ft_strlen(tmp), 1, flags);
			flags->print += ft_putstr_fd(tmp + 1, 1);
		}
	}
	else
		print_spaces(flags, tmp);
}

void		print_int(t_flags *flags, int nb)
{
	char	*tmp;

	tmp = ft_itoa(nb);
	if (flags->space)
		flags->print += ft_putchar_fd(' ', 1);
	if (flags->minus)
	{
		if (flags->has_dot)
			int_minus(flags, nb, tmp);
		else
			print_spaces(flags, tmp);
	}
	else
	{
		if (!flags->dot && flags->has_dot && nb == 0)
			print_width(flags->width, flags->dot, 0, flags);
		else if (flags->dot)
			int_print_dot(flags, nb, tmp);
		else if (flags->zero)
			int_print_zero(flags, nb, tmp);
		else
			print_spaces(flags, tmp);
	}
	free(tmp);
}

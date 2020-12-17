/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:21:00 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/17 16:53:03 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_in_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int len;

	len = 0;
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar_fd('-', 1);
	if (flags.dot >= 0)
		len += print_width(flags.dot, ft_strlen(d_i), 1);
	len += ft_putstr_fd(d_i, 1);
	return (len);
}

static int	ft_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int len;

	len = 0;
	if (flags.minus == 1)
		len += ft_in_put_part_int(d_i, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		len += print_width(flags.width, 0, 0);
	}
	else
		len += print_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		len += ft_in_put_part_int(d_i, save_i, flags);
	return (len);
}


int			ft_print_int(int i, t_flags flags)
{
	char	*d_i;
	int		save_i;
	int		char_count;

	save_i = i;
	char_count = 0;
	if (flags.dot == 0 && i == 0)
	{
		char_count += print_width(flags.width, 0, 0);
		return (char_count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putchar_fd('-', 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	d_i = ft_itoa(i);
	char_count += ft_put_part_int(d_i, save_i, flags);
	free(d_i);
	return (char_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:21:09 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/17 14:53:12 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_char(char c, t_flags flags)
{
	int		len;

	len = 0;
	if (flags.minus)
		ft_putchar_fd(c, 1);
	len += print_width(flags.width, 1, 0);
	if (!flags.minus)
		ft_putchar_fd(c, 1);
	return (len + 1);
}

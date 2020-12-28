/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:16:36 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/28 19:01:04 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		print_char(t_flags *flags, char c)
{
	if (flags->minus)
		flags->print += ft_putchar_fd(c, 1);
	print_width(flags->width, 1, 0, flags);
	if (!flags->minus)
		flags->print += ft_putchar_fd(c, 1);
}

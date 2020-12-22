/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:40:44 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/22 11:28:46 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		init_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->has_dot = 0;
	flags->len = 0;
	flags->minus = 0;
	flags->print = 0;
	flags->star = 0;
	flags->type = 0;
	flags->width = 0;
	flags->zero = 0;
}

void		reset_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->has_dot = 0;
	flags->len = 0;
	flags->minus = 0;
	flags->star = 0;
	flags->type = 0;
	flags->width = 0;
	flags->zero = 0;
}

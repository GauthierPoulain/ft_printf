/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:22:29 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/22 13:47:40 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		get_type(t_flags *flags, va_list lst)
{
	if (flags->type == 'c')
		return ;
	if (flags->type == 's')
		return ;
	if (flags->type == 'p')
		return ;
	if (flags->type == 'd' || flags->type == 'i')
		print_int(flags, va_arg(lst, int));
	if (flags->type == 'u')
		return ;
	if (flags->type == 'x')
		return ;
	if (flags->type == 'X')
		return ;
	if (flags->type == '%')
		return ;
}

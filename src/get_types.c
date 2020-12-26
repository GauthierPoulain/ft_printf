/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:22:29 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/26 17:27:02 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		get_type(t_flags *flags, va_list lst)
{
	if (flags->type == 'c')
		print_char(flags, va_arg(lst, int));
	if (flags->type == 's')
		print_string(flags, va_arg(lst, char *));
	if (flags->type == 'p')
		print_pointer(flags, va_arg(lst, size_t));
	if (flags->type == 'd' || flags->type == 'i')
		print_int(flags, va_arg(lst, int));
	if (flags->type == 'u')
		print_unsigned(flags, va_arg(lst, unsigned int));
	if (flags->type == 'x')
		print_hexa(flags, va_arg(lst, unsigned int), 0);
	if (flags->type == 'X')
		print_hexa(flags, va_arg(lst, unsigned int), 1);
	if (flags->type == '%')
		print_percent(flags);
}

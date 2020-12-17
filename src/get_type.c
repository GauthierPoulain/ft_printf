/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:05:42 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/17 14:11:58 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		get_type(int c, t_flags flags, va_list lst)
{
	int len;

	len = 0;
	if (c == 'c')
		return (print_char((char)va_arg(lst, int), flags));
	// else if (c == 's')
	// 	return (ft_treat_string(va_arg(lst, char *), flags));
	// else if (c == 'p')
	// 	return (ft_treat_pointer(va_arg(lst, unsigned long long), flags));
	else if (c == 'd' || c == 'i')
		return (ft_print_int((int)va_arg(lst, int), flags));
	// else if (c == 'u')
	// 	return (ft_treat_uint((unsigned int)va_arg(lst, unsigned int),
	// 		flags));
	// else if (c == 'x')
	// 	return (ft_treat_hexa(va_arg(lst, unsigned int), 1, flags));
	// else if (c == 'X')
	// 	return (ft_treat_hexa(va_arg(lst, unsigned int), 0, flags));
	// else if (c == '%')
	// 	return (ft_treat_percent(flags));
	return (0);
}

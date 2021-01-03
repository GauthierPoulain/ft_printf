/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:37:42 by gapoulai          #+#    #+#             */
/*   Updated: 2021/01/03 02:42:53 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list		lst;
	t_flags		flags;

	va_start(lst, s);
	if (!s)
		return (-1);
	init_flags(&flags);
	while (*s)
	{
		if (*s == '%' && s[1])
		{
			s += parse_flags(&flags, lst, (char *)s);
			if (ft_ischarset(*s, CHARSET))
			{
				get_type(&flags, lst);
				s++;
			}
			else
				flags.print += ft_putchar_fd(*s, 1);
		}
		else
			flags.print += ft_putchar_fd(*s++, 1);
	}
	va_end(lst);
	return (flags.print);
}

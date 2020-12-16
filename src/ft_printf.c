/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:58:38 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/16 12:08:31 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_printf(const char *s, ...)
{
	va_list		list;
	size_t		len;

	va_start(list, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			len += ft_putchar_fd(*s, 1);
			s++;
			
		}
		else
		{
			len += ft_putchar_fd(*s, 1);
			s++;
		}
	}
	return (len);
}
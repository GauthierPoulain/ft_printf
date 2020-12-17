/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:14:44 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/17 14:25:03 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

// va_arg(lst, void *)

int				ft_printf(const char *s, ...)
{
	int		len;
	t_flags	flags;
	va_list	lst;

	va_start(lst, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			flags = init_flags();
			s++;
			s += flag_parse(s, &flags, lst);
			// printf("[%c, %c, %d]", flags.type, *s, istype(*s));
			if (istype(*s))
				len += get_type((char)flags.type, flags, lst);
			else if (*s)
				len += ft_putchar_fd(*s, 1);
			s++;
		}
		else
			len += ft_putchar_fd(*s++, 1);
	}
	va_end(lst);
	return (len);
}

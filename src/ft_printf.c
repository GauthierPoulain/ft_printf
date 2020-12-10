/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:29:03 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/10 12:44:38 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	count_va_args(const char *s)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (s[++i])
		if (s[i] == '%')
			count++;
	return (count);
}

int		ft_printf(const char *s, ...)
{
	va_list		valist;
	size_t		vacount;
	size_t		i;
	char		*str;

	vacount = count_va_args(s);
	va_start(valist, s);
	i = 0;
	while (i < vacount)
	{
		str = va_arg(valist, char *);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(" : ", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	(void)s;
	return (1);
}

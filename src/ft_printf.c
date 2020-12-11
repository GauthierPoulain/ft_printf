/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:29:03 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/11 13:31:28 by gapoulai         ###   ########lyon.fr   */
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

static void		print_adress(void *element, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(ft_nbr_base((int)element, HEXA_BASE), fd);
}

static void		print_type(char type, void *element, int fd)
{
	if (type == 'c')
		ft_putchar_fd((char)element, fd);
	else if (type == 's')
		ft_putstr_fd((char *)element, fd);
	else if (type == 'p')
		print_adress(element, fd);
	else if (type == 'd' || type == 'i')
		ft_putnbr_fd((int)element, fd);
	else if (type == 'u')
		ft_putnbr_fd((unsigned int)element, fd);
	else if (type == 'x')
		ft_putstr_fd(ft_nbr_base((int)element, HEXA_BASE), fd);
	else if (type == 'X')
		ft_putstr_fd(ft_nbr_base((int)element, HEXA_BASE_CAPS), fd);
	else if (type == '%')
		ft_putchar_fd('%', fd);
}

int				ft_printf(const char *s, ...)
{
	va_list		valist;
	char		current;

	va_start(valist, s);
	while ((current = *s))
	{
		if (current == '%')
		{
			s++;
			print_type(*s, va_arg(valist, void*), 1);
		}
		else
			ft_putchar_fd(current, 1);
		s++;
	}
	(void)s;
	return (1);
}

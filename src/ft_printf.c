/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:29:03 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/13 21:14:20 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t			count_va_args(const char *s)
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

static size_t	print_type(char type, void *element, t_flags *flags, int fd)
{
	if (type == 'c')
		return (0);
	if (type == 's')
		return (0);
	if (type == 'p')
		return (0);
	if (type == 'd')
		return (print_int((int)element, flags, fd));
	if (type == 'i')
		return (0);
	if (type == 'u')
		return (0);
	if (type == 'x')
		return (0);
	if (type == 'X')
		return (0);
	if (type == '%')
		return (0);
	return (0);
}

int				ft_printf(const char *s, ...)
{
	va_list		valist;
	int			len;
	t_flags		*flags;
	int			tmp;

	len = 0;
	va_start(valist, s);
	while (*s)
	{
		// if (*s == '%')
		// 	printf("%d\n", check_flags(s + 1));
		if (*s == '%' && get_flag_len(s + 1) != -1)
		{
			s++;
			if (check_flags(s))
			{
			if (!(flags = get_flags(s)))
				return (0);
			tmp = print_type(*s, va_arg(valist, void *), flags, 1);
			len += tmp;
			if (tmp == -1)
				return (0);	
			}
			s += get_flag_len(s);
		}
		else
		{
			ft_putchar_fd(*s, 1);
			len++;
		}
		s++;
	}
	free(flags);
	return (len);
}

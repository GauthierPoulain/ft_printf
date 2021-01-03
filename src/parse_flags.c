/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:28:37 by gapoulai          #+#    #+#             */
/*   Updated: 2021/01/03 02:43:08 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

int			parse_flags(t_flags *flags, va_list lst, char *s)
{
	int		i;

	i = 0;
	reset_flags(flags);
	if (s[1] == ' ')
		flags->space = 1;
	while (!flags->type && !ft_ischarset(s[++i], CHARSET) && s[i])
	{
		if (s[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (s[i] == '.')
			i += parse_dot(&s[i], flags, lst);
		if (s[i] == '-')
			parse_minus(flags);
		if (s[i] == '*')
			parse_star(lst, flags);
		if (ft_isdigit(s[i]))
			parse_digit(s[i], flags);
		if (ft_ischarset(s[i], CHARSET))
			flags->type = s[i];
	}
	flags->type = s[i];
	return (i);
}

int			parse_dot(char *s, t_flags *flags, va_list lst)
{
	int		i;

	i = 1;
	flags->has_dot = 1;
	if (s[i] == '*')
	{
		flags->dot = va_arg(lst, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(s[i]))
		{
			flags->dot = (flags->dot * 10) + (s[i] - '0');
			i++;
		}
	}
	return (i);
}

void		parse_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

void		parse_star(va_list lst, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(lst, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
}

void		parse_digit(char c, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = flags->width * 10 + (c - '0');
}

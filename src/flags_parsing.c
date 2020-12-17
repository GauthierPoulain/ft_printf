/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:13:16 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/17 14:53:12 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// int			ft_flag_dot(const char *save, int start,
// 	t_flags *flags, va_list args)
// {
// 	int i;

// 	i = start;
// 	i++;
// 	if (save[i] == '*')
// 	{
// 		flags->dot = va_arg(args, int);
// 		i++;
// 	}
// 	else
// 	{
// 		flags->dot = 0;
// 		while (ft_isdigit(save[i]))
// 			flags->dot = (flags->dot * 10) + (save[i++] - '0');
// 	}
// 	return (i);
// }


int			ft_flag_dot(const char *s, t_flags *flags, va_list args)
{
	int		i;

	i = 1;
	if (s[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(s[i]))
			flags->dot = (flags->dot * 10) + (s[i++] - '0');
	}
	return (i);
}

t_flags		ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

t_flags		ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

int			flag_parse(const char *s, t_flags *flags, va_list lst)
{
	int		i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || isflag(s[i]) || istype(s[i])))
	{
		if (s[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (s[i] == '.')
			i += ft_flag_dot(s + i, flags, lst);
		if (s[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (s[i] == '*')
			*flags = ft_flag_width(lst, *flags);
		if (ft_isdigit(s[i]))
			*flags = ft_flag_digit(s[i], *flags);
		if (istype(s[i]))
		{
			flags->type = s[i];
			break;
		}
		i++;
	}
	return (i);
}
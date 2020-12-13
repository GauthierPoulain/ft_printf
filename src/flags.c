/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:42:13 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/13 17:15:29 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			check_flags(const char *s)
{
	int		i;
	int		width;
	int		fill;
	int		justify;

	justify = 0;
	width = 0;
	fill = 0;
	i = -1;
	while (!ft_ischarset(s[++i], "cspduxX%"))
	{
		if (!justify && !width && s[i] == '-')
			justify = 1;
		else if (!fill && s[i] == '.')
			fill = 1;
		else if (ft_isdigit(s[i]))
		{
			while (ft_isdigit(s[i]))
				i++;
			width = i--;
		}
		else
			return (-1);
	}
	return (i);
}

t_flags		*get_flags(const char *s)
{
	size_t	i;
	t_flags *flags;
	size_t	tmp;

	if (!(flags = malloc(sizeof(t_flags))))
		return (NULL);
	flags->justify_left = 0;
	flags->fill_zero = 0;
	flags->width = 0;
	i = -1;
	while (!ft_ischarset(s[++i], "cspdiuxX%"))
	{
		if (s[i] == '.')
			flags->fill_zero = 1;
		else if (s[i] == '-')
			flags->justify_left = 1;
		else if (ft_isdigit(s[i]))
		{
			tmp = 0;
			while (ft_isdigit(s[i]))
				tmp = (size_t)ft_popnbr(flags->width, s[i++] - '0');
			flags->width = (size_t)ft_math_max(tmp, flags->width);
			i--;
		}
	}
	return (flags);
}

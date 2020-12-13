/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:42:13 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/13 21:17:10 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// int			check_flags(const char *s)
// {
// 	int		i;
// 	int		width;
// 	int		fill;
// 	int		justify;

// 	justify = 0;
// 	width = 0;
// 	fill = 0;
// 	i = -1;
// 	while (!ft_ischarset(s[++i], "cspduxX%"))
// 	{
// 		if (!justify && !width && s[i] == '-')
// 			justify = 1;
// 		else if (!fill && s[i] == '.')
// 			fill = 1;
// 		else if (ft_isdigit(s[i]))
// 		{
// 			while (ft_isdigit(s[i]))
// 				i++;
// 			width = i--;
// 		}
// 		else
// 			return (-1);
// 	}
// 	return (i);
// }

// t_flags		*get_flags(const char *s)
// {
// 	size_t	i;
// 	t_flags *flags;
// 	size_t	tmp;

// 	if (!(flags = malloc(sizeof(t_flags))))
// 		return (NULL);
// 	flags->justify_left = 0;
// 	flags->fill_zero = 0;
// 	flags->width = 0;
// 	i = -1;
// 	while (!ft_ischarset(s[++i], "cspdiuxX%"))
// 	{
// 		if (s[i] == '.')
// 			flags->fill_zero = 1;
// 		else if (s[i] == '-')
// 			flags->justify_left = 1;
// 		else if (ft_isdigit(s[i]))
// 		{
// 			tmp = 0;
// 			while (ft_isdigit(s[i]))
// 				tmp = (size_t)ft_popnbr(flags->width, s[i++] - '0');
// 			flags->width = (size_t)ft_math_max(tmp, flags->width);
// 			i--;
// 		}
// 	}
// 	return (flags);
// }

static int	get_justify(const char *s)
{
	char	*str;
	int		i;
	int		valid;
	
	if (!(str = ft_strchr(s, (char)'-')))
		return (0);
	i = 0;
	while (str[i] == '-')
		i++;
	valid = 1;
	if (ft_strchr((const char *)str, (char)'-'))
		valid = -1;
	return (valid);
}

// static int	get_total_size(const char *s)
// {
// 	int		size;
	
// 	size = 0;
// 	while ()
// 	{
		
// 	}
	
// }

int		get_flag_len(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && !ft_ischarset(s[++i], "cspdiuxX%"))
		i++;
	if (!s[i])
		return (-1);
	return (i);
}

int		print_invalid_flag(const char *s, int fd)
{
	char	*tmp;
	char	*res;
	
	res = NULL;
	if ((tmp = ft_strchr(s, (int)'.')))
		if (ft_strchr((const char *)tmp, (int)'-'))
			{
				res = ft_strdup(tmp);
				res[ft_get_index(tmp, (int)'-')] = 0;
				res = ft_strjoin(res, "0");
				res = ft_strjoin(res, ft_strchr(tmp, (int)'-') + 1);
			}
	ft_putchar_fd('%', fd);
	ft_putstr_fd(res, fd);
	return (0);
}

int			check_flags(const char *s)
{
	char *tmp;

	if ((tmp = ft_strchr(s, (int)'.')))
		if (ft_strchr((const char *)tmp, (int)'-'))
			return (print_invalid_flag(s, 1));
			
	return (1);
}

t_flags		*get_flags(const char *s)
{
	t_flags		*flags;

	if (!(flags = malloc(sizeof(t_flags))))
		return (NULL);
	if ((flags->justify_left = get_justify(s)) == -1)
		return (NULL);
	flags->total_size = 0;
	flags->zero_size = 0;

	

	return (flags);
}

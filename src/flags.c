/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:42:13 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/15 11:41:34 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int			print_invalid_flag(const char *s, int fd)
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












size_t		get_flag_len(const char *s)
{
	size_t	i;

	i = 1;
	while (s[i] && s[i] != '%' && !ft_isalpha(s[i]))
		i++;
	return (i);
}

char		*get_flag_str(const char *s)
{
	char	*str;

	if (!(str = ft_strndup(s, get_flag_len(s))))
		return (NULL);
	return (str);
}

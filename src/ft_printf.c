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

static size_t	print_type(char type, void *element, int fd)
{
	if (type == 'c')
		return (print_char(element, fd));
	else if (type == 's')
		return (print_string(element, fd));
	else if (type == 'p')
		return (print_pointer_adress(element, fd));
	else if (type == 'd' || type == 'i')
		ft_putnbr_fd((int)element, fd);
	else if (type == 'u')
		ft_putnbr_fd((unsigned int)element, fd);
	else if (type == 'x')
		ft_putstr_fd(ft_convert_base((char *)element, DECIMAL, HEXA_BASE), fd);
	else if (type == 'X')
		ft_putstr_fd(ft_convert_base((char *)element, DECIMAL, HEXA_BASE_CAPS),
		fd);
	else if (type == '%')
		ft_putchar_fd('%', fd);
	return (0);
}

t_flags		*get_flags(char **s)
{
	size_t	i;
	t_flags	*flags;

	i = 0;
	if (!(flags = malloc(sizeof(t_flags))))
		return (NULL);
	flags->width = -1;
	flags->justify_left = 0;
	while (!ft_ischarset(*s[i], "cspduxX%"))
	{
		if (flags->width == -1)
		{
			ft_putnbr_fd(i, 1);
			while (ft_isdigit(*s[i]))
			{
				flags->width *= 10;
				flags->width = flags->width + (*s[i] + '0');
				i++;
			}
		}
		if (*s[i] == '-')
			flags->justify_left = 1;
		i++;
	}
	s = &s[i];
	return (flags);
}

int				ft_printf(const char *s, ...)
{
	va_list		valist;
	char		current;
	size_t		len;
	t_flags		*flags;
	char		*cast;

	cast = (char *)s;
	len = 0;
	va_start(valist, s);
	while ((current = *cast))
	{
		if (current == '%')
		{
			cast++;
			flags = get_flags(&cast);
			ft_putchar_fd('1', 1);
			len += print_type(*cast, va_arg(valist, void*), 1);
		}
		else
		{
			ft_putchar_fd(current, 1);
			len++;
		}
		cast++;
	}
	free(flags);
	return (len);
}

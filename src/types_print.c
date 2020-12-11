/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:12:27 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/11 22:29:47 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	print_char(void *element, int fd)
{
	if ((char)element)
	{
		ft_putchar_fd((char)element, fd);
		return (1);
	}
	return (0);
}

size_t	print_string(void *element, int fd)
{
	ft_putstr_fd((char *)element, fd);
	return (ft_strlen((char *)element));
}

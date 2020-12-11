/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_adress.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 22:29:03 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/11 22:29:05 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	print_pointer_adress(void *element, int fd)
{
	size_t	cast;
	char *str;

	cast = (size_t)element;
	str = ft_convert_base(ft_itoa(cast), DECIMAL, HEXA_BASE);
	ft_putstr_fd("0x", fd);
	ft_putstr_fd(str, fd);
	return(ft_strlen(str) + 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:57:37 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/13 20:34:55 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"



size_t		print_int(int nb, t_flags *flags,int fd)
{
	// size_t		fill_len;

	// fill_len = ft_math_max(0, flags->width - ft_nblen((long long)nb));
	// if (flags->fill_zero && !fill_len && !nb)
	// 	return (0);
	// if (flags->fill_zero || !flags->justify_left)
	// 	fill(flags->fill_zero, fill_len, fd);
	// ft_putnbr_fd((long long)nb, fd);
	// if (!(flags->fill_zero || !flags->justify_left))
	// 	fill(flags->fill_zero, fill_len, fd);
	// return (ft_nblen((long long)nb) + fill_len);

	(void)nb;
	(void)flags;
	(void)fd;
	return(0);
}

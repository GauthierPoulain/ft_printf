/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:31:20 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/22 15:55:41 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		print_pointer(t_flags *flags, size_t adr)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_itoa(adr);
	tmp2 = ft_convert_base(tmp, DECIMAL, BASE_HEXA);
	free(tmp);
	tmp = ft_strjoin("0x", tmp2);
	free(tmp2);
	print_string(flags, tmp);
	free(tmp);
}

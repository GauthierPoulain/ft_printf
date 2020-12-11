/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:30:41 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/11 13:04:42 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

# include <stdio.h>

# define DECIMAL "0123456789"
# define HEXA_BASE "0123456789abcdef"
# define HEXA_BASE_CAPS "0123456789ABCDEF"

int		ft_printf(const char *s, ...);

#endif

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

typedef struct		s_flags
{
	int				justify_left;
	int				width;

}					t_flags;

int		ft_printf(const char *s, ...);
size_t	print_pointer_adress(void *element, int fd);
size_t	print_char(void *element, int fd);
size_t	print_string(void *element, int fd);

#endif

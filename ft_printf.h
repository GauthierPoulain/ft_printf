/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:40:22 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/19 17:59:47 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct	s_flags
{
	int			type;
	int			width;
	int			minus;
	int			zero;
	int			dot;
	int			star;
}				t_flags;

int				ft_printf(const char *s, ...);
int				flag_parse(const char *s, t_flags *flags, va_list lst);
int				istype(int c);
int				isflag(int c);
int				get_type(int c, t_flags flags, va_list lst);
t_flags			init_flags(void);
int				print_width(int size, int minus, int zero);

int				print_char(char c, t_flags flags);
int				ft_print_int(int i, t_flags flags);

#endif

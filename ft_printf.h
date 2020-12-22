/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:40:22 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/22 15:38:23 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

# include <stdio.h>

# define DECIMAL "0123456789"
# define BASE_HEXA "0123456789abcdef"
# define BASE_HEXA_CAP "0123456789ABCDEF"

typedef struct	s_flags
{
	int			print;
	int			zero;
	int			star;
	int			minus;
	int			dot;
	int			has_dot;
	int			width;
	char		type;
	int			len;
	char		*tmp;
}				t_flags;

int				ft_printf(const char *s, ...);

int				parse_flags(t_flags *flags, va_list lst, char *s);
int				parse_dot(char *s, t_flags *flags, va_list lst);
void			parse_minus(t_flags *flags);
void			parse_star(va_list lst, t_flags *flags);
void			parse_digit(char c, t_flags *flags);

void			init_flags(t_flags *flags);
void			reset_flags(t_flags *flags);

void			get_type(t_flags *flags, va_list lst);

void			print_char(t_flags *flags, char c);

void			print_string(t_flags *flags, char *str);

void			print_pointer(t_flags *flags, size_t adr);

void			print_int(t_flags *flags, int nb);
void			int_print_dot(t_flags *flags, int nb, char *tmp);

void			print_width(int width, int i, int zero, t_flags *flags);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:38:00 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/17 14:57:19 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TEST " --0*%0*.0d*0 0*%0*.10d*0-- ", -21, INT_MAX, 21, INT_MIN

int		main(void)
{
	int		buff;
	char	*pointer;

	setbuf(stdout, NULL);
	pointer = malloc(1);
	printf("real     = |");
	buff = printf(TEST);
	printf("|\n");
	printf("return = %d\n", buff);
	printf("le miens = |");
	buff = ft_printf(TEST);
	printf("|\n");
	printf("return = %d\n", buff);
	free(pointer);
	return (0);
}

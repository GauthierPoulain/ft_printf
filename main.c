/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:38:00 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/17 14:51:41 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>
#include <stdlib.h>

#define TEST "int = %-*.*d", 5, 6, 10

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

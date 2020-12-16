/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:38:00 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/15 16:04:34 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int		buff;
	char	*pointer;

	setbuf(stdout, NULL);
	pointer = malloc(1);
	printf("|");
	buff = printf("int = %d", 42);
	printf("|\n");
	printf("return = %d\n", buff);
	printf("|");
	buff = ft_printf("int = %d", 42);
	printf("|\n");
	printf("return = %d\n", buff);
	free(pointer);
	return (0);
}

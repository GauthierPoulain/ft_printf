/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:38:00 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/15 09:59:20 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>
#include <stdlib.h>

#define TEST "%d" ,55

int		main(void)
{
	int		buff;
	char	*pointer;

	setbuf(stdout, NULL);
	pointer = malloc(1);
	printf("|");
	buff = printf(TEST);
	printf("|\n");
	printf("return = %d\n", buff);
	printf("|");
	buff = ft_printf(TEST);
	printf("|\n");
	printf("return = %d\n", buff);
	free(pointer);
	return (0);
}

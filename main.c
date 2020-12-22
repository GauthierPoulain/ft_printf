/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:38:00 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/22 15:57:51 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TEST "%-10c%*c%c*",'0', 10, '1', '2'

int		main(void)
{
	int		buff;
	char	*pointer;

	setbuf(stdout, NULL);
	pointer = malloc(1);
	printf("printf :    [");
	buff = printf(TEST);
	printf("] = %d\n", buff);
	printf("ft_printf : [");
	buff = ft_printf(TEST);
	printf("] = %d\n", buff);
	free(pointer);
	return (0);
}

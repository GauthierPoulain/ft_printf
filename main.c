/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:38:00 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/14 11:53:31 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>
#include <stdlib.h>
#define TEST " %cd   %d %d " ,55

int		main(void)
{
	int		buff;
	char *pointer;
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
	// printf("%.-1d\n");
	// printf(TEST);
	// ft_printf("char = %c\n", 'a');
	// ft_printf("char = %10c\n", 'a');
	// ft_printf("char = %-10c\n", 'a');
	// ft_printf("string = %s\n", "hello world");
	// ft_printf("int = %d\n", 42);
	// ft_printf("int = %i\n", 42);
	// ft_printf("unsigned int = %u\n", 42);
	// ft_printf("percent = %%\n");
	// ft_printf("hexa = %x\n", 42);
	// ft_printf("caps hexa = %X\n", 42);
	// ft_printf("pointer = %p\n", pointer);
	// printf("pointer = %p\n", pointer);
	free(pointer);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:38:00 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/11 13:27:34 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char *pointer;

	pointer = malloc(1);
	ft_printf("char = %c\n", 'a');
	ft_printf("char = %10c\n", 'a');
	ft_printf("char = %-10c\n", 'a');



	// ft_printf("string = %s\n", "hello world");
	// ft_printf("int = %d\n", 42);
	// ft_printf("int = %i\n", 42);
	// ft_printf("unsigned int = %u\n", 42);
	// ft_printf("percent = %%\n");
	// ft_printf("hexa = %x\n", 42);
	// ft_printf("caps hexa = %X\n", 42);
	ft_printf("pointer = %p\n", pointer);
	printf("pointer = %p\n", pointer);
	return (0);
}

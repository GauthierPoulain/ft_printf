#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int		size;

	size = ft_printf("%p", NULL);
	ft_printf("$\n");
	printf("%p", NULL);
	printf("$\n");
	return (size);
}

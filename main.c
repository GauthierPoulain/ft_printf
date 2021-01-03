#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int		size;

	size = ft_printf("%.03s", NULL);
	ft_printf("$\n");
	ft_printf("%.03s", NULL);
	printf("$\n");
	return (size);
}

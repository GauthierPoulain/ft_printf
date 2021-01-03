#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int		size;

	size = ft_printf("% .*o", -3, 12345);
	ft_printf("$\n");
	printf("% .*o", -3, 12345);
	printf("$\n");
	return (size);
}

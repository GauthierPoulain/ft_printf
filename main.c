#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int		size;

	size = ft_printf("%% *.5i 42 == |% *.5i|", 4, 42);
	ft_printf("$\n");
	printf("%% *.5i 42 == |%      *.5i|", 4, 42);
	printf("$\n");
	return (size);
}

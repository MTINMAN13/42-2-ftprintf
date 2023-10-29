#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	ft_printf("%d", ft_printf("0x%p-", (void *)ULONG_MAX));
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	ft_printf(" NULL %s NULL ", NULL);

	ft_printf("\n");

	printf("%d", printf("0x%p-", (void *)ULONG_MAX));
	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf(" NULL %s NULL ", NULL);

	return (0);
}


// gcc -o my_program test.c -I ../include -L .. -lftprintf -L ../libft -lft

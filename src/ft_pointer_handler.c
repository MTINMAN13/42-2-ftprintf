// the function returns the amount of printed characters
// the function prints the pointer to passed argument

#include "ft_printf.h"
#include "libft.h"

void	ft_handle_x_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_handle_x_ptr(num / 16);
		ft_handle_x_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

// todo TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));

int	ft_print_pointer(void *hi)
{
	uintptr_t	fuckingpointer;
	int			returnvalue;

	fuckingpointer = (uintptr_t)hi;
	returnvalue = 0;
	returnvalue += ft_handle_s("0x");
	if (hi == 0)
		returnvalue += ft_handle_s("0");
	else
	{
		ft_handle_x_ptr(fuckingpointer);
		returnvalue += ft_hex_len(fuckingpointer);
	}
	return (returnvalue);
}
// int	main(void)
// {
// 	printf("%p", "what");
// 	ft_print_pointer("what");
// 	return(0);
// }
// int	main(void)
// {
// 	int x = 25;
// 	int pointertox = &x;
// 	write(1, pointertox, 10);
// 	return(0);
// }
// #include <stdio.h>
// #include <stdlib.h>
// int G = 0;   /* a global variable, stored in BSS segment */
// int	main(int argc, char **argv)
// {
// 	static int s;  /* static local variable, stored in BSS segment */
// 	int a;         /* automatic variable, stored on stack */
// 	int *p;        /* pointer variable for malloc below */
// 	/* obtain a block big enough for one int from the heap */
// 	p = malloc(sizeof(int));
// 	printf("\n%i\n", printf("%p", (void *) &G));
// 	printf("&s   = %p\n", (void *) &s);
// 	printf("&a   = %p\n", (void *) &a);
// 	printf("&p   = %p\n", (void *) &p);
// 	printf("p    = %p\n", (void *) p);
// 	printf("main = %p\n", (void *) main);
// 	free(p);
// 	return 0;
// }

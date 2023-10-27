#include <stdio.h>
#include <stdlib.h>
// #include "libft.h"
// #include "ft_printf.h"

int	ft_numlen(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		++count;
	while (n && ++count)
		n /= base;
	return (count);
}

char	handle_u(unsigned int n)
{
	unsigned int			len;
	char					*ret;
	const char				*digits;

	digits = "0123456789";
	len = ft_numlen(n, 10);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--len] = digits[n % 10];
		else
			ret[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	ft_putstr_fd(ret, 1);
	free(ret);
	return (len);
}

int	handle_id(int i)
{
	int	len;

	len = ft_numlen(i, 10);
	ft_putnbr_fd(i, 10);
	return (len);
}

// int	main(void)
// {
// 	printf("%d is the length of the
//  integer i will pass in", ft_numlen(-250, 10));
// 	handle_u(-150932094);
// 	handle_u(handle_u(-150932094));
// 	return(0);
// }

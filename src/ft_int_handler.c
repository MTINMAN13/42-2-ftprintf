#include "ft_printf.h"

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

char	ft_handle_u(unsigned int n)
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

int	ft_handle_di(int i)
{
	int	len;

	len = ft_numlen(i, 10);
	ft_putnbr_fd(i, 1);
	return (len);
}

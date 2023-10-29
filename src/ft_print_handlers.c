#include "ft_printf.h"

//  TODO TEST(10, print(" NULL %s NULL ", NULL));

int	ft_handle_s(char *string)
{
	int	returnvalue;

	returnvalue = 0;
	while (*string)
	{
		ft_putcharo(*string);
		string++;
		returnvalue++;
	}
	return (returnvalue);
}

int	ft_handle_c(int whatever)
{
	ft_putcharo(whatever);
	return (1);
}

int	ft_print_percent(void)
{
	ft_putcharo('%');
	return (1);
}

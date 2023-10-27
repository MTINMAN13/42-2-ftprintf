#include "ft_printf.h"
#include "libft.h"

int	handle_s(char *string)
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

int	handle_c(int whatever)
{
	ft_putcharo(whatever);
	return (1);
}


#include <unistd.h>
#include <stdio.h>

static int	ft_putcharo(int c)
{
	write(1, &c, 1);
	return (1);
}

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
	return(returnvalue);
}

int	handle_c(int whatever)
{
	ft_putcharo(whatever);
	return(1);
}

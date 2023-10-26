

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_putcharo(int c)
{
	write(1, &c, 1);
	return (1);
}

static int ft_printfhandler(va_list input, const char type)
{
// needs to correctly influence the printf return value
	int		chars_printed;

	chars_printed = 0;
	write(1, "[STUFF]", 7);
	return (chars_printed);
}

// if there is a fucking variadic argument, we take it and we copy it with whatever fuck you


int print(const char *to_be_printed, ... )
{
	va_list	conversions;
	int 	chars_printed;

	chars_printed = 0;
	va_start(conversions, to_be_printed);
	while (*to_be_printed)
	{
		if (*to_be_printed == '%')
		{
			to_be_printed++;
			chars_printed += ft_printfhandler(conversions, *to_be_printed);
		}
		else
			chars_printed += ft_putcharo(*to_be_printed);
		to_be_printed++;
	}
	va_end(conversions);
	return(chars_printed);
}

int main(void)
{
	print("whatsup bro%s, hello");
	return(0);
}




#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

static int	ft_putcharo(int c)
{
	write(1, &c, 1);
	return (1);
}

static int ft_printfhandler(va_list input, const char type)
{
	int		chars_printed;

	chars_printed = 0;
	if (type == 'd' || type == 'i')
		chars_printed += handle_di(va_arg(input, int));
	else if (type == 'u')
		chars_printed += handle_u(va_arg(input, unsigned int));
	else if (type == 'x' || type == 'X')
		chars_printed += handle_x(va_arg(input, unsigned int), type);
	else if (type == 'c')
		chars_printed += handle_c(va_arg(input, char *));
	else if (type == 's')
		chars_printed += handle_s(va_arg(input, char));
	else if (type == 'p')
		chars_printed += ft_print_pointer(va_arg(input, unsigned long long));
	else if (type == '%')
		chars_printed += ft_printpercent();
	return (chars_printed);
}
// if there is a fucking variadic argument, we take it and we copy it with whatever fuck you

int ft_printf(const char *to_be_printed, ... )
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

int	main(void)
{
	ft_printf("whatsup bro%s, hello");
	return(0);
}

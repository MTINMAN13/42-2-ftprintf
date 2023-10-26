

#include <stdio.h>

// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

// #include "libft.h"
int		ft_printf(const char *printable, ...)
{
	return (0);
}


	// printf("Ahoj brasku");
	// printf("%c Prints a single character.");
	// printf("%p The void * pointer argument has to be printed in hexadecimal format.");
	// printf("%d Prints a decimal (base 10) number.");
	// printf("%i Prints an integer in base 10.");
	// printf("%u Prints an unsigned decimal (base 10) number.");
	// printf("%x Prints a number in hexadecimal (base 16) lowercase format.");
	// printf("%X Prints a number in hexadecimal (base 16) uppercase format.");
	// printf("%% Prints a percent sign.");
	// printf("");
	// printf("");
	// printf("");


int	main(void)
{
	const char *printable = "ahoj";
	int i = 0;
	while (*printable)
	{
		printf("%c", *printable);
		i++;
		printable++;
	}
	printf("%u is a decimal num", "h");
	return(i);
}

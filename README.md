# 42-2-ftprintf
ehm .. ja.. mein public repo fur das .. ja... printf ... und so.. =)

----
TODO:
1) Print the Const Character
- iterate through the 'const char'
- "write" each unique character
- or
- look for special instances %c, %s, %p, %d, %i, %u, %x, %X, %%
2) Handle additional Arguments

FACTS;
- Insufficient Args throws : warning: more '%' conversions than data arguments [-Wformat-insufficient-args]
- Thats where Variadic Functions come in
- we use : va_start, va_arg, va_copy, va_end
- these go in line with the syntax (...) in : int ft_printf(const char *, ...)
- (edit: LEGACY) but we cant use va_list (author note: which is kind of cringe tbh.. but whatever right cant// do shit)
- nevermind... va_list is actually a variable, thus we an use it.. there is only the function restriction

- *printf returns an integer value*, which is the total _number of printed_ characters.
- TEST_REALM_ft_printf.c:45:32: warning: format specifies type 'int' but the argument has type 'char *' [-Wformat]
- above is for when 	printf("%d is a decimal num", "hello");   (!!see _patch note 0.2_)

- !!! we CAN essentially PASS FULL VA_LIST and we can *HANDLE* the ARGUMENTS ONE By ONE *!externally!*  !!
- (some time has passed since the above lines..) so i took this shit and fucking ran with it.. specifically i ran with it here static int ft_printfhandler(va_list input, const char type)

- !!! POINTERS HAVE THEIR OWN VARIABLE TYPE !! _(lmao, who knew?_ :)_)_
- pointer wants to be in uintptr_t

AND THATS ALL FOLKS!


_____
> - THE ORIGINAL DESCRIPTION
> You will discover variadic functions in C.
> The key to a successful ft_printf is a well-structured and extensible code.
> int		ft_printf(const char *, ...)

## notes about functions (and terms)
##### 'Ellipsis' (...)
- ... is used to denote ranges, an unspecified number of arguments, or a parent directory. (Src: Wiki)
- in C, this thing (ellipsis) is used to represent a "variable" number of "parameters" to a function.

##### va_list | variable
va_list is a new variable type responsible for handling the variadic function arguments
- va_list its used to declare the variable used to hold the arguments
- its responsible for holding the parameter past the (...) called _Ellipsis _(the three dots yes)_ in the function prototype (aka signature, or header)
- va_list	arguments;

##### (UPDATE) uintptr_t | variable
uintptr_t is an unsigned integer type that is guaranteed to be able to hold the value of a pointer.
- its in stdint.h
- #include <stdint.h>

## functions
##### va_start
va_start is used to initiate the variable
- takes in the variable which is _before_ the 'ellipsis' and then it handles arguments
- va_start(ellipsis, arguments)

##### va_arg
va_arg is responsible for *pulling* the arguments (elements) one at a time, looping
- we need to specify which data type elemnets (variable types) are gonna be used (int, char, etc..)
- va_arg(arguments, _datatype_)

##### va_copy
va_copy is used to duplicate this va_list object, allowing you to work with the copy while preserving the original va_list for future use.
- The va_copy macro copies src to dest.
- va_copy( va_list dest, va_list src );
[https://en.cppreference.com/w/c/variadic/va_copy][def souce]

##### va_end
"this is where we tell the function: okay looping stops here"
- va_end(arguments);

_________

### PATCH NOTES

###### -- 0.6. The Pointer whatever chapter thing.. how does this fucking shit work? WHAT THE FUCK
how to i even print the fucking pointer
a: we do this shit -->

#include <unistd.h>
#include <stdint.h>

int	ft_print_pointer(unsigned long long *hi)
{
	uintptr_t	fuckingpointer;

	fuckingpointer = (uintptr_t)hi;
	return(0);
}

int	main(void)
{
	ft_print_pointer("what");
	return(0);
}

in this patch we added the pointer handler thus finishing or rather fuck no not finishing, just rather entering a polishing phase
fuck
i am entering the polishing phase next

###### -- 0.3. (also known as 0.5)

replaced ft_printf_int.c with putnbr and stuff
workin on the handler (variadic argument handler)
handler implemented (static int ft_printfhandler(va_list input, const char type))

###### -- 0.2. -- Implement Logic

In this work session, we added ehm the discovery exploration notes. The insights
helped me understand the variable argument stuff.

> conversions = "cspdiuxX%";
> 	if its 0 (c) --> int (single character as per the ascii table)
>	if its 1 (s) --> char | string of characters
>	if its 2 (p) --> "prints" pointer | (format specifies 'void *')
>	if its 3 (d) or 4 (i) --> int
>	if its 5, 6, 7 (iuxX) --> unsigned int
> 		further, 6, 7 (xX) is converted to hex
>	if its 8 it prints '%'

prototype logic
int	main(void)
{
	const char *printable = "ahoj";
	int i = 0;
	while (*printable)
	{
		if (*printable == %)
			handle stuff
		else
			printf("%c", *printable);
		i++;
		printable++;
	}
	return(i);
}


###### -- 0.1. -- ^^ UwU Patch RawR | 2023

We (meaning me) have also included the Libft.h in Makefile (v1.0)

Gutten Tag, wir sind die big programatoren und das is der um printf jaja
Heute ist utery 24ichste. Das ist die struktur hier, ja:

ft_printf_project/
|-- include/
|   |-- libft.h
|
|-- libft/
|   |-- libft.a
|   |-- ft_strlen.c
|
|-- src/
|   |-- ft_printf.c
|
|-- Makefile
|-- README.md


[def]: source

#include "libft.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	//Percentage
	ft_printf("%%\n");
	//Char
	ft_printf("%s this is a test\n", "hello");
	//String
	ft_printf("%s\n", "This is a test to see if life works");
	// ft_printf("%10.10s\n", "Check width and precision when I get it working");
	//Signed Integer
	ft_printf("%d\n", INTMAX_MAX);
	ft_printf("%hd\n", INTMAX_MAX);
	ft_printf("%hhd\n", INTMAX_MAX);
	ft_printf("%ld\n", INTMAX_MAX);
	ft_printf("%lld\n", INTMAX_MAX);
	// ft_printf("%jd\n", INTMAX_MAX);
	ft_printf("%zd\n", INTMAX_MAX);
	return (0);
}

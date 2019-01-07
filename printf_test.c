#include "libft.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	//Percentage
	int a;

	a = 29;
	ft_printf("%%\n");
	//Char
	ft_printf("%s this is a test\n", "hello");
	//String
	ft_printf("%s\n", "This is a test to see if life works");
	// ft_printf("%10.10s\n", "Check width and precision when I get it working");
	//Signed Integer
	ft_printf("%d\n", __LONG_LONG_MAX__);
	ft_printf("%hd\n", __LONG_LONG_MAX__);
	ft_printf("%hhd\n", __LONG_LONG_MAX__);
	ft_printf("%ld\n", __LONG_LONG_MAX__);
	ft_printf("%lld\n", __LONG_LONG_MAX__);
	// ft_printf("%jd\n", INTMAX_MAX);
	ft_printf("%zd\n", __LONG_LONG_MAX__);
	ft_printf("%o is the octal representation of %d\n", a, a);
	ft_printf("%x is the hex representation of %d\n", a, a);
	ft_printf("%X is the hex representation of %d\n", a, a);
	ft_printf("%u is the decimal representation of %d\n", a, a);

	ft_printf("%10x\n", 20);
	ft_printf("%10.5x\n", 20);
	ft_printf("%10.5d\n", (-20));
	return (0);
}

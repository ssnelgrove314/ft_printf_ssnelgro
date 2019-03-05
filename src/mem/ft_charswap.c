#include "libft.h"

void	ft_charswap(char *a, char *b)
{
	char tmp_a;

	tmp_a = *a;
	*a = *b;
	*b = tmp_a;
}
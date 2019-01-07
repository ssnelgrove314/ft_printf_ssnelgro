#include "ft_string.h"

void	ft_strfill(char *strtofill, size_t n, char fill_char)
{
	char *str;
	
	str = strtofill;
	if (!strtofill)
		return ;
	while (n--)
	{
		*str = fill_char;
		str++;
	}
}
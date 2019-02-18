#include "ft_string.h"

void	ft_strfill(char **strtofill, size_t n, char fill_char)
{
	size_t i;
	
	i = 0;
	if (!strtofill || n < 1)
		return ;
	while (i < n)
	{
		strtofill[0][i] = fill_char;
		i++;
	}
}
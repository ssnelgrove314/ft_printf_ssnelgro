#include "libft.h"

int main(void)
{
	t_vector test;
	char *t = (char *)ft_memalloc(sizeof(char) * 37);
	ft_vector_init(&test, 37);
	ft_vector_nappend(&test, "0123456789abcdefghijklmnop", 36);
	ft_subvector_slide(&test, test.data, t, 2);
	printf("%s\n%s\n", test.data, t);
	return (0);
}
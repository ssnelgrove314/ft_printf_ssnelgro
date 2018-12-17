#include "../ft_printf.h"

int main(void)
{
	t_vector test;
	ft_vector_init(&test, 100);
	ft_vector_append(&test, "c");
	ft_vector_nappend(&test, "     ", 5);
	ft_subvector_slide(&test, test.data, test.data + 6, 1);
	printf("%s\n", test.data);
	return (0);
}
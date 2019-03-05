#include "../ft_printf.h"

void	spec_percentage(t_printf *prtf)
{
	ft_vector_nappend(prtf->output, "%", 1);
}
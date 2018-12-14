#include "../ft_printf.h"

void	spec_percentage(t_printf *prtf, va_list arg)
{
	if ((prtf->args.flags.flags) || prtf->args.width || prtf->args.precision || prtf->args.length.length)
		ft_printf_error(prtf->start_spec, INVALID_SPEC);
	ft_vector_nappend(prtf->output, "%", 1);
}
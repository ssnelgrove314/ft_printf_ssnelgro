#include "../ft_printf.h"

void	spec_char(t_printf *prtf, va_list arg)
{
	t_vector output;

	ft_vector_init(&output, prtf->args.width + 1);
	if (prtf->args.length.pf_l)
	{
		prtf->args.val.wide_char = va_arg(arg, wchar_t *);
	}
	else
	{
		prtf->args.val.signed_char = va_arg(arg, int);
	}
	handle_width(prtf);
	handle_precision(prtf);
}
#include "../ft_printf.h"

void	spec_char(t_printf *prtf, va_list arg)
{
	t_vector output;

	if (prtf->args.widthcision & PF_PRECISION_SET)
		ft_printf_error(prtf->start_spec, INVALID_SPEC);
	ft_vector_init(&output, prtf->args.width + 2);
	if (prtf->args.length & PF_L)
	{
		prtf->args.val.wide_char = va_arg(arg, wchar_t *);
		ft_vector_nappend(&output, (char *)prtf->args.val.wide_char, 2);
	}
	else
	{
		prtf->args.val.signed_char = va_arg(arg, int);
		ft_vector_nappend(&output, &prtf->args.val.signed_char, 1);
	}
	// handle_width(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}
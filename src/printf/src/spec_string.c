#include "../ft_printf.h"

void	format_str(t_printf *prtf, t_vector *output)
{
	
}

void	spec_string(t_printf *prtf, va_list arg)
{
	t_vector output;

	if (prtf->args.length & PF_L)
	{
		prtf->args.val.wide_char = va_arg(arg, wchar_t *);
		ft_vector_nappend(&output, (char *)prtf->args.val.wide_char, 2);
	}
	else
	{
		prtf->args.val.str = va_arg(arg, char *);
		ft_vector_nappend(&output, &prtf->args.val.signed_char, 1);
	}
	ft_vector_nappend(prtf->output, output.data, output.len);
	format_str(prtf, &output);
	ft_vector_free(&output);
}
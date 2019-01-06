#include "../ft_printf.h"

void	format_str(t_printf *prtf, t_vector *output)
{
	if ((size_t)prtf->args.precision < output->len)
		output->len = prtf->args.precision;
	if (prtf->args.width)
		// pad_str(prtf, output);
		return ;
}

void	spec_string(t_printf *prtf)
{
	t_vector output;

	ft_vector_init(&output, 10);
	if (prtf->args.length & PF_L)
	{
		prtf->args.val.wide_char = va_arg(prtf->args.arg, wchar_t *);
		ft_vector_nappend(&output, (char *)prtf->args.val.wide_char, 2);
	}
	else
	{
		prtf->args.val.str = va_arg(prtf->args.arg, char *);
		ft_vector_nappend(&output, prtf->args.val.str, ft_strlen(prtf->args.val.str));
	}
	ft_vector_nappend(prtf->output, output.data, output.len);
	format_str(prtf, &output);
	ft_vector_free(&output);
}
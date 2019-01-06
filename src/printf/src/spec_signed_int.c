#include "../ft_printf.h"

void	ft_pf_get_value(t_printf *prtf)
{
	if (prtf->args.length & PF_HH)
		prtf->args.val.signed_char = (signed char)va_arg(prtf->args.arg, int);
	else if (prtf->args.length & PF_H)
		prtf->args.val.signed_short = (short)va_arg(prtf->args.arg, int);
	else if (!prtf->args.length)
		prtf->args.val.signed_int = va_arg(prtf->args.arg, int);
	else if (prtf->args.length & PF_L)
		prtf->args.val.signed_long = (long)va_arg(prtf->args.arg, long int);
	else if (prtf->args.length & PF_LL)
		prtf->args.val.signed_llong = (long long)va_arg(prtf->args.arg, long long int);
	else if (prtf->args.length & PF_J)
		prtf->args.val.intmax = (intmax_t)va_arg(prtf->args.arg, intmax_t);
	else if (prtf->args.length & PF_Z)
		prtf->args.val.ssizet = (ssize_t)va_arg(prtf->args.arg, ssize_t);
}

void	spec_signed_int(t_printf *prtf)
{
	t_vector output;
	char *val;

	val = NULL;
	ft_vector_init(&output, 10);
	ft_pf_get_value(prtf);
	val = ft_imaxtoa(prtf->args.val.intmax);
	ft_vector_append(&output, val);
	ft_strdel(&val);
	// ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}
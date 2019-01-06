#include "../ft_printf.h"

void	ft_pf_get_value(t_printf *prtf)
{
	if (prtf->args.length & PF_HH)
		prtf->args.val.unsigned_char = (unsigned char)va_arg(prtf->args.arg, unsigned int);
	else if (prtf->args.length & PF_H)
		prtf->args.val.unsigned_short = (short)va_arg(prtf->args.arg, unsigned int);
	else if (!prtf->args.length)
		prtf->args.val.unsigned_int = va_arg(prtf->args.arg, unsigned int);
	else if (prtf->args.length & PF_L)
		prtf->args.val.unsigned_long = (unsigned long)va_arg(prtf->args.arg, unsigned long int);
	else if (prtf->args.length & PF_LL)
		prtf->args.val.unsigned_llong = (unsigned long long)va_arg(prtf->args.arg, unsigned long long int);
	else if (prtf->args.length & PF_J)
		prtf->args.val.uintmax = (uintmax_t)va_arg(prtf->args.arg, uintmax_t);
	else if (prtf->args.length & PF_Z)
		prtf->args.val.sizet = (size_t)va_arg(prtf->args.arg, size_t);
}

void	spec_octal(t_printf *prtf)
{
	t_vector output;
	char *val;

	val = NULL;
	ft_vector_init(&output, 10);
	ft_pf_get_value(prtf);
	val = ft_uimaxtoa_base(prtf->args.val.uintmax, "01234567");
	ft_vector_append(&output, val);
	ft_strdel(&val);
	// ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}
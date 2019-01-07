#include "../ft_printf.h"

void	ft_pf_get_value_signed(t_printf *prtf)
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

void	ft_pf_get_value_unsigned(t_printf *prtf)
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

void	ft_pf_get_values(t_printf *prtf, char sign)
{
	if (sign == PF_SIGNED)
		ft_pf_get_value_signed(prtf);
	if (sign == PF_UNSIGNED)
		ft_pf_get_value_unsigned(prtf);
}
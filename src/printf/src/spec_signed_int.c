#include "../ft_printf.h"

void	spec_signed_int(t_printf *prtf, va_list arg)
{
	if (!arg)
		prtf->args.val.signed_int = va_arg(arg, int);
}
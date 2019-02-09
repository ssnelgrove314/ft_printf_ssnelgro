#include "../ft_printf.h"

void	spec_signed_int(t_printf *prtf)
{
	t_vector output;
	char *val;

	val = NULL;
	ft_vector_init(&output, 10);
	ft_pf_get_values(prtf, PF_SIGNED);
	val = ft_imaxtoa(prtf->args.val.signed_int);
	ft_vector_append(&output, val);
	ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}
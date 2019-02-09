#include "../ft_printf.h"

void	spec_signed_int(t_printf *prtf)
{
	t_vector output;
    // char *val;

	ft_vector_init(&output, 10);
	// ft_get_float_val(prtf);
	// val = ft_ftoa(prtf->args.val.double_double);
	// ft_vector_append(&output, val);
	// ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}
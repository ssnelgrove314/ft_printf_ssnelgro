#include "../ft_printf.h"

void	handle_flags(t_printf *prtf, t_vector *output)
{
	if (prtf->args.flags & PF_PREPEND_SIGN && ft_atoi(output->data) > 0)
		ft_vector_nprepend(output, "+", 1);
	if (prtf->args.flags & PF_ALT_FORM)
		if (ft_strchr("ox", prtf->args.spec))
			ft_vector_nprepend(output, "0", 1);
	if (prtf->args.flags & PF_PREPEND_SPACE && !(prtf->args.flags & PF_PREPEND_SIGN && prtf->args.flags && ft_atoi(output->data) > 0))
		ft_vector_nprepend(output, " ", 1);
}

void	handle_precision(t_printf *prtf, t_vector *output)
{
	if (!(prtf->args.widthcision & PF_PRECISION_SET) || ft_strchr("c%", prtf->args.spec))
		return ; //possible error?
	else if (prtf->args.spec == 's')
		output->len > (size_t)prtf->args.precision ? output->len -= prtf->args.precision : 0;
	else if (ft_strchr("dioxXu", prtf->args.spec))
	{
		while (output->len < (size_t)prtf->args.precision)
			ft_vector_nprepend(output, "0", 1);
	}
}

void	handle_width(t_printf *prtf, t_vector *output)
{
	char	*padding;
	int		pad_len;
	
	pad_len = prtf->args.width - output->len;
	padding = ft_strnew(pad_len);
	ft_strfill(padding, pad_len, ' ');
	if (prtf->args.flags & PF_LEFT_JUST)
		ft_vector_nappend(output, padding, pad_len);
	else
		ft_vector_nprepend(output, padding, pad_len);
	free(padding);
}

void	ft_format_str(t_printf *prtf, t_vector *output)
{
	if (prtf->args.flags)
		handle_flags(prtf, output);
	if (prtf->args.widthcision & PF_PRECISION_SET)
		handle_precision(prtf, output);
	if (prtf->args.widthcision & PF_WIDTH_SET)
		handle_width(prtf, output);
}

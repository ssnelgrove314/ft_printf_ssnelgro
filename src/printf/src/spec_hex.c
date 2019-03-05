/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:53:02 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 18:06:42 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			spec_hex(t_printf *prtf)
{
	t_vector	output;
	char		*val;
	char		*base;

	base = NULL;
	(prtf->args.spec == 'x')
		? (base = "0123456789abcdef") :
		(base = "0123456789ABCDEF");
	val = NULL;
	ft_vector_init(&output, 10);
	ft_pf_get_values(prtf, PF_UNSIGNED);
	val = ft_uimaxtoa_base(prtf->args.val.uintmax, base);
	ft_vector_append(&output, val);
	ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}

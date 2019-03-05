/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_signed_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:53:19 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 18:07:01 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			spec_signed_int(t_printf *prtf)
{
	t_vector	output;
	char		*val;

	val = NULL;
	ft_vector_init(&output, 10);
	ft_pf_get_values(prtf, PF_SIGNED);
	if (prtf->args.length & PF_HH)
		val = ft_itoa(prtf->args.val.signed_char);
	else if (prtf->args.length & PF_H)
		val = ft_itoa(prtf->args.val.signed_short);
	else if (!prtf->args.length)
		val = ft_itoa(prtf->args.val.signed_int);
	else if (prtf->args.length & PF_L || prtf->args.length & PF_LL)
		val = ft_imaxtoa(prtf->args.val.signed_llong);
	else if (prtf->args.length & PF_J)
		val = ft_imaxtoa(prtf->args.val.intmax);
	else if (prtf->args.length & PF_Z)
		val = ft_imaxtoa(prtf->args.val.ssizet);
	ft_vector_append(&output, val);
	ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:09:06 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/01 17:11:06 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			spec_octal(t_printf *prtf)
{
	t_vector	output;
	char		*val;

	val = NULL;
	ft_vector_init(&output, 10);
	ft_pf_get_values(prtf, PF_UNSIGNED);
	val = ft_uimaxtoa_base(prtf->args.val.uintmax, "01234567");
	ft_vector_append(&output, val);
	ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}

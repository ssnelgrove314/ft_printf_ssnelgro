/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:31:21 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/01 16:32:03 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			spec_decimal(t_printf *prtf)
{
	t_vector	output;
	char		*val;

	val = NULL;
	ft_vector_init(&output, 10);
	ft_pf_get_values(prtf, PF_UNSIGNED);
	val = ft_uimaxtoa_base(prtf->args.val.uintmax, "0123456789");
	ft_vector_append(&output, val);
	ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}

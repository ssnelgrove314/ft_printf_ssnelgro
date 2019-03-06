/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:50:34 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 18:22:55 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//Only deal with left/right alightment, width and precision for strings. No flags
// void			ft_format_spec_str(t_printf *prtf, t_vector *output)
// {

// }

void			spec_string(t_printf *prtf)
{
	t_vector	output;
	size_t		length;

	length = 0;
	ft_vector_init(&output, 10);
	prtf->args.val.str = va_arg(prtf->args.arg, char *);
	if (!prtf->args.val.str)
		ft_vector_nappend(&output, "(null)", 6);
	else if (!(prtf->args.val.str[0] == '\0'))
	{
		length = ft_strlen(prtf->args.val.str);
		if (prtf->args.precision)
			ft_vector_nappend(&output, prtf->args.val.str,
			prtf->args.precision);
		else
			ft_vector_nappend(&output, prtf->args.val.str, length);
		ft_format_str(prtf, &output);
		// ft_format_spec_str(prtf, &output);
		ft_vector_nappend(prtf->output, output.data, output.len);
	}
	ft_vector_free(&output);
}

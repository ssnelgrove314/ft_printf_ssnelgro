/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:53:41 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 18:23:45 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_format_str(t_printf *prtf, t_vector *output)
{
	int		width_pad_len;
	size_t	sign_alt;
	int		precision_pad_len;
	int		num_len;
	char	pad_char;
	int		neg;
	char	*precision_pad;
	char	*width_pad;

	sign_alt = 0;
	neg = 0;
	num_len = output->len;
	if (prtf->args.flags & PF_ALT_FORM)
	{
		num_len = num_len + ((prtf->args.spec == 'o') ? 1 : 2);
		if (prtf->args.spec == 'X' || prtf->args.spec == 'x')
			ft_vector_nprepend(output, "X", 1);
		ft_vector_nprepend(output, "0", 1);
	}
	else if (output->data[0] == '-')
	{
		sign_alt = 0;
		neg = 1;
	}
	else if (prtf->args.flags & PF_PREPEND_SIGN)
	{
		sign_alt = 1;
		num_len++;
	}
	precision_pad_len =
		(num_len < prtf->args.precision) ? prtf->args.precision - num_len : 0;
	width_pad_len = prtf->args.width - sign_alt - precision_pad_len - num_len;
	precision_pad = ft_strnew(precision_pad_len);
	ft_strfill(&precision_pad, precision_pad_len, '0');
	ft_vector_nprepend(output, precision_pad, precision_pad_len);
	free(precision_pad);
	if (sign_alt == 1)
		ft_vector_nprepend(output, "+", 1);
	pad_char = (prtf->args.flags & PF_PAD_ZEROS ? '0' : ' ');
	if (width_pad_len > 0)
	{
		width_pad = ft_strnew(width_pad_len);
		ft_strfill(&width_pad, width_pad_len, ' ');
		if (prtf->args.flags & PF_LEFT_JUST)
			ft_vector_nappend(output, width_pad, width_pad_len);
		else
			ft_vector_nprepend(output, width_pad, width_pad_len);
		free(width_pad);
	}
	if (prtf->args.flags & PF_PREPEND_SPACE && width_pad_len < 0 && !neg)
		ft_vector_nprepend(output, " ", 1);
}

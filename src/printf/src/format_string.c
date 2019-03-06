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

static void		ft_format_str_pad(t_printf *prtf,
								t_vector *output, t_fmt_str *fmt)
{
	fmt->width_pad = ft_strnew(fmt->width_pad_len);
	ft_strfill(&(fmt->width_pad), fmt->width_pad_len, ' ');
	if (prtf->args.flags & PF_LEFT_JUST)
		ft_vector_nappend(output, fmt->width_pad, fmt->width_pad_len);
	else
		ft_vector_nprepend(output, fmt->width_pad, fmt->width_pad_len);
	free(fmt->width_pad);
}

static void		ft_format_str_finish(t_printf *prtf, t_vector *output,
						t_fmt_str *fmt)
{
	fmt->precision_pad_len =
		(fmt->num_len < prtf->args.precision)
		? prtf->args.precision - fmt->num_len : 0;
	fmt->width_pad_len =
	prtf->args.width - fmt->sign_alt - fmt->precision_pad_len - fmt->num_len;
	fmt->precision_pad = ft_strnew(fmt->precision_pad_len);
	ft_strfill(&(fmt->precision_pad), fmt->precision_pad_len, '0');
	ft_vector_nprepend(output, fmt->precision_pad, fmt->precision_pad_len);
	free(fmt->precision_pad);
	if (fmt->sign_alt == 1)
		ft_vector_nprepend(output, "+", 1);
	fmt->pad_char = (prtf->args.flags & PF_PAD_ZEROS ? '0' : ' ');
	if (fmt->width_pad_len > 0)
		ft_format_str_pad(prtf, output, fmt);
	if (prtf->args.flags & PF_PREPEND_SPACE
	&& !(prtf->args.flags & PF_PREPEND_SIGN)
	&& fmt->width_pad_len < 0 && !fmt->neg)
		ft_vector_nprepend(output, " ", 1);
	free(fmt);
}

void			ft_format_str(t_printf *prtf, t_vector *output)
{
	t_fmt_str	*fmt;
	//Will have to fix for negative values and padding and width
	//process 1. get number as vector, insert padding between the negitive.
	//If append sign flag, prepend + sign after padding
	//if space flag and not append sign flag and not negitive, prepend space
	fmt = (t_fmt_str *)ft_memalloc(sizeof(t_fmt_str));
	fmt->sign_alt = 0;
	fmt->neg = 0;
	fmt->num_len = output->len;
	if (prtf->args.flags & PF_ALT_FORM)
	{
		fmt->num_len = fmt->num_len
		+ ((prtf->args.spec == 'o') ? 1 : 2);
		if (prtf->args.spec == 'X' || prtf->args.spec == 'x')
			ft_vector_nprepend(output, "X", 1);
		ft_vector_nprepend(output, "0", 1);
	}
	else if (output->data[0] == '-')
	{
		fmt->sign_alt = 0;
		fmt->neg = 1;
	}
	else if (prtf->args.flags & PF_PREPEND_SIGN)
	{
		fmt->sign_alt = 1;
		fmt->num_len++;
	}
	ft_format_str_finish(prtf, output, fmt);
}

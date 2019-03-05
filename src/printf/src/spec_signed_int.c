/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_signed_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:53:09 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/01 15:53:18 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

<<<<<<< HEAD
void			spec_signed_int(t_printf *prtf)
{
	t_vector	output;
	char		*val;
=======
void	spec_signed_int(t_printf *prtf)
{
	t_vector output;
	char *val;
>>>>>>> refs/remotes/origin/master

	val = NULL;
	ft_vector_init(&output, 10);
	ft_pf_get_values(prtf, PF_SIGNED);
<<<<<<< HEAD
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
=======
	val = ft_imaxtoa(prtf->args.val.signed_int);
>>>>>>> refs/remotes/origin/master
	ft_vector_append(&output, val);
	ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
<<<<<<< HEAD
}
=======
}
>>>>>>> refs/remotes/origin/master

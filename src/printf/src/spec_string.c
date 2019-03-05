/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:48:24 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/01 15:50:23 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "../ft_printf.h"

void			spec_string(t_printf *prtf)
{
	t_vector	output;
	size_t		length;

	length = 0;
	ft_vector_init(&output, 10);
	prtf->args.val.str = va_arg(prtf->args.arg, char *);
	if (!prtf->args.val.str)
		ft_vector_nappend(&output, "(null)", 6);
	else
	{
		length = ft_strlen(prtf->args.val.str);
		if (length < (size_t)prtf->args.precision)
			ft_vector_nappend(&output,
			prtf->args.val.str, prtf->args.precision);
=======
void	spec_string(t_printf *prtf)
{
	t_vector output;
	size_t length;

	length = 0;
	ft_vector_init(&output, 10);
	// if (prtf->args.length & PF_L)
	// {
	// 	prtf->args.val.wide_char = va_arg(prtf->args.arg, wchar_t *);
	// 	ft_vector_nappend(&output, (char *)prtf->args.val.wide_char, 2);
	// }
	prtf->args.val.str = va_arg(prtf->args.arg, char *);
	if (!prtf->args.val.str)
		ft_vector_nappend(&output, "(null)", 6); //should probably make NULL_STR and NULL_STR_SIZE defines
	else
	{
		length = ft_strlen(prtf->args.val.str);
		if (length > (size_t)prtf->args.precision)
			ft_vector_nappend(&output, prtf->args.val.str, prtf->args.precision); 
>>>>>>> refs/remotes/origin/master
		else
			ft_vector_nappend(&output, prtf->args.val.str, length);
	}
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
}

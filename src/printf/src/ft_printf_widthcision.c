/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_widthcision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:55:43 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/05 12:55:45 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void				printf_get_widthcision_2(t_printf *prtf)
{
	prtf->fmt++;
	if (ft_isdigit(*prtf->fmt))
	{
		prtf->args.precision = ft_atoi(prtf->fmt);
		prtf->args.widthcision |= PF_PRECISION_SET;
		prtf->fmt += ft_numlen(prtf->args.precision);
	}
	else if (*prtf->fmt == '*')
		prtf->args.widthcision |=
			(PF_PRECISION_ASTERISK | PF_PRECISION_SET);
}

void					printf_get_widthcision(t_printf *prtf)
{
	if (prtf->fmt)
	{
		if (ft_isdigit(*prtf->fmt))
		{
			if ((prtf->args.flags & PF_PAD_ZEROS) && *(prtf->fmt + 1) == '.')
				prtf->args.width = ft_atoi(prtf->fmt);
			if (!(prtf->args.flags & PF_PAD_ZEROS))
				prtf->args.width = ft_atoi(prtf->fmt);
			prtf->args.widthcision |= PF_WIDTH_SET;
			prtf->fmt += ft_numlen(prtf->args.width);
		}
		else if (*prtf->fmt == '*')
			prtf->args.widthcision |= (PF_WIDTH_ASTERISK | PF_WIDTH_SET);
		if (CMP(*prtf->fmt, '.'))
			printf_get_widthcision_2(prtf);
		return ;
	}
}

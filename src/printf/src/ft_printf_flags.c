/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:34:39 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 20:34:41 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** This may have to be broken up later and the dispatch table
** inited in a seperate header or function.
*/

t_printf_spec		g_spec[19] =
{
	{'%', &spec_percentage},
	{'c', &spec_char},
	{'s', &spec_string},
	{'d', &spec_signed_int},
	{'i', &spec_signed_int},
	{'o', &spec_octal},
	{'x', &spec_hex},
	{'X', &spec_hex},
	{'u', &spec_decimal},
	{'f', &spec_float},
	{'F', &spec_float},
};

/*
** Description: Contains the functions needed to parse
** the format string.
** %[flags][width][.precision][length]specifier
*/

void					printf_parse_after_percent(t_printf *prtf)
{
	prtf->start_spec = prtf->fmt;
	prtf->fmt += 1;
	printf_get_flags(prtf);
	printf_get_widthcision(prtf);
	printf_get_length(prtf);
	printf_get_spec(prtf);
}

void					printf_get_flags(t_printf *prtf)
{
	char				*flags;

	flags = "-+ #0";
	while (prtf->fmt)
	{
		if (CMP(*prtf->fmt, flags[0]))
			prtf->args.flags |= PF_LEFT_JUST;
		else if (CMP(*prtf->fmt, flags[1]))
			prtf->args.flags |= PF_PREPEND_SIGN;
		else if (CMP(*prtf->fmt, flags[2]))
			prtf->args.flags |= PF_PREPEND_SPACE;
		else if (CMP(*prtf->fmt, flags[3]))
			prtf->args.flags |= PF_ALT_FORM;
		else if (CMP(*prtf->fmt, flags[4]))
		{
			if (ft_isdigit(*(prtf->fmt + 1)))
			{
				if (*(prtf->fmt + 2) == '.')
					prtf->args.width = ft_atoi(prtf->fmt + 1);
				else
					prtf->args.precision = ft_atoi(prtf->fmt + 1);
				prtf->fmt += 1;
			}
			prtf->args.flags |= PF_PAD_ZEROS;
		}
		else
			return ;
		prtf->fmt += 1;
	}
	return ;
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
		return ;
	}
}

void					printf_get_length(t_printf *prtf)
{
	if (*prtf->fmt == 'l')
	{
		if (prtf->fmt[1] == 'l')
		{
			prtf->fmt++;
			prtf->args.length |= PF_LL;
		}
		else
			prtf->args.length |= PF_L;
		prtf->fmt++;
	}
	else if (*prtf->fmt == 'h')
	{
		if (prtf->fmt[1] == 'h')
		{
			prtf->fmt++;
			prtf->args.length |= PF_HH;
		}
		else
			prtf->args.length |= PF_H;
		prtf->fmt++;
	}
	else if (*prtf->fmt == 'z')
	{
		prtf->args.length |= PF_Z;
		prtf->fmt++;
	}
}

void					printf_get_spec(t_printf *prtf)
{
	int					i;

	i = -1;
	while (++i < 11)
		if (CMP(*prtf->fmt, g_spec[i].spec))
		{
			prtf->fmt += 1;
			prtf->args.spec = g_spec[i].spec;
			g_spec[i].func(prtf);
			return ;
		}
	ft_printf_error(prtf->start_spec, INVALID_SPEC);
}

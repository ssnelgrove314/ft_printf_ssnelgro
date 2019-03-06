/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:16:20 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/05 16:39:07 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

uintmax_t		ft_pw(uintmax_t nb, uintmax_t power)
{
	uintmax_t	i;

	if (power == 0)
		return (1);
	if (power % 2 == 0)
	{
		i = ft_pw(nb, power / 2);
		return (i * i);
	}
	else
		return (nb * ft_pw(nb, power - 1));
}

void			reverse(char *str, int len)
{
	int			i;
	int			j;
	int			temp;

	i = 0;
	j = len - 1;
	temp = 0;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int				get_int_len(uintmax_t nbr)
{
	int			num;

	num = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		num++;
	}
	return (num);
}

void			ft_get_float_val(t_printf *prtf)
{
	prtf->args.val.double_double = va_arg(prtf->args.arg, double);
}

void			spec_float(t_printf *prtf)
{
	t_vector	output;
	char		*val;

	ft_vector_init(&output, 10);
	ft_get_float_val(prtf);
	if (prtf->args.precision <= 0)
		prtf->args.precision = 6;
	val = ft_ftoa(prtf, prtf->args.val.double_double);
	ft_vector_append(&output, val);
	ft_strdel(&val);
	ft_format_str(prtf, &output);
	ft_vector_nappend(prtf->output, output.data, output.len);
	ft_vector_free(&output);
	free(val);
}

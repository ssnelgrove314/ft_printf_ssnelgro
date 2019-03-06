/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_float_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:33:47 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/05 16:37:38 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			pf_ldtoa_int_base(
				t_printf *prtf, uintmax_t nbr, t_ftoa_vars *vars)
{
	char		char_case;
	int			tmp_len;
	int			len_diff;
	int			int_len_tmp;

	char_case = ('a' - 10 - (('a' - 'A') * UPPER(prtf->args.spec)));
	tmp_len = get_int_len(nbr);
	len_diff = vars->tot_len - tmp_len;
	int_len_tmp = tmp_len + ((vars->neg == 1) ? 1 : 0);
	while (int_len_tmp-- > (vars->neg == 1) ? 1 : 0)
	{
		vars->res[int_len_tmp] = (nbr % vars->base) + ((nbr % vars->base < 10)
		? '0' : char_case);
		nbr /= vars->base;
	}
	while (len_diff--)
	{
		vars->res[tmp_len++] = (nbr % vars->base) + ((nbr % vars->base < 10)
		? '0' : char_case);
	}
}

/*
** Converts a floating point number to string.
*/

static void		ft_ftoa_init(t_printf *prtf, long double n, t_ftoa_vars *vars)
{
	vars->base = 10;
	vars->res = (char *)ft_memalloc(sizeof(char) * 59);
	vars->tot_len =
		(prtf->args.precision != 0 || prtf->args.flags & PF_ALT_FORM) ? 1 : 0;
	if (n < 0)
	{
		n *= -1;
		vars->int_len++;
		vars->neg = 1;
	}
	if (n == 0)
		vars->int_len = 1;
}

static void		ft_ftoa_3(t_printf *prtf, t_ftoa_vars *vars)
{
	if (prtf->args.precision != 0 || prtf->args.flags & PF_ALT_FORM)
	{
		vars->tmp = vars->res[vars->int_len];
		vars->res[vars->int_len] = '.';
		vars->int_len++;
		vars->tot_len--;
		while (vars->tot_len > vars->int_len)
		{
			vars->res[vars->tot_len] = vars->res[vars->tot_len - 1];
			vars->tot_len--;
		}
		vars->res[vars->int_len] = vars->tmp;
	}
	if (vars->neg)
		vars->res[0] = '-';
}

static void		ft_ftoa_2(t_printf *prtf, long double n, t_ftoa_vars *vars)
{
	prtf->args.precision++;
	vars->frac =
		(DABS(n) - (uintmax_t)DABS(n))
		* ft_pw(vars->base, prtf->args.precision + vars->int_len);
	vars->frac =
		((uintmax_t)DABS(vars->frac)
		% vars->base >= (uintmax_t)(vars->base / 2))
		? (vars->frac / vars->base) + 1 : vars->frac / vars->base;
	pf_ldtoa_int_base(prtf, (uintmax_t)DABS(vars->frac), vars);
}

char			*ft_ftoa(t_printf *prtf, long double n)
{
	t_ftoa_vars	*vars;
	char		*ret;

	vars = (t_ftoa_vars *)ft_memalloc(sizeof(t_ftoa_vars));
	ft_ftoa_init(prtf, n, vars);
	while ((uintmax_t)n > 0)
	{
		vars->int_len++;
		n /= 10;
	}
	vars->tot_len += vars->int_len + prtf->args.precision;
	if (prtf->args.precision != 0)
		ft_ftoa_2(prtf, n, vars);
	ft_ftoa_3(prtf, vars);
	ret = vars->res;
	free(vars);
	return (ret);
}

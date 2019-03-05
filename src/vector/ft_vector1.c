/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:36:17 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 19:36:18 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_vector_free(t_vector *vector)
{
	if (vector->data && vector->cap > 0)
	{
		free(vector->data);
		vector->data = NULL;
	}
}

int				ft_vectorspace_init(
				t_vector *vspace[], size_t init_cap, size_t size)
{
	VAR(size_t, i, -1);
	if (!vspace || !init_cap)
		return (-1);
	if (!(vspace = ft_memalloc(sizeof(t_vector *) * size)))
		return (-1);
	while (++i < size)
		if (~ft_vector_init(vspace[i], init_cap))
			continue ;
		else
		{
			free(vspace);
			return (-1);
		}
	return (0);
}

void			ft_subvector_slide(
				t_vector *vector, char *data, char *target, size_t data_len)
{
	VAR(int, orient, target >= data ? 1 : -1);
	VAR(char *, start, ~orient ? data : data + (data_len - 1));
	VAR(char *, subt, start + (orient * data_len));
	VAR(int, shifts, ~orient ? (target - subt) : (subt - target));
	if (shifts < (int)(~orient ? data_len : data_len - 1))
		return ;
	while (shifts-- != (~orient ? 0 : -1))
	{
		ft_charswap(start, subt);
		start += orient;
		subt += orient;
	}
	ft_subvector_slide(vector, start, target, data_len);
}

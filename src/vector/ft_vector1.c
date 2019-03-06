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

void				ft_vector_ninsert(
			t_vector *vector, char *newdata, size_t new_size, size_t position)
{
	t_vector		*output;

	output = (t_vector *)ft_memalloc(sizeof(t_vector));
	ft_vector_init(output, vector->len + new_size);
	ft_vector_nappend(output, vector->data, vector->len - position);
	ft_vector_nappend(output, newdata, new_size);
	ft_vector_nappend(output, &(vector->data[position]), vector->len - position);
	ft_vector_free(vector);
	vector = output;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:07:37 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 19:35:52 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_vector_init(t_vector *vector, size_t init_cap)
{
	if (!vector || !init_cap)
		return (-1);
	vector->len = 0;
	vector->cap = init_cap;
	if ((vector->data = ft_memalloc(sizeof(char) * vector->cap)) == NULL)
		return (-1);
	return (0);
}

void			ft_vector_append(t_vector *vector, char *newdata)
{
	size_t		nd_len;

	nd_len = ft_strlen(newdata);
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, newdata, nd_len);
	vector->len += nd_len;
}

void			ft_vector_resize(t_vector *vector, size_t min)
{
	size_t		mllc_size;

	if (!(vector->data))
		ft_vector_init(vector, min);
	mllc_size = vector->cap;
	while (mllc_size < min)
		mllc_size *= 2;
	vector->data = (char *)ft_recalloc(vector->data, vector->len, mllc_size);
	vector->cap = mllc_size;
}

void			ft_vector_nappend(t_vector *vector, char *newdata, size_t n)
{
	size_t		nd_len;

	nd_len = n;
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, newdata, nd_len);
	vector->len += nd_len;
}

void			ft_vector_nprepend(t_vector *vector, char *newdata, size_t n)
{
	t_vector	*output;
	t_vector	tmp;

	output = (t_vector *)ft_memalloc(sizeof(t_vector));
	ft_vector_init(output, vector->len + n);
	ft_vector_nappend(output, newdata, n);
	ft_vector_nappend(output, vector->data, vector->len);
	tmp = *output;
	*output = *vector;
	*vector = tmp;
	ft_vector_free(output);
	free(output);
}

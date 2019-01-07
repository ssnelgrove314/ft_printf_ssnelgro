#include "libft.h"

int		ft_vectorspace_init(t_vector *vspace[], size_t init_cap, size_t size)
{
	VAR(size_t, i, -1);
	if (!vspace || !init_cap)
		return (-1);
	if(!(vspace = ft_memalloc(sizeof(t_vector *) * size)))
		return (-1);
	while(++i < size)
		if(~ft_vector_init(vspace[i], init_cap))
			continue ;
		else
		{
			free(vspace);
			return (-1);
		}
	return (0);
}

void	ft_subvector_slide(t_vector *vector, char *data, char *target, size_t data_len)
{
	VAR(int, orient, target >= data ? 1 : -1);
	VAR(char *, start, ~orient ? data : data + (data_len - 1));
	VAR(char *, subt, start + (orient * data_len));
	VAR(int, shifts, ~orient ? (target - subt) : (subt - target));
	if(shifts < (int)(~orient ? data_len : data_len - 1))
		return ;
	while (shifts-- != (~orient ? 0 : -1))
	{
		ft_charswap(start, subt);
		start += orient;
		subt += orient;
	}
	ft_subvector_slide(vector, start, target, data_len);
}

int		ft_vector_init(t_vector *vector, size_t init_cap)
{
	if (!vector || !init_cap)
		return (-1);
	vector->len = 0;
	vector->cap = init_cap;
	if ((vector->data = ft_memalloc(sizeof(char) * vector->cap)) == NULL)
		return (-1);
	return (0);
}

void	ft_vector_append(t_vector *vector, char *newdata)
{
	size_t nd_len;

	nd_len = ft_strlen(newdata);
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, newdata, nd_len);
	vector->len += nd_len;
}

void	ft_vector_resize(t_vector *vector, size_t min)
{
	size_t	mllc_size;

	if (!(vector->data))
		ft_vector_init(vector, min);
	mllc_size = vector->cap;
	while (mllc_size < min)
		mllc_size *= 2;
	vector->data = (char *)ft_recalloc(vector->data, vector->len, mllc_size);
	vector->cap = mllc_size;
}

void	ft_vector_nappend(t_vector *vector, char *newdata, size_t n)
{
	size_t nd_len;

	nd_len = n;
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, newdata, nd_len);
	vector->len += nd_len;
}

void	ft_vector_free(t_vector *vector)
{
	if (vector->data && vector->cap > 0)
	{
		free(vector->data);
		vector->data = NULL;
	}
}

void	ft_vector_nprepend(t_vector *vector, char *newdata, size_t n)
{
	t_vector *output;
	t_vector tmp;

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
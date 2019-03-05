#ifndef FT_VECTOR
#define FT_VECTOR

# include "../../libft.h"

typedef struct		s_vector
{
	size_t			len;
	size_t			cap;
	char			*data;
}					t_vector;

void				ft_subvector_slide(t_vector *vector, char *data, char *target,
					size_t data_len);
int					ft_vector_init(t_vector *vector, size_t init_cap);
void				ft_vector_append(t_vector *vector, char *newdata);
void				ft_vector_resize(t_vector *vector, size_t min);
void				ft_vector_nappend(t_vector *vector, char *newdata,
					size_t n);
void				ft_vector_free(t_vector *vector);
void				ft_vector_nprepend(t_vector *vector, char *newdata, size_t n);

#endif
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../../libft.h"

typedef struct	s_printf_flags // "-+ #0"
{
	uint8_t		left_just : 1;
	uint8_t		prepend_sign_of_sign_conversions : 1;
	uint8_t		prepend_space : 1;
	uint8_t		alt_form : 1;
	uint8_t		pad_zeros : 1;
}				t_printf_flags;

typedef struct	s_printf_length
{
	uint8_t		pf_hh : 1;
	uint8_t		pf_h : 1;
	uint8_t		pf_l : 1;
	uint8_t		pf_ll : 1;
	uint8_t		pf_z : 1;
}				t_printf_legnth;

typedef struct s_printf_args
{
	t_printf_flags	flags;
	int				width;
	int				precision;
	t_printf_legnth	length;
	char			spec;
}					t_printf_args;

typedef struct		s_printf
{
	t_vector		output;
	char			*fmt;
	t_printf_args	args;
}					t_printf;

typedef void	(*t_spec_func)(t_printf *prtf, va_list arg);

typedef struct	s_printf_spec
{
	char			spec;
	t_spec_func		func;
}				t_printf_spec;

int		ft_printf(const char *format, ...);
int		ft_vfprintf(FILE *stream, const char *format, va_list arg);
void	printf_parse_after_percent(t_printf *prtf, va_list arg);
void	printf_get_flags(t_printf *prtf, va_list arg);
void	printf_get_widthcision(t_printf *prtf, va_list arg);
void	printf_get_length(t_printf *prtf, va_list arg);
void	printf_get_spec(t_printf *prtf, va_list arg);

//Append the result to the vector
void	spec_percentage(t_printf *prtf, va_list arg);
void	spec_char(t_printf *prtf, va_list arg);
void	spec_string(t_printf *prtf, va_list arg);
void	spec_signed_int(t_printf *prtf, va_list arg);
void	spec_octal(t_printf *prtf, va_list arg);

//csdioxXufFeEaAgGnp
static t_printf_spec		g_spec[19] = {
	{'%', &spec_percentage},
	{'c', &spec_char},
	{'s', &spec_string},
	{'d', &spec_signed_int},
	{'i', &spec_signed_int},
	{'o', &spec_octal},
};

#endif
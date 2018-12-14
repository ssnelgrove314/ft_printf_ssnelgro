#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../../libft.h"

# define CMP(x,y)(x == y)

typedef union	s_printf_flags // "-+ #0"
{
	uint8_t		flags;
	uint8_t		left_just : 1;
	uint8_t		prepend_sign_of_sign_conversions : 1;
	uint8_t		prepend_space : 1;
	uint8_t		alt_form : 1;
	uint8_t		pad_zeros : 1;
}				t_printf_flags;

typedef union	s_printf_length
{
	uint8_t		length;
	uint8_t		pf_hh : 1;
	uint8_t		pf_h : 1;
	uint8_t		pf_l : 1;
	uint8_t		pf_ll : 1;
	uint8_t		pf_z : 1;
}				t_printf_legnth;

typedef union	s_printf_val
{
	void				*void_ptr;
	short int			signed_short;
	unsigned short int	unsigned_short;
	short int 			*short_ptr;

	int					signed_int;
	unsigned			unsigned_int;
	int					*int_ptr;

	long int			*long_ptr;
	long int			signed_long;
	unsigned long		unsigned_long;

	long double			double_double;
	double				signed_double;

	long long int		*llong_ptr;
	unsigned long long	unsigned_llong;
	long long int		signed_llong;

	char				signed_char;
	unsigned char		unsigned_char;
	char				*str;
	wchar_t *			wide_char;

	wint_t				wide_int;
	size_t				sz_t;
	uintptr_t			uintptr;
	ptrdiff_t			ptr_diff;
	ptrdiff_t			*diffptr;
	intmax_t			intmax;
	intmax_t			*intmax_ptr;
	uintmax_t			uintmax;
	size_t				sizet;
	ssize_t				ssizet;
	size_t				*sizet_ptr;
}						t_printf_val;

typedef struct s_printf_args
{
	t_printf_flags	flags;
	int				width;
	int				precision;
	t_printf_legnth	length;
	char			spec;
	t_printf_val	val;
}					t_printf_args;

typedef struct		s_printf
{
	t_vector		*output;
	char			*fmt;
	char			*format;
	char			*start_spec;
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

void	ft_printf_error(char *error, int error_type);
//csdioxXufFeEaAgGnp

typedef enum	s_printf_errors
{
	NULL_FMT_STRING,
	INVALID_SPEC,
	NUM_OUT_OF_RANGE,
}				e_printf_errors;
#endif
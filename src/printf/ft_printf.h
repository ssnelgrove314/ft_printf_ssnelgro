#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <wchar.h>
# include <stddef.h>

# define CMP(x,y)(x == y)

typedef union			s_printf_val
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

// typedef union	s_printf_flags // "-+ #0"
// {
// 	uint8_t		left_just : 1;
// 	uint8_t		prepend_sign_of_sign_conversions : 1;
// 	uint8_t		prepend_space : 1;
// 	uint8_t		alt_form : 1;
// 	uint8_t		pad_zeros : 1;
// }				t_printf_flags;

// typedef struct	s_printf_length
// {
// 	uint8_t		pf_hh : 1;
// 	uint8_t		pf_h : 1;
// 	uint8_t		pf_l : 1;
// 	uint8_t		pf_ll : 1;
// 	uint8_t		pf_z : 1;
// }				t_printf_legnth;

typedef enum
{
	LEFT_JUST = 1 << 0,
	PREPEND_SIGN = 1 << 1,
	PREPEND_SPACE = 1 << 2,
	ALT_FORM = 1 << 3,
	PAD_ZEROS = 1 << 4,
}e_pf_flags;

typedef enum
{
	PF_HH = 1 << 0,
	PF_H = 1 << 1,
	PF_L = 1 << 2,
	PF_LL = 1 << 3,
	PF_Z = 1 << 4,
}e_pf_length;

typedef enum
{
	PF_WIDTH_SET = 1 << 0,
	PF_PRECISION_SET = 1 << 1,
	PF_WIDTH_ASTERISK = 1 << 2,
	PF_PRECISION_ASTERISK = 1 << 3,
}e_pf_widthcision;

typedef struct s_printf_args
{
	uint8_t			flags;
	uint8_t			widthcision;
	int				width;
	int				precision;
	uint8_t			length;
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
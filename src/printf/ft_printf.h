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

int		ft_printf(const char *format, ...);
int		ft_vfprintf(FILE *stream, const char *format, va_list arg);
void	printf_parse_after_percent(t_printf *prtf, va_list arg);
void	printf_get_flags(t_printf *prtf, va_list arg);
void	printf_get_widthcision(t_printf *prtf, va_list arg);
void	printf_get_length(t_printf *prtf, va_list arg);

#endif
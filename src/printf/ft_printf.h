/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:33:10 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/01 16:59:19 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <wchar.h>
# include <stddef.h>
# include <stdarg.h>
# define CMP(x,y)(x == y)

typedef union				u_printf_val
{
	void					*void_ptr;
	short int				signed_short;
	unsigned short int		unsigned_short;
	short int				*short_ptr;
	int						signed_int;
	unsigned				unsigned_int;
	int						*int_ptr;
	long int				*long_ptr;
	long int				signed_long;
	unsigned long			unsigned_long;
	long double				double_double;
	long double				signed_double;
	long long int			*llong_ptr;
	unsigned long long		unsigned_llong;
	long long int			signed_llong;
	char					signed_char;
	unsigned char			unsigned_char;
	char					*str;
	wchar_t					*wide_char;
	size_t					sz_t;
	uintptr_t				uintptr;
	ptrdiff_t				ptr_diff;
	ptrdiff_t				*diffptr;
	intmax_t				intmax;
	intmax_t				*intmax_ptr;
	uintmax_t				uintmax;
	size_t					sizet;
	ssize_t					ssizet;
	size_t					*sizet_ptr;
}							t_printf_val;

enum
{
	PF_LEFT_JUST = 1 << 0,
	PF_PREPEND_SIGN = 1 << 1,
	PF_PREPEND_SPACE = 1 << 2,
	PF_ALT_FORM = 1 << 3,
	PF_PAD_ZEROS = 1 << 4,
}							e_pf_flags;

enum
{
	PF_HH = 1 << 0,
	PF_H = 1 << 1,
	PF_L = 1 << 2,
	PF_LL = 1 << 3,
	PF_J = 1 << 4,
	PF_Z = 1 << 5,
}							e_pf_length;

enum
{
	PF_WIDTH_SET = 1 << 0,
	PF_PRECISION_SET = 1 << 1,
	PF_WIDTH_ASTERISK = 1 << 2,
	PF_PRECISION_ASTERISK = 1 << 3,
}							e_pf_widthcision;

enum
{
	PF_SIGNED,
	PF_UNSIGNED
}							e_pf_signess;

typedef struct				s_printf_args
{
	uint8_t					flags;
	uint8_t					widthcision;
	int						width;
	int						precision;
	uint8_t					length;
	char					spec;
	va_list					arg;
	t_printf_val			val;
	int						neg;
}							t_printf_args;

typedef struct				s_printf
{
	t_vector				*output;
	char					*fmt;
	char					*format;
	char					*start_spec;
	t_printf_args			args;
}							t_printf;

typedef void				(*t_spec_func)(t_printf *prtf);

typedef struct				s_printf_spec
{
	char					spec;
	t_spec_func				func;
}							t_printf_spec;

int							ft_printf(const char *format, ...);
int							ft_vprintf(const char *format, va_list arg);

void						printf_parse_after_percent(t_printf *prtf);
void						printf_get_flags(t_printf *prtf);
void						printf_get_widthcision(t_printf *prtf);
void						printf_get_length(t_printf *prtf);
void						printf_get_spec(t_printf *prtf);
void						ft_pf_get_values(t_printf *prtf, char sign);
void						spec_percentage(t_printf *prtf);
void						spec_char(t_printf *prtf);
void						spec_string(t_printf *prtf);
void						spec_signed_int(t_printf *prtf);
void						spec_octal(t_printf *prtf);
void						spec_hex(t_printf *prtf);
void						spec_decimal(t_printf *prtf);
void						spec_float(t_printf *prtf);
void						ft_format_str(t_printf *prtf, t_vector *output);
void						ft_printf_error(char *error, int error_type);

enum
{
	NULL_FMT_STRING,
	INVALID_SPEC,
	NUM_OUT_OF_RANGE,
}							e_printf_errors;

#endif

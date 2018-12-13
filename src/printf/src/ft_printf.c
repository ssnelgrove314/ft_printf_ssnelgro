#include "../ft_printf.h"
# define CMP(x,y)(x == y)

int					ft_printf(const char *format, ...)
{
	va_list		args;
 	int			ret;

	va_start(args, format);
	ret = ft_vfprintf(stdout, format, args);
	va_end(args);
	return (ret);
}

int		ft_vprintf(FILE *stream, const char *format, va_list arg)
{
	t_printf	prtf;
	char		*tmp;
	int			fd;

	//This shit needs some error checking :P
	prtf.fmt = (char *)format;
	ft_vector_init(&(prtf.output), ft_strlen(format));
	while ((tmp = ft_strchr(prtf.fmt, '%')) != NULL)
	{
		ft_vector_nappend(&(prtf.output), prtf.fmt, (tmp - prtf.fmt));
		prtf.fmt = tmp;
		printf_parse_after_percent(&prtf, arg);
	}
	ft_vector_append(&(prtf.output), prtf.fmt);
	write(stream->_fileno, &(prtf.output), prtf.output.len);
	return (prtf.output.len);
}

void	printf_parse_after_percent(t_printf *prtf, va_list arg)
{
	//%[flags][width][.precision][length]specifier
	printf_get_flags(prtf, arg);
	printf_get_widthcision(prtf, arg);
	printf_get_length(prtf, arg);
	printf_get_spec(prtf, arg);
	
}

void	printf_get_flags(t_printf *prtf, va_list arg)
{
	char	*flags;
	char	*tmp;
	char	fc;

	flags = "-+ #0";
	while (++prtf->fmt != '\0')
	{
		if (!(tmp = ft_strchr(flags, *prtf->fmt)))
			return ;
		if (CMP(*tmp, flags[0]))
			prtf->args.flags.left_just++;
		if (CMP(*tmp, flags[1]))
			prtf->args.flags.prepend_sign_of_sign_conversions++;
		if (CMP(*tmp, flags[2]))
			prtf->args.flags.prepend_space++;
		if (CMP(*tmp, flags[3]))
			prtf->args.flags.alt_form++;
		if (CMP(*tmp, flags[4]))
			prtf->args.flags.pad_zeros++;
	}
	//parse error
}

void printf_get_widthcision(t_printf *prtf, va_list arg)
{
	while (++prtf->fmt != '\0')
	{
		if (ft_isdigit(*prtf->fmt))
			prtf->args.width = ft_atoi(prtf->fmt);
		if (CMP(*prtf->fmt, '.'))
		{
			prtf->fmt++;
			if (ft_isdigit(*prtf->fmt))
				prtf->args.precision = ft_atoi(prtf->fmt);
			return ;
		}
	}
	//parse error
}

void printf_get_length(t_printf *prtf, va_list arg)
{
	while (++prtf->fmt != '\0')
	{
		if (*prtf->fmt == 'l')
		{
			if (prtf->fmt[1] == 'l')
			{
				prtf->fmt++;
				prtf->args.length.pf_ll++;
			}
			else
				prtf->args.length.pf_l++;
		}
		else if (*prtf->fmt == 'h')
		{
			if (prtf->fmt[1] == 'h')
			{
				prtf->fmt++;
				prtf->args.length.pf_hh++;
			}
			else
				prtf->args.length.pf_h++;
		}
		else if (*prtf->fmt == 'z')
			prtf->args.length.pf_z++;
		else
			return ;
	}

}

void printf_get_spec(t_printf *prtf, va_list arg)
{

}
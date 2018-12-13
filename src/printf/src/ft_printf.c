#include "../ft_printf.h"


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

	prtf.fmt = (char *)format;
	ft_vector_init(&(prtf.output), ft_strlen(format));
	while ((tmp = ft_strchr(prtf.fmt, '%')) != NULL)
	{
		ft_vector_nappend(&(prtf.output), prtf.fmt, (tmp - prtf.fmt));
		prtf.fmt = tmp + 1;
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

void printf_get_flags(t_printf *prtf, va_list arg)
{

}

void printf_get_widthcision(t_printf *prtf, va_list arg)
{

}

void printf_get_length(t_printf *prtf, va_list arg)
{

}

void printf_get_spec(t_printf *prtf, va_list arg)
{

}
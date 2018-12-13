#include "../ft_printf.h"
# define CMP(x,y)(x == y)

/*
** Function: ft_printf
** Return: the number of characters printed and returned
** by ft_vfprintf
** Params: A format string, full specifications can be found
** online. (...) is for variadic arguments.
** Description: A function that prints based off a formated string
** and can take a variadic number of arguments.
*/

int					ft_printf(const char *format, ...)
{
	va_list		args;
 	int			ret;

	va_start(args, format);
	ret = ft_vfprintf(stdout, format, args);
	va_end(args);
	return (ret);
}

/*
** Function: ft_vprintf
** Return: number of characters printed
** Params: a FILE stream to write to, a format string to
** format the writing and the va_list containing all of the args.
** Description: This is where the meat and potatoes of my
** printf are kept. We search for '%' and then send it to
** printf_parse_after_percent, which adds the parsed result to the
** output vector until there are no more '%' to parse.
*/

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

/*
** Description: Contains the functions needed to parse
** the format string.
*/

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
	//this isn't right;
	while (++prtf->fmt != '\0')
	{
		if (ft_isdigit(*prtf->fmt))
		{
			prtf->args.width = ft_atoi(prtf->fmt);
			prtf->fmt += ft_numlen(prtf->args.width);
		}
		if (CMP(*prtf->fmt, '.'))
		{
			prtf->fmt++;
			if (ft_isdigit(*prtf->fmt))
			{/
				prtf->args.precision = ft_atoi(prtf->fmt);
				prtf->fmt += ft_numlen(prtf->args.width);
			}
			//error
		}
		return ;
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
				prtf->args.length.pf_ll += 1;
			}
			else
				prtf->args.length.pf_l += 1;
		}
		else if (*prtf->fmt == 'h')
		{
			if (prtf->fmt[1] == 'h')
			{
				prtf->fmt++;
				prtf->args.length.pf_hh += 1;
			}
			else
				prtf->args.length.pf_h += 1;
		}
		else if (*prtf->fmt == 'z')
			prtf->args.length.pf_z += 1;
		else
			return ;
	}
}

/*
** This may have to be broken up later and the dispatch table
** inited in a seperate header or function.
*/

void printf_get_spec(t_printf *prtf, va_list arg)
{
	int i;

	i = -1;
	t_printf_spec		g_spec[19] =
	{
		{'%', &spec_percentage},
		{'c', &spec_char},
		{'s', &spec_string},
		{'d', &spec_signed_int},
		{'i', &spec_signed_int},
		{'o', &spec_octal},
	};
	while (++i < 6)
		if (CMP(*prtf->fmt, g_spec[i].spec))
		{
			g_spec[i].func(prtf, arg);
			return ;
		}
	//parse error
}
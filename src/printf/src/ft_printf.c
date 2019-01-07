#include "../ft_printf.h"

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
	va_list		arg;
 	int			ret;

	va_start(arg, format);
	ret = ft_vprintf(format, arg);
	va_end(arg);
	return (ret);
}

void	printf_clean_up(t_printf *prtf)
{
	prtf->args.val.intmax = 0;
	prtf->args.flags = 0;
	prtf->args.widthcision = 0;
	prtf->args.width = 0;
	prtf->args.precision = 0;
	prtf->args.length = 0;
	prtf->args.spec = 0;
}

void	printf_init(const char *format, t_printf *prtf)
{
	prtf->format = ft_strdup(format);
	prtf->fmt = prtf->format;
	prtf->output = (t_vector *)ft_memalloc(sizeof(t_vector));
	ft_vector_init(prtf->output, ft_strlen(format));
	printf_clean_up(prtf);
}

void	ft_prtf_free(t_printf *prtf)
{
	free(prtf->format);
	ft_vector_free(prtf->output);
	free(prtf->output);
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

int		ft_vprintf(const char *format, va_list arg)
{
	t_printf	prtf;
	char		*tmp;
	int			ret;

	tmp = NULL;
	va_copy(prtf.args.arg, arg);
	printf_init(format, &prtf);
	while ((tmp = ft_strchr(prtf.fmt, '%')) != NULL)
	{
		ft_vector_nappend(prtf.output, prtf.fmt, (tmp - prtf.fmt));
		prtf.fmt = tmp;
		printf_parse_after_percent(&prtf);
		printf_clean_up(&prtf);
	}
	ft_vector_append(prtf.output, prtf.fmt);
	write(1, prtf.output->data, prtf.output->len);
	ret = prtf.output->len;
	va_end(arg);
	va_end(prtf.args.arg);
	ft_prtf_free(&prtf);
	return (ret);
}

/*
** Description: Contains the functions needed to parse
** the format string.
** %[flags][width][.precision][length]specifier
*/

void	printf_parse_after_percent(t_printf *prtf)
{
	prtf->start_spec = prtf->fmt;
	prtf->fmt += 1;
	printf_get_flags(prtf);
	printf_get_widthcision(prtf);
	printf_get_length(prtf);
	printf_get_spec(prtf);
}

void	printf_get_flags(t_printf *prtf)
{
	char	*flags;

	flags = "-+ #0";
	while (prtf->fmt)
	{
		if (CMP(*prtf->fmt, flags[0]))
			prtf->args.flags |= PF_LEFT_JUST;
		else if (CMP(*prtf->fmt, flags[1]))
			prtf->args.flags |= PF_PREPEND_SIGN;
		else if (CMP(*prtf->fmt, flags[2]))
			prtf->args.flags |= PF_PREPEND_SIGN;
		else if (CMP(*prtf->fmt, flags[3]))
			prtf->args.flags |= PF_ALT_FORM;
		else if (CMP(*prtf->fmt, flags[4]))
			prtf->args.flags |= PF_PAD_ZEROS;
		else
			return ;
		prtf->fmt += 1;
	}
	return ;
}

void printf_get_widthcision(t_printf *prtf)
{
	if (prtf->fmt)
	{
		if (ft_isdigit(*prtf->fmt))
		{
			prtf->args.width = ft_atoi(prtf->fmt);
			prtf->args.widthcision |= PF_WIDTH_SET;
			prtf->fmt += ft_numlen(prtf->args.width);
		}
		else if (*prtf->fmt == '*')
			prtf->args.widthcision |= (PF_WIDTH_ASTERISK | PF_WIDTH_SET);
		if (CMP(*prtf->fmt, '.'))
		{
			prtf->fmt++;
			if (ft_isdigit(*prtf->fmt))
			{
				prtf->args.precision = ft_atoi(prtf->fmt);
				prtf->args.widthcision |= PF_PRECISION_SET;
				prtf->fmt += ft_numlen(prtf->args.precision);
			}
			else if (*prtf->fmt == '*')
				prtf->args.widthcision |= (PF_PRECISION_ASTERISK | PF_PRECISION_SET);
		}
		return ;
	}
}

void printf_get_length(t_printf *prtf)
{
	if (*prtf->fmt == 'l')
	{
		if (prtf->fmt[1] == 'l')
		{
			prtf->fmt++;
			prtf->args.length |= PF_LL;
		}
		else
			prtf->args.length |= PF_L;
		prtf->fmt++;
	}
	else if (*prtf->fmt == 'h')
	{
		if (prtf->fmt[1] == 'h')
		{
			prtf->fmt++;
			prtf->args.length |= PF_HH;
		}
		else
			prtf->args.length |= PF_H;
		prtf->fmt++;
	}
	else if (*prtf->fmt == 'z')
	{
		prtf->args.length |= PF_Z;
		prtf->fmt++;
	}
}

/*
** This may have to be broken up later and the dispatch table
** inited in a seperate header or function.
*/

void printf_get_spec(t_printf *prtf)
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
		{'x', &spec_hex},
		{'X', &spec_hex},
		{'u', &spec_decimal},
	};
	while (++i < 9)
		if (CMP(*prtf->fmt, g_spec[i].spec))
		{
			prtf->fmt += 1;
			prtf->args.spec = g_spec[i].spec;
			g_spec[i].func(prtf);
			return ;
		}
	ft_printf_error(prtf->start_spec, INVALID_SPEC);
}
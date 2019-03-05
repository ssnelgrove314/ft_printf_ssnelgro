/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:14:17 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 20:16:49 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int						ft_printf(const char *format, ...)
{
	va_list				arg;
	int					ret;

	va_start(arg, format);
	ret = ft_vprintf(format, arg);
	va_end(arg);
	return (ret);
}

void					printf_clean_up(t_printf *prtf)
{
	prtf->args.val.intmax = 0;
	prtf->args.flags = 0;
	prtf->args.widthcision = 0;
	prtf->args.width = 0;
	prtf->args.precision = 0;
	prtf->args.length = 0;
	prtf->args.spec = 0;
}

void					printf_init(const char *format, t_printf *prtf)
{
	prtf->format = ft_strdup(format);
	prtf->fmt = prtf->format;
	prtf->output = (t_vector *)ft_memalloc(sizeof(t_vector));
	ft_vector_init(prtf->output, ft_strlen(format));
	printf_clean_up(prtf);
}

void					ft_prtf_free(t_printf *prtf)
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

int						ft_vprintf(const char *format, va_list arg)
{
	t_printf			prtf;
	char				*tmp;
	int					ret;

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

#include "ft_printf.h"

int valid_spec(char c)
{
    const char *valid;
    
    valid = "diDsSpxXoObncCuU%";
    while (valid)
    {
        if (c == *valid)
            return (1);
        valid++;
    }
    return (0);
}

int valid_flag(char c)
{
    const char *valid;
    
    valid = "+- 0#";
    while (valid)
    {
        if (c == *valid)
            return (1);
        valid++;
    }
    return ('\0');
}

int pf_parse_format_str(printf_struct_t *local)
{
	size_t i;

	if (ft_vector_init(&(local->output), ft_strlen(local->format + 60)) == -1)
		return (-1);
	while ((local->format = get_next_arg(local))
	{
		i = -1;
		while (++i < MAX_FORMATS)
			if (printf_dispatch[i].flag == local->conv_spec)
			{
				printf_dispatch[i].printf_func()
				local->format++;
			}
		if (!valid_arg(local->conv_spec) && local->width)
	}
https://github.com/eliasgoodale/libft/blob/cb386b4e3faeb0d9429e0b4eccbd77241e93d66b/ft_printf/parse_args.c
}
char *get_next_arg(printf_struct_t *local)
{
    while (local->format + local->fmt_c)
    {
        if ((*(local->format)) + local->fmt_c == '%')
        {
			ft_vector_nappend(local->output, local->format, local->fmt_c);
			local->fmt_c++;
			while (valid_flag((*(local->format)) + local->fmt_c))
				get_flags(local);
			get_width(local);
			get_preci(local);
			get_lngth(local);
			local->conv_spec = (*(local->format)) + local->fmt_c;
			return (local->format + local->fmt_c);
        }
    }
	ft_vector_nappend(local->output, local->format, local->fmt_c);
	return (NULL);
}



int ft_printf_parser(char **ret, const char *format, va_list ap)
{
    printf_struct_t local;

    local.format = (char *)format;
    va_copy(local.ap, ap);
    local.output = ft_strnew(0);
    pf_parse_format_str(&local);
    *ret = ft_strdup(local.output);
    return (ft_strlen(*ret));
}

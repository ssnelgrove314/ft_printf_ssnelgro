#include "ft_printf.h"

void pf_parse_format_str(printf_struct_t *local)
{
    char *tmp;

    tmp = local->format;
    while (tmp)
    {
        tmp = ft_strchr(tmp, '%');
        tmp++;
        tmp = pf_parse_after_perc(local, tmp);

    }

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




printf_struct_t **printf_spec_fmt_list(printf_io_t *pfdata)
{
    char *fmt;
    printf_struct_t *tmp;

    fmt = pfdata->format++;
    while ((fmt = ft_strchr(fmt, '%')) != NULL)
    {
        if (!pfdata->info)
            pfdata->info = (printf_struct_t **)ft_memalloc(sizeof(printf_struct_t) * pf_count_specifiers(fmt));
        while (pf_valid_char(fmt))
        {
            if ()

            fmt++;
        }
        tmp = (printf_struct_t *)ft_memalloc(sizeof(printf_struct_t));
        if (*fmt == specifier)
            tmp->conv_spec = *fmt;
        if(*fmt == length)
        if(ft_isdigit(*fmt))
        if(*fmt == '.')
        if (fmt_isdigit(*fmt))
        if (fmt_flags)
    }
}
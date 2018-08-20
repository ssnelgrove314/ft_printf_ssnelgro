#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
    int len;
    char *ret;

    if (!format || !*format)
        return (-1);
    va_start(ap, format);
    len = ft_vasprintf(&ret, format, ap);
    write(1, ret, len);
    free(ret);
    va_end(ap);
    return (len);
}

int ft_vasprintf(char **ret, const char *format, va_list ap)
{
    if (*format == '\0')
        *ret = ft_strnew(0);
    if (!ret)
        return (0);
    if (ft_strchr(format, '%') == NULL)
    {
        if ((*ret = ft_strdup(format)) == NULL)
            return (-1);
        return (ft_strlen(*ret));
    }
    return (ft_printf_parser(ret, format, ap));
}

// int ft_vprintf(const char *format, va_list ap, ...)
// {
//
// }
//
// int ft_sprintf(char *buffer, const char format, ...)
// {
//
// }
//
// int ft_snprintf(char *buffer, size_t bufsz, const char format, ...)
// {
//
// }
//
// int ft_dprintf(int fd, const char format, ...)
// {
//
// }
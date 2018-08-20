#include "ft_printf.h"

int ft_printf_parser(char **ret, const char *format, va_list ap)
{
    printf_io_t *pfdata;

    pfdata = init_printf_io(ret, format, ap);
    

}

printf_io_t *init_printf_io(char **ret, const char *format, va_list ap)
{
    printf_io_t *pfdata;

    if((pfdata = (printf_io_t *)malloc(sizeof(printf_io_t *))) == NULL)
        return (NULL);
    *ret = pfdata->ret;
    pfdata->format = ft_strdup(format);
    va_copy(ap, pfdata->ap);
    pfdata->info = printf_spec_fmt_list(pfdata);

    return (pfdata);
}
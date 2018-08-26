#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define MAX_FORMATS 11
typedef struct      printf_struct_s
{
    char *format;
    size_t fmt_c;
    va_list ap;
    char conv_spec;
    int precision;
    char length;
    int width;
    char *flags;
    char *func_ret;
	t_vector *output;
}                   printf_struct_t;

typedef printf_struct_t *ft_printf_func(printf_struct_t *iprints);

typedef struct ft_printf_dispatch_s
{
    char *full_name;
    char flag;
    ft_printf_func *printf_func;
}              ft_printf_dispatch_t;

printf_struct_t *printf_handle_percent(printf_struct_t *iprints);
printf_struct_t *printf_handle_char(printf_struct_t *iprints);
printf_struct_t *printf_handle_str(printf_struct_t *iprints);
printf_struct_t *printf_handle_sint(printf_struct_t *iprints);
printf_struct_t *printf_handle_uint(printf_struct_t *iprints);
printf_struct_t *printf_handle_hex(printf_struct_t *iprints);
printf_struct_t *printf_handle_decimal(printf_struct_t *iprints);
printf_struct_t *printf_handle_float(printf_struct_t *iprints);
printf_struct_t *printf_handle_binary(printf_struct_t *iprints);

const ft_printf_dispatch_t printf_dispatch[] =
{
    {"printf_handle_percent", '%', &printf_handle_percent},
    {"printf_handle_char", 'c', &printf_handle_char},
    {"printf_handle_str", 's', &printf_handle_str},
    {"printf_handle_sint", 'd', &printf_handle_sint},
    {"printf_handle_sint", 'i', &printf_handle_sint},
    {"printf_handle_uint", 'o', &printf_handle_uint},
    {"printf_handle_hex", 'x', &printf_handle_hex},
    {"printf_handle_hex", 'X', &printf_handle_hex},
    {"printf_handle_decimal", 'u', &printf_handle_decimal},
    {"printf_handle_float", 'f', &printf_handle_float},
    {"printf_handle_binary", 'b', &printf_handle_binary}
};

int ft_printf(const char *format, ...);
int ft_vasprintf(char **ret, const char *format, va_list ap);
int ft_printf_parser(char **ret, const char *format, va_list ap);

// int ft_vprintf(const char *format, va_list ap, ...);
// int ft_sprintf(char *buffer, const char format, ...);
// int ft_snprintf(char *buffer, size_t bufsz, const char format, ...);
// int ft_dprintf(int fd, const char *format, ...);




#endif
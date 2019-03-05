#ifndef FT_STDLIB_H
#define FT_STDLIB_H

#include "../../libft.h"
char				*ft_imaxtoa(intmax_t value);
char 				*ft_uimaxtoa_base(uintmax_t value, const char *base);
char				*ft_itoa(int n);
int					ft_atoi(char *str);

#endif
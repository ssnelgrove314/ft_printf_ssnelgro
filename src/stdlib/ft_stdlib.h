/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:41:43 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 19:46:19 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include "../../libft.h"

char				*ft_imaxtoa(intmax_t value);
char				*ft_uimaxtoa_base(uintmax_t value, const char *base);
char				*ft_itoa(int n);
int					ft_atoi(char *str);

#endif

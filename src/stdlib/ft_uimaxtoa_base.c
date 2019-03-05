/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:01:29 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 19:01:41 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uimaxtoa_base(uintmax_t value, const char *base)
{
	uintmax_t	i;
	size_t		size;
	char		*ret;
	size_t		base_size;

	base_size = ft_strlen(base);
	i = value;
	size = 1;
	while ((i /= base_size))
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = value;
	ret[--size] = base[i % base_size];
	while ((i /= base_size))
		ret[--size] = base[i % base_size];
	return (ret);
}

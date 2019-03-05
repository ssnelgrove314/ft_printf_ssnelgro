/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:16:24 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 19:18:16 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void		ft_strfill(char **strtofill, size_t n, char fill_char)
{
	size_t	i;

	i = 0;
	if (!strtofill || n < 1)
		return ;
	while (i < n)
	{
		strtofill[0][i] = fill_char;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_percentage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:23:53 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 18:23:54 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	spec_percentage(t_printf *prtf)
{
	ft_vector_nappend(prtf->output, "%", 1);
}

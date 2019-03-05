/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:03:49 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/01 16:08:32 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_printf_error(char *error, int error_type)
{
	char	*errormsg;

	errormsg = NULL;
	if (CMP(NULL_FMT_STRING, error_type))
		errormsg = "Invalid format string\n";
	else if (CMP(INVALID_SPEC, error_type))
		errormsg = ft_strjoin(error, ": invalid conversion specification\n");
	else if (CMP(NUM_OUT_OF_RANGE, error_type))
		errormsg = ft_strjoin(error, ": Number out of range.\n");
	write(1, errormsg, ft_strlen(errormsg));
	exit(1);
}

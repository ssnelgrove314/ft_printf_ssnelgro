/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:45:17 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/01 15:46:48 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstappend(t_list **begin_list,
			void const *content, size_t contentsize)
{
	t_list	*list;

	list = *begin_list;
	if (!list)
	{
		*begin_list = ft_lstnew(content, contentsize);
	}
	else
	{
		while ((list)->next)
			list = list->next;
		list = ft_lstnew(content, contentsize);
	}
}

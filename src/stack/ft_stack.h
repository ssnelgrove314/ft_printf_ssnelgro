/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:56:23 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 19:39:42 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "../../libft.h"

typedef struct	s_stack
{
	void		**contents;
	int			top;
	int			max;
}				t_stack;

void			stack_init(t_stack *stack, int max_size);
int				stack_empty(t_stack *stack);
int				stack_full(t_stack *stack);
void			stack_push(t_stack *stack, void *elem);
void			*stack_pop(t_stack *stack);

#endif

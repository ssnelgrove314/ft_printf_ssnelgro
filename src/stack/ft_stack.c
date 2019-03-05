/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:39:49 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 19:39:50 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void		stack_init(t_stack *stack, int max_size)
{
	void	*new_content;

	new_content = (void **)ft_memalloc(sizeof(void *) * max_size);
	if (new_content == NULL)
		exit(1);
	stack->contents = new_content;
	stack->max = max_size;
	stack->top = -1;
}

int			stack_empty(t_stack *stack)
{
	return (stack->top < 0);
}

int			stack_full(t_stack *stack)
{
	return (stack->top >= stack->max - 1);
}

void		stack_push(t_stack *stack, void *elem)
{
	if (stack_full(stack))
		exit(1);
	stack->contents[++stack->top] = elem;
}

void		*stack_pop(t_stack *stack)
{
	if (stack_empty(stack))
		exit(1);
	return (stack->contents[stack->top--]);
}

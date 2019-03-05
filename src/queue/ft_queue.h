/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:53:49 by ssnelgro          #+#    #+#             */
/*   Updated: 2019/03/04 18:54:11 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include "../../libft.h"

# define QUEUE_CAPACITY 1024

typedef struct	s_queue
{
	void		*data[QUEUE_CAPACITY];
	size_t		head;
	size_t		tail;
	size_t		size;
}				t_queue;

void			init_queue(t_queue *q);
void			enqueue(t_queue *q, void *item);
void			*dequeue(t_queue *q);
int				empty_queue(t_queue *q);
int				full_queue(t_queue *q);

#endif

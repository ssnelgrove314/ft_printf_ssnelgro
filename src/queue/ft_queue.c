#include "ft_queue.h"

void			init_queue(t_queue *q)
{
	if (!q)
	{
		//queue_error("Null Queue");
		return ;
	}
	q->head = 0;
	q->tail = -1;
	q->size = 0;
}

void			enqueue(t_queue *q, void *item)
{
	if (!q)
	{
		//queue_error("Null Queue");
		return ;
	}
	if (full_queue(q))
	{
		//queue_error("Queue is full\n");
		return ;
	}
	(q->tail)++;
	(q->tail) %= QUEUE_CAPACITY;
	(q->data)[q->tail] = item;
	(q->size)++;
}

void			*dequeue(t_queue *q)
{
	void		*item;

	item = NULL;
	if (!q)
	{
		//queue_error("Null Queue");
		return (item);
	}
	if(empty_queue(q))
	{
		//queue_error("Queue is empty\n");
		return (item);
	}
	item = (q->data)[q->head];
	(q->head)++;
	(q->head) %= QUEUE_CAPACITY;
	(q->size)--;
	return (item);
}

int				empty_queue(t_queue *q)
{
	if (!q)
	{
		//queue_error("Null Queue");
		return (-1);
	}
	return (q->size == 0);
}

int				full_queue(t_queue *q)
{
	if (!q)
	{
		//queue_error("Null Queue");
		return (-1);
	}
	return (q->size == QUEUE_CAPACITY);
}
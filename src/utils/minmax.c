/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:54:13 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/05 18:45:32 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <limits.h>

size_t	get_min_pos(t_deque *d)
{
	t_deque_node	*cur;
	size_t			pos;
	int				min;

	cur = d->head;
	pos = 0;
	min = INT_MAX;
	while (cur != d->head->prev)
	{
		if (cur->data < min)
			min = cur->data;
		cur = cur->next;
	}
	if (cur->data < min)
		min = cur->data;
	cur = d->head;
	while (cur->data != min)
	{
		cur = cur->next;
		pos++;
	}
	return (pos);
}

size_t	get_max_pos(t_deque *d)
{
	t_deque_node	*cur;
	size_t			pos;
	int				max;

	cur = d->head;
	pos = 0;
	max = INT_MIN;
	while (cur != d->head->prev)
	{
		if (cur->data > max)
			max = cur->data;
		cur = cur->next;
	}
	if (cur->data > max)
		max = cur->data;
	cur = d->head;
	while (cur->data != max)
	{
		cur = cur->next;
		pos++;
	}
	return (pos);
}

void	move_min_on_top(t_deque *d, char *op)
{
	size_t	i;
	size_t	min_pos;

	i = 0;
	min_pos = get_min_pos(d);
	while (i++ < min_pos)
		do_rotate(d, true, op);
}

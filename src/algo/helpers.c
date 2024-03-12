/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:56:45 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/12 20:46:36 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

#include <stdbool.h>
#include <limits.h>

#include "../../include/operations.h"

t_deque_node	*get_closest_node(t_deque *trgt, t_deque_node *node)
{
	int				diff;
	int				min_diff;
	t_deque_node	*closest;
	t_deque_node	*cur;

	cur = trgt->head;
	min_diff = INT_MAX;
	while (cur != trgt->head->prev)
	{
		diff = ft_abs(node->data - cur->data);
		if (diff < min_diff)
		{
			min_diff = diff;
			closest = cur;
		}
		cur = cur->next;
	}
	diff = ft_abs(node->data - cur->data);
	if (diff < min_diff)
	{
		min_diff = diff;
		closest = cur;
	}
	return (closest);
}

void	shift_a(t_deque *a)
{
	if (get_min_pos(a) < a->size)
	{
		while (get_min_pos(a) > 0)
			do_reverse_rotate(a, true, RRA);
	}
	else
	{
		while (get_min_pos(a) > 0)
			do_rotate(a, true, RA);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:56:45 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/08 17:13:07 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdbool.h>
#include <limits.h>

#include "libft.h"
#include "operations.h"

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

void	bring_node_top(t_deque *d, t_deque_node *node, char *op)
{
	size_t	i;

	i = 0;
	while (i++ < d->size && d->head != node)
		do_rotate(d, true, op);
}

void	bring_node_back(t_deque *d, int index, char *op)
{
	size_t	i;

	i = 0;
	while (i++ < d->size && (int) i <= index)
		do_reverse_rotate(d, true, op);
}

/**
 * @brief  Check if stack `b` is sorted in descending order
 * @param  *b: pointer to stack `b`
 * @retval `true` if the stack is sorted properly, otherwise `false`
 */
bool	is_sorted(t_deque *d)
{
	t_deque_node	*cur;

	cur = d->head;
	while (cur != d->head->prev)
	{
		if (cur->data > cur->next->data)
			return (false);
		cur = cur->next;
	}
	if (cur->data < cur->next->data)
		return (false);
	return (true);
}

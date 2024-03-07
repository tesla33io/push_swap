/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 20:07:00 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

#include "libft.h"
#include "operations.h"

void	prepare_b(t_deque *a, t_deque *b)
{
	do_push(a, b, true, PB);
	do_push(a, b, true, PB);
}

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

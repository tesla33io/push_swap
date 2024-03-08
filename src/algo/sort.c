/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/08 17:06:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

#include "libft.h"
#include "ft_printf.h"
#include "operations.h"

void	prepare_b(t_deque *a, t_deque *b)
{
	do_push(a, b, true, PB);
	do_push(a, b, true, PB);
	if (b->head < b->head->next)
		do_swap(b, true, SB);
}

void	iterate_a(t_deque *a, t_deque *b)
{
	t_deque_node	*cur_a;
	size_t			i_a;
	int				ops_need;
	int				ops_need_next;
	int				b_node_pos;

	cur_a = a->head;
	i_a = 0;
	while (i_a < a->size)
	{
		ops_need = 1 + deque_get_index(a, cur_a)
			+ deque_get_index(b, get_closest_node(b, cur_a));
		ops_need_next = 1 + deque_get_index(a, cur_a->next)
			+ deque_get_index(b, get_closest_node(b, cur_a->next));
		if (ops_need == 1)
		{
			do_push(a, b, true, PB);
			if (b->head->data < b->head->next->data)
				do_rotate(b, true, RB);
			return ;
		}
		else if (ops_need < ops_need_next
			&& cur_a->data > get_closest_node(b, cur_a)->data)
		{
			if (cur_a->data < stack_avg(a))
			{
				b_node_pos = deque_get_index(b, get_closest_node(b, cur_a));
				while (a->head != cur_a
					&& b->head != get_closest_node(b, cur_a))
					do_rr(a, b, true);
				bring_node_top(a, cur_a, RA);
				bring_node_top(b, get_closest_node(b, cur_a), RB);
				do_rotate(b, true, RB);
				do_push(a, b, true, PB);
				// bring_node_back(b, b_node_pos + 1, RRB);
				return ;
			}
			else
				do_rotate(a, true, RA);
		}
		else
		{
			do_rotate(b, true, RB);
			// do_rotate(a, true, RA);
			// do_swap(a, true, SA);
			continue ;
		}
		cur_a = cur_a->next;
		i_a++;
	}
	return ;
}

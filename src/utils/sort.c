/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:06:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/22 19:16:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief  Check if stack `b` is sorted in descending order
 * @param  *b: pointer to stack `b`
 * @retval `true` if the stack is sorted properly, otherwise `false`
 */
t_bool	is_sorted(t_deque *d)
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

/**
 * @brief  Sorts stack `b` if it's not sorted
 * @param  *b: pointer stack `b`
 * @retval None
 */
void	sort_b(t_deque *b)
{
	if (is_sorted(b) == false)
		do_rotate(b, true, RB);
}

void	sort_a(t_deque *a)
{
	if (is_sorted(a) == false)
	{
		if (get_min_pos(a) == 1 && get_max_pos(a) == 0)
		{
			do_reverse_rotate(a, true, RRA);
			do_reverse_rotate(a, true, RRA);
		}
		else if (get_min_pos(a) == 2 && get_max_pos(a) == 1)
			do_reverse_rotate(a, true, RRA);
		else if (get_min_pos(a) == 2 && get_max_pos(a) == 0)
		{
			do_swap(a, true, SA);
			do_reverse_rotate(a, true, RRA);
		}
		else if (get_min_pos(a) == 0 && get_max_pos(a) == 1)
		{
			do_swap(a, true, SA);
			do_rotate(a, true, RA);
		}
		else if (get_min_pos(a) == 1 && get_max_pos(a) == 2)
			do_swap(a, true, SA);
	}
}

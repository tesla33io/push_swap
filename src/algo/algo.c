/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:15:26 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/06 17:10:11 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>

void	begin(t_deque *a, t_deque *b)
{
	do_push(a, b, true, "pb");
	do_push(a, b, true, "pb");
	sort_b(b);
}

void	fill_up_b(t_deque *a, t_deque *b)
{
	long int		avg;

	avg = 0;
	while (a->size > 3)
	{
		avg = stack_avg(a);
		if (a->head->data >= avg / 2)
			do_rotate(a, true, RA);
		else
			do_push(a, b, true, PB);
	}
}

// 
void	move_cheapest(t_deque *a, t_deque *b, char *rotate, char *push)
{
	t_deque_node	*cur;
	int				min_clsts;
	int				i;

	cur = a->head;
	min_clsts = INT_MAX;
	while (cur != a->head->prev)
	{
		if (clsts_to_t(b, cur->data) < min_clsts)
			min_clsts = clsts_to_t(b, cur->data);
		cur = cur->next;
	}
	i = 0;
	while (clsts_to_t(b, a->head->data) != min_clsts && i++ < (int) a->size)
		do_rotate(a, true, rotate);
	do_push(a, b, true, push);
}

void	push_back_to_a(t_deque *a, t_deque *b)
{
	t_deque_node	*cur;
	int				min_ops;

	while (b->size > 0)
	{
		cur = b->head;
		min_ops = INT_MAX;
		while (cur != b->head->prev)
		{
			// ft_printf(1, "clsts to t: %d\n", clsts_to_t(a, cur->data));
			if (clsts_to_t(a, cur->data) < min_ops)
				min_ops = clsts_to_t(a, cur->data);
			cur = cur->next;
		}
		// ft_printf(1, "minops: %d\n", min_ops);
		if (min_ops == INT_MAX)
			return ;
		/** TODO:
		 * handle if the last elements has
		 * least amount of operations to trnsfr
		 */
		cur = b->head;
		while (clsts_to_t(a, cur->data) != min_ops)
			cur = cur->next;
		transfer(a, b, cur->data);
	}
}

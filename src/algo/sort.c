/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:28:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/12 21:05:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

#include <stdbool.h>

#include "../../include/operations.h"

void	prepare_b(t_deque *a, t_deque *b)
{
	do_push(a, b, true, PB);
	do_push(a, b, true, PB);
	if (b->head < b->head->next)
		do_swap(b, true, SB);
}

void	fill_b_switch(int *i, t_deque_node **cur, t_deque *a, t_deque *b)
{
	if (*i == calc_rr_to_b(a, b, *cur))
	{
		move_rr(a, b, *cur, true);
		*i = -42;
	}
	else if (*i == calc_rrr_to_b(a, b, *cur))
	{
		move_rrr(a, b, *cur, true);
		*i = -42;
	}
	else if (*i == calc_rarrb_to_b(a, b, *cur))
	{
		move_rarrb(a, b, *cur, true);
		*i = -42;
	}
	else if (*i == calc_rrarb_to_b(a, b, *cur))
	{
		move_rrarb(a, b, *cur, true);
		*i = -42;
	}
}

void	fill_b(t_deque *a, t_deque *b)
{
	int				i;
	t_deque_node	*cur;

	while (a->size > 3 && !is_sorted(a))
	{
		cur = a->head;
		i = calc_rotate_ab(a, b);
		while (i >= 0 && cur != b->head)
		{
			fill_b_switch(&i, &cur, a, b);
			cur = cur->next;
		}
	}
}

void	fill_a_switch(int *i, t_deque_node **cur, t_deque *a, t_deque *b)
{
	if (*i == calc_rr_to_a(a, b, *cur))
	{
		move_rr(a, b, *cur, false);
		*i = -42;
	}
	else if (*i == calc_rrr_to_a(a, b, *cur))
	{
		move_rrr(a, b, *cur, false);
		*i = -42;
	}
	else if (*i == calc_rarrb_to_a(a, b, *cur))
	{
		move_rarrb(a, b, *cur, false);
		*i = -42;
	}
	else if (*i == calc_rrarb_to_a(a, b, *cur))
	{
		move_rrarb(a, b, *cur, false);
		*i = -42;
	}
}

void	fill_a(t_deque *a, t_deque *b)
{
	int				i;
	t_deque_node	*cur;

	while (b->size)
	{
		cur = b->head;
		i = calc_rotate_ba(a, b);
		while (i >= 0 && cur != a->head)
		{
			fill_a_switch(&i, &cur, a, b);
			cur = cur->next;
		}
	}
}

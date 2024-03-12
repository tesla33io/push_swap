/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:45:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/12 20:53:37 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"
#include "../../include/operations.h"

#include <stdbool.h>

static void	fix_head(t_deque *d, char *op)
{
	if (d->head->data < d->head->next->data)
		do_swap(d, true, op);
}

void	move_rr(t_deque *a, t_deque *b, t_deque_node *node, bool to_b)
{
	t_deque_node	*cn;

	if (to_b)
	{
		cn = get_closest_node(b, node);
		while (a->head != node && deque_get_index(b, cn) > 0)
			do_rr(a, b, true);
		while (a->head != node)
			do_rotate(a, true, RA);
		while (deque_get_index(b, cn) > 0)
			do_rotate(b, true, RB);
		do_push(a, b, true, PB);
		fix_head(b, SB);
		return ;
	}
	cn = get_closest_node(a, node);
	while (b->head != node && deque_get_index(a, cn) > 0)
		do_rr(a, b, true);
	while (b->head != node)
		do_rotate(b, true, RB);
	while (deque_get_index(a, cn) > 0)
		do_rotate(a, true, RA);
	do_push(b, a, true, PA);
	fix_head(a, SA);
}

void	move_rrr(t_deque *a, t_deque *b, t_deque_node *node, bool to_b)
{
	t_deque_node	*cn;

	if (to_b)
	{
		cn = get_closest_node(b, node);
		while (a->head != node && deque_get_index(b, cn) > 0)
			do_rrr(a, b, true);
		while (a->head != node)
			do_reverse_rotate(a, true, RRA);
		while (deque_get_index(b, cn) > 0)
			do_reverse_rotate(b, true, RRB);
		do_push(a, b, true, PB);
		fix_head(b, SB);
		return ;
	}
	cn = get_closest_node(a, node);
	while (b->head != node && deque_get_index(a, cn) > 0)
		do_rrr(a, b, true);
	while (b->head != node)
		do_reverse_rotate(b, true, RRB);
	while (deque_get_index(a, cn) > 0)
		do_reverse_rotate(a, true, RRA);
	do_push(b, a, true, PA);
	fix_head(a, SA);
}

void	move_rrarb(t_deque *a, t_deque *b, t_deque_node *node, bool to_b)
{
	t_deque_node	*cn;

	if (to_b)
	{
		cn = get_closest_node(b, node);
		while (a->head != node)
			do_reverse_rotate(a, true, RRA);
		while (deque_get_index(b, cn) > 0)
			do_rotate(b, true, RB);
		do_push(a, b, true, PB);
		if (b->head->data < b->head->next->data)
			do_swap(b, true, SB);
	}
	else
	{
		cn = get_closest_node(a, node);
		while (deque_get_index(a, cn) > 0)
			do_reverse_rotate(a, true, RRA);
		while (b->head != node)
			do_rotate(b, true, RB);
		do_push(b, a, true, PA);
		if (a->head->data > a->head->next->data)
			do_swap(a, true, SA);
	}
}

void	move_rarrb(t_deque *a, t_deque *b, t_deque_node *node, bool to_b)
{
	t_deque_node	*cn;

	if (to_b)
	{
		cn = get_closest_node(b, node);
		while (a->head != node)
			do_rotate(a, true, RA);
		while (deque_get_index(b, cn) > 0)
			do_reverse_rotate(b, true, RRB);
		do_push(a, b, true, PB);
		if (b->head->data < b->head->next->data)
			do_swap(b, true, SB);
	}
	else
	{
		cn = get_closest_node(a, node);
		while (deque_get_index(a, cn) > 0)
			do_rotate(a, true, RA);
		while (b->head != node)
			do_reverse_rotate(b, true, RRB);
		do_push(b, a, true, PA);
		if (a->head->data > a->head->next->data)
			do_swap(a, true, SA);
	}
}

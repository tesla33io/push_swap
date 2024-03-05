/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:46:39 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/05 17:28:23 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

/**
 * @brief  Calculates the position of the node with the closest value to the top of the target stack.
 * @note   Returns the amount of steps required to bring a node to the top of the target stack.
 * @param  *trgt: pointer to the stack where to look
 * @param  val: value that will be transferred to the target stack
 * @retval position of the closest node (by value) to the top
 */
int	clsts_to_t(t_deque *trgt, int val)
{
	int				pos;
	int				clst;
	int				i;
	t_deque_node	*cur;

	if (!trgt || !trgt->head)
	{
		ft_printf(2, "[transfer.c:clsts_to_t] Error.\n");
		return (-1);
	}
	i = 0;
	cur = trgt->head;
	clst = INT_MAX;
	while (cur != trgt->head->prev)
	{
		if (cur->data > val && clst > cur->data)
		{
			clst = cur->data;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

/**
 * @brief  Calculates the position of the node with the closest value to the bottom of the target stack.
 * @note   Returns the amount of steps required to bring a node to the bottom of the target stack.
 * @param  *trgt: pointer to the stack where to look
 * @param  val: value that will be transferred to the target stack
 * @retval position of the closest node (by value) to the bottom
 */
int	clsts_to_b(t_deque *trgt, int val)
{
	int				pos;
	int				closest;
	int				i;
	t_deque_node	*cur;

	if (!trgt || !trgt->head)
	{
		ft_printf(2, "[transfer.c:clsts_to_b] Error.\n");
		return (-1);
	}
	i = 0;
	cur = trgt->head->prev;
	closest = INT_MAX;
	while (cur != trgt->head)
	{
		if (cur->data > val && closest > cur->data)
		{
			closest = cur->data;
			pos = i;
		}
		cur = cur->prev;
		i++;
	}
	return (pos);
}

void	transfer(t_deque *a, t_deque *b, t_deque_type val)
{
	int		steps;
	int		s_in_a;
	int		s_in_b;
	int		back_in_a;

	steps = clsts_to_t(a, val);
	if (steps < 0)
		return ;
	s_in_b = deque_get_index(b, val);
	s_in_a = steps - s_in_b;
	back_in_a = s_in_a;
	while (s_in_b-- > 0)
		do_rotate(b, true, RB);
	while (s_in_a-- > 0)
		do_rotate(a, true, RA);
	do_push(b, a, true, PA);
}

void	move_head(t_deque *from, t_deque *to)
{
	int		ttop;
	int		tbtm;
	int		i;

	ttop = clsts_to_t(to, from->head->data);
	tbtm = clsts_to_b(to, from->head->data);
	if (ttop < 0 || tbtm < 0)
		exit(-1);
	ft_printf(1, "top: %d - btm: %d\n", ttop, tbtm);
	if (ttop < tbtm)
	{
		i = 0;
		while (i < ttop - 1)
			do_rotate(to, true, RB);
		do_push(from, to, true, PB);
		// do rb
	}
	else
	{
		i = 0;
		while (i < tbtm - 1)
			do_reverse_rotate(to, true, RRB);
		do_push(from, to, true, PB);
		// do rrb
	}
}

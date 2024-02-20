/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:15:26 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/20 21:37:54 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	begin(t_deque *a, t_deque *b)
{
	do_push(a, b, true, "pb");
	do_push(a, b, true, "pb");
}

void	do_move(t_deque *from, t_deque *to, char *op)
{
	if (from->head->data > to->head->data)
		do_push(from, to, true, op);
	else
	{
		do_push(from, to, true, op);
		do_rotate(to, true, op);
	}
}

void	do_bring_up(t_deque *d, int index)
{
	int		i;

	i = -1;
	if (index < (int) d->size / 2)
	{
		while (++i < index - 1)
			do_rotate(d, true, RA);
	}
	else
	{
		while (++i < (int) d->size - index)
			do_reverse_rotate(d, true, RRA);
	}
}

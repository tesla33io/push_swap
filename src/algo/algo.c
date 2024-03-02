/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:15:26 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/02 17:58:00 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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
		if (a->head->data >= avg)
			do_rotate(a, true, RA);
		else
			do_push(a, b, true, PB);
	}
}

void	push_back_to_a(t_deque *a, t_deque *b)
{
	while (b->size > 0)
	{
		do_push(b, a, true, PA);
		if (a->head->data > a->head->next->data)
			do_swap(a, true, SA);
	}
}

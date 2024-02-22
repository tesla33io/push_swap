/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:15:26 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/22 21:29:39 by astavrop         ###   ########.fr       */
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
	size_t			half;

	avg = 0;
	half = (size_t) a->size / 2;
	while (a->size > 3 && a->size > half)
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
	int	i;

	while (b->size > 0)
	{
		i = 0;
		while (i < calc_ops_in_target(a, b->head->data))
			do_rotate(a, true, RA);
		do_push(b, a, true, PA);
	}
}

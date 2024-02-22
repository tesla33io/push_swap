/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:15:26 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/22 18:23:51 by astavrop         ###   ########.fr       */
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
		if (a->head->data > avg)
			do_rotate(a, true, RA);
		else
			do_push(a, b, true, PB);
	}
}
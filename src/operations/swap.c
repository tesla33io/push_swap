/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:23:19 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/21 14:48:33 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	do_swap(t_deque *d, t_bool print, char *op)
{
	t_deque_node	*first;
	t_deque_node	*second;

	if (d->size < 1)
		return ;
	first = deque_pop_front(d);
	second = deque_pop_front(d);
	deque_push_front(d, first);
	deque_push_front(d, second);
	if (print)
		ft_printf(1, "%s\n", op);
}

void	do_ss(t_deque *a, t_deque *b, t_bool print)
{
	do_swap(a, false, "sa error");
	do_swap(b, false, "sb error");
	if (print)
		ft_printf(1, "ss\n");
}

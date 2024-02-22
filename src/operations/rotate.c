/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:57:20 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/21 14:48:29 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	do_rotate(t_deque *d, t_bool print, char *op)
{
	t_deque_node	*first;

	first = deque_pop_front(d);
	deque_push_back(d, first);
	if (print)
		ft_printf(1, "%s\n", op);
}

void	do_reverse_rotate(t_deque *d, t_bool print, char *op)
{
	t_deque_node	*last;

	last = deque_pop_back(d);
	deque_push_front(d, last);
	if (print)
		ft_printf(1, "%s\n", op);
}

void	do_rr(t_deque *a, t_deque *b, t_bool print)
{
	do_rotate(a, false, "ra error");
	do_rotate(b, false, "rb error");
	if (print)
		ft_printf(1, "rr\n");
}

void	do_rrr(t_deque *a, t_deque *b, t_bool print)
{
	do_reverse_rotate(a, false, "rra error");
	do_reverse_rotate(b, false, "rrb error");
	if (print)
		ft_printf(1, "rrr\n");
}

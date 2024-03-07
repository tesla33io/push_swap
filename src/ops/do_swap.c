/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:46:27 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 19:10:17 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdbool.h>

#include "libft.h"
#include "ft_printf.h"

void	do_swap(t_deque *d, bool print, char *op)
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

void	do_ss(t_deque *a, t_deque *b, bool print)
{
	do_swap(a, false, "sa error");
	do_swap(b, false, "sb error");
	if (print)
		ft_printf(1, "ss\n");
}

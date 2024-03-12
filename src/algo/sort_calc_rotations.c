/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_calc_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:45:44 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/12 21:05:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

#include <limits.h>

int	calc_rotate_ab(t_deque *a, t_deque *b)
{
	int				n;
	size_t			i;
	t_deque_node	*cur;

	cur = a->head;
	n = __INT_MAX__;
	i = 0;
	while (cur && i < a->size)
	{
		if (n > calc_rr_to_b(a, b, cur))
			n = calc_rr_to_b(a, b, cur);
		if (n > calc_rrr_to_b(a, b, cur))
			n = calc_rrr_to_b(a, b, cur);
		if (n > calc_rarrb_to_b(a, b, cur))
			n = calc_rarrb_to_b(a, b, cur);
		if (n > calc_rrarb_to_b(a, b, cur))
			n = calc_rrarb_to_b(a, b, cur);
		cur = cur->next;
		i++;
	}
	return (n);
}

int	calc_rotate_ba(t_deque *a, t_deque *b)
{
	int				n;
	size_t			i;
	t_deque_node	*cur;

	cur = b->head;
	i = 0;
	n = __INT_MAX__;
	while (cur && i < b->size)
	{
		if (n > calc_rr_to_a(a, b, cur))
			n = calc_rr_to_a(a, b, cur);
		if (n > calc_rrr_to_a(a, b, cur))
			n = calc_rrr_to_a(a, b, cur);
		if (n > calc_rarrb_to_a(a, b, cur))
			n = calc_rarrb_to_a(a, b, cur);
		if (n > calc_rrarb_to_a(a, b, cur))
			n = calc_rrarb_to_a(a, b, cur);
		cur = cur->next;
		i++;
	}
	return (n);
}

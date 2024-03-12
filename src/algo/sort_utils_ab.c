/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:17:38 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/12 14:17:42 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

int	calc_rr(t_deque *a, t_deque *b, t_deque_node *node)
{
	int				n;
	t_deque_node	*cnb;

	cnb = get_closest_node(b, node);
	n = deque_get_index(b, cnb);
	if (n < deque_get_index(a, node))
		n = deque_get_index(a, node);
	return (n);
}

int	calc_rrr(t_deque *a, t_deque *b, t_deque_node *node)
{
	int				n;
	t_deque_node	*cnb;

	n = 0;
	cnb = get_closest_node(b, node);
	if (deque_get_index(b, cnb))
		n = b->size - deque_get_index(b, cnb);
	if (deque_get_index(a, node) && (n < (int) (a->size
					- deque_get_index(a, node))))
		n = (int) a->size - deque_get_index(a, node);
	return (n);
}

int	calc_rrarb(t_deque *a, t_deque *b, t_deque_node *node)
{
	int				n;
	t_deque_node	*cnb;

	n = 0;
	cnb = get_closest_node(b, node);
	if (deque_get_index(a, node))
		n = (int) a->size - deque_get_index(a, node);
	n += deque_get_index(b, cnb);
	return (n);
}

int	calc_rarrb(t_deque *a, t_deque *b, t_deque_node *node)
{
	int				n;
	t_deque_node	*cnb;

	n = 0;
	cnb = get_closest_node(b, node);
	if (deque_get_index(b, cnb))
		n = (int) b->size - deque_get_index(b, cnb);
	n += deque_get_index(a, node);
	return (n);
}

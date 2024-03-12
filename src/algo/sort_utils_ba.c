/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_ba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:45:53 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/12 21:05:06 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

int	calc_rr_to_a(t_deque *a, t_deque *b, t_deque_node *node)
{
	int				n;
	t_deque_node	*cn;

	cn = get_closest_node(a, node);
	n = deque_get_index(a, cn);
	if (n < deque_get_index(b, node))
		n = deque_get_index(b, node);
	return (n);
}

int	calc_rrr_to_a(t_deque *a, t_deque *b, t_deque_node *node)
{
	int				n;
	t_deque_node	*cn;

	cn = get_closest_node(a, node);
	n = 0;
	if (deque_get_index(a, cn))
		n = a->size - deque_get_index(a, cn);
	if (deque_get_index(b, node)
		&& (n < (int)(b->size - deque_get_index(b, node))))
		n = b->size - deque_get_index(b, node);
	return (n);
}

int	calc_rarrb_to_a(t_deque *a, t_deque *b, t_deque_node *node)
{
	int				n;
	t_deque_node	*cn;

	n = 0;
	cn = get_closest_node(a, node);
	if (deque_get_index(b, node))
		n = (int) b->size - deque_get_index(b, node);
	n += deque_get_index(a, cn);
	return (n);
}

int	calc_rrarb_to_a(t_deque *a, t_deque *b, t_deque_node *node)
{
	int				n;
	t_deque_node	*cn;

	n = 0;
	cn = get_closest_node(a, node);
	if (deque_get_index(a, cn))
		n = (int) a->size - deque_get_index(a, cn);
	n += deque_get_index(b, node);
	return (n);
}

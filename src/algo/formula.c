/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:20:07 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/20 22:25:16 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief  Function to count how many 'basic' steps needed to move node
 *         from stakc `a` to stack `b`
 * @note   'basic' steps are: pa, pb, ra, rb, rra, rrb
 * @param  *a: pointer to stack `a`
 * @param  *b: pointer to stack `b`
 * @param  iia: index of the node in stack `a`
 * @retval Number of steps
 */
int	count_steps(t_deque *a, t_deque *b, int iia, t_deque_node *nodea)
{
	int				n_steps;
	int				i;
	t_deque_node	*cur;

	n_steps = 0;
	i = 0;
	cur = b->head;
	if (iia > (int) a->size / 2)
		n_steps++;
	if (cur->data < nodea->data)
		return (iia + 1 - n_steps);
	else if (nodea->data < cur->prev->data)
		return (iia + 1);
	while (i < (int) b->size)
	{
		if (cur->data > nodea->data && cur->next->data < nodea->data)
			n_steps = iia + i;
		cur = cur->next;
		i++;
	}
	return (n_steps);
}

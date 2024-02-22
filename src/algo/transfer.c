/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:46:39 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/22 19:36:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <limits.h>

/**
 * @brief  Calculate position of the node in target stack with the closet
 *         value to the `val`
 * @note   Basically returns amount of steps to bring a node to the top
 *         of the `trgt`
 * @param  *trgt: pointer to stack where to look
 * @param  val: value that will be transferd to the target stack
 * @retval position of closet node (by value)
 */
int	calc_ops_in_target(t_deque *trgt, int val)
{
	int				pos;
	int				clst;
	int				i;
	t_deque_node	*cur;

	i = 0;
	cur = trgt->head;
	clst = INT_MAX;
	while (cur != trgt->head->prev)
	{
		if (cur->data > val && clst > cur->data)
		{
			clst = cur->data;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

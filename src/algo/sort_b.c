/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:06:11 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/20 22:01:35 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * @brief  Check if stack `b` is sorted in descending order
 * @param  *b: pointer to stack `b`
 * @retval `true` if the stack is sorted properly, otherwise `false`
 */
t_bool	is_b_sorted(t_deque *b)
{
	t_deque_node	*cur;

	cur = b->head;
	while (cur != b->head->prev)
	{
		if (cur->data < cur->next->data)
			return (false);
		cur = cur->next;
	}
	if (cur->data > cur->next->data)
		return (false);
	return (true);
}

/**
 * @brief  Sorts stack `b` if it's not sorted
 * @param  *b: pointer stack `b`
 * @retval None
 */
void	sort_b(t_deque *b)
{
	if (is_b_sorted(b) == false)
		do_rotate(b, true, RB);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:33:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/04 18:36:21 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	deque_get_index(t_deque *d, t_deque_type val)
{
	size_t			i;
	t_deque_node	*cur;

	i = 0;
	cur = d->head;
	while (cur != d->head->prev)
	{
		if (cur->data == val)
			return ((int) i);
		cur = cur->next;
		i++;
	}
	return ((int) i);
}

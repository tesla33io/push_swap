/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:49:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/08 16:49:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include "libft.h"

long int	stack_avg(t_deque *d)
{
	long int		sum;
	t_deque_node	*cur;

	sum = 0;
	cur = d->head;
	while (cur != d->head->prev)
	{
		sum += cur->data;
		cur = cur->next;
	}
	sum += cur->data;
	return (sum / d->size);
}

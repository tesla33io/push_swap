/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:57 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/22 18:05:11 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

long int	new_avg(t_deque *d, long int oavg, int rval)
{
	long int	newa;

	newa = (oavg * (d->size + 1)) - rval;
	newa /= d->size;
	return (newa);
}

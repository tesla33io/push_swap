/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:10:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/08 17:11:10 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

#include "libft.h"

size_t	get_min_pos(t_deque *d)
{
	t_deque_node	*cur;
	size_t			pos;
	int				min;

	cur = d->head;
	pos = 0;
	min = INT_MAX;
	while (cur != d->head->prev)
	{
		if (cur->data < min)
			min = cur->data;
		cur = cur->next;
	}
	if (cur->data < min)
		min = cur->data;
	cur = d->head;
	while (cur->data != min)
	{
		cur = cur->next;
		pos++;
	}
	return (pos);
}

size_t	get_max_pos(t_deque *d)
{
	t_deque_node	*cur;
	size_t			pos;
	int				max;

	cur = d->head;
	pos = 0;
	max = INT_MIN;
	while (cur != d->head->prev)
	{
		if (cur->data > max)
			max = cur->data;
		cur = cur->next;
	}
	if (cur->data > max)
		max = cur->data;
	cur = d->head;
	while (cur->data != max)
	{
		cur = cur->next;
		pos++;
	}
	return (pos);
}

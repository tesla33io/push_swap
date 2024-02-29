/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:26:39 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/29 14:56:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

void	deque_insert(t_deque *d, int i, t_deque_type val)
{
	t_deque_node	*new_node;
	t_deque_node	*cur;
	int				orig_i;

	ft_printf(1, "i: %d, size: %d\n", i, d->size);
	if (i > (int) d->size)
		return ;
	new_node = malloc(sizeof(t_deque_node));
	new_node->data = val;
	cur = d->head;
	orig_i = i;
	while (--i > 0)
		cur = cur->next;
	new_node->prev = cur->prev;
	new_node->next = cur;
	cur->prev->next = new_node;
	if (orig_i == 0)
		d->head = new_node;
	if (orig_i == (int) d->size)
		d->head->prev = new_node;
	d->size++;
}

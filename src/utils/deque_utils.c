/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:11:10 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 20:49:53 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"
#include "../../include/colors.h"
#include <stdbool.h>

void	deque_print(t_deque *deque)
{
	t_deque_node	*cur;

	cur = deque->head;
	ft_printf(1, GREEN"{head}->"R);
	while (cur != deque->head->prev)
	{
		ft_printf(1, "{ "YELLOW"%d"R" }->", cur->data);
		cur = cur->next;
	}
	ft_printf(1, "{ "YELLOW"%d"R" }->", cur->data);
	ft_printf(1, GREEN"{end}\n"R);
}

int	deque_get_index(t_deque *d, t_deque_node *node)
{
	size_t			i;
	t_deque_node	*cur;

	i = 0;
	cur = d->head;
	while (cur != node && i++ < d->size)
		cur = cur->next;
	return ((int) i);
}

bool	is_sorted(t_deque *d)
{
	t_deque_node	*cur;

	cur = d->head;
	while (cur != d->head->prev)
	{
		if (cur->data > cur->next->data)
			return (false);
		cur = cur->next;
	}
	return (true);
}

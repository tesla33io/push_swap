/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:14:24 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 19:32:38 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdlib.h>

#include "libft.h"

void	clear_deque(t_deque *d)
{
	t_deque_node	*n;

	while (d->size > 0)
	{
		n = deque_pop_front(d);
		free(n);
	}
}

int	ps_clear(t_deque *a, t_deque *b)
{
	if (a)
	{
		if (a->head)
			clear_deque(a);
		free(a);
	}
	if (b)
	{
		if (b->head)
			clear_deque(b);
		free(b);
	}
	return (0);
}

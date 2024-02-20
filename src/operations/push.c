/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:53:32 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/20 21:52:45 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	do_push(t_deque *from, t_deque *to, t_bool print, char *op)
{
	t_deque_node	*el;

	if (from->size < 1)
		return ;
	el = deque_pop_front(from);
	deque_push_front(to, el);
	if (print)
		ft_printf(1, "%s\n", op);
}

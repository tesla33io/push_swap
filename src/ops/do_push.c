/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:44:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 19:08:53 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdbool.h>

#include "libft.h"
#include "ft_printf.h"

void	do_push(t_deque *from, t_deque *to, bool print, char *op)
{
	t_deque_node	*el;

	if (from->size < 1)
		return ;
	el = deque_pop_front(from);
	deque_push_front(to, el);
	if (print)
		ft_printf(1, "%s\n", op);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:55:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/18 20:17:54 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"
#include "colors.h"
#include <stdlib.h>

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

int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;

	a = parse_input(argc, argv);
	b = malloc(sizeof(t_deque));
	b->head = NULL;
	ft_printf(1, "-- Start --\n");
	deque_print(a);
	// deque_print(b);
	do_swap(a, true, SA);
	do_push(a, b, true, PB);
	do_push(a, b, true, PB);
	do_push(a, b, true, PB);
	do_rotate(b, true, RB);
	do_reverse_rotate(a, true, RRA);
	deque_print(a);
	deque_print(b);
	free(b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:55:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/06 17:12:27 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "colors.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_deque			*a;
	t_deque			*b;

	a = parse_input(argc, argv);
	b = malloc(sizeof(t_deque));
	b->head = NULL;
	// fill_up_b(a, b);
	// deque_print(a);
	// deque_print(b);
	// move_min_on_top(a, RA);
	begin(a, b);
	while (a->size > 3)
	{
		if (a->head->data < stack_avg(a))
			move_cheapest(a, b, RA, PB);
		else
			do_rotate(a, true, RA);
	}
	exit(0);
	while (b->size > 0)
		move_cheapest(b, a, RB, PA);
	sort_a(a);
	// push_back_to_a(a, b);
	return (0);
}

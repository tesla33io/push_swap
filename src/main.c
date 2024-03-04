/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:55:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/04 18:58:34 by astavrop         ###   ########.fr       */
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
	// ft_printf(1, BG_YELLOW BLACK "DEQUE `A` INITIAL STATE:" R "\n");
	// deque_print(a);
	fill_up_b(a, b);
	sort_a(a);
	push_back_to_a(a, b);
	// while (b->size > 0)
	// {
	// 	swap = false;
	// 	ft_printf(1, ":A:::DEQUE\n");
	// 	deque_print(a);
	// 	ft_printf(1, ":B:::DEQUE\n");
	// 	deque_print(b);
	// 	ft_printf(1, ":OPS:: val(%d) - steps(%d)\n",
	// 		b->head->data, clsts_to_t(a, b->head->data));
	// 	if (clsts_to_t(a, b->head->data) == 1)
	// 		swap = true;
	// 	do_push(b, a, false, PA);
	// 	if (swap)
	// 		do_swap(a, false, SA);
	// }
	return (0);
}

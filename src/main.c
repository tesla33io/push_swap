/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:42:56 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 20:12:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdlib.h>

#include "ft_printf.h"

int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;

	a = parse_input(ac, av);
	b = malloc(sizeof(t_deque));
	b->head = NULL;
	b->size = 0;
	prepare_b(a, b);
	deque_print(a);
	deque_print(b);
	ft_printf(1, "Closest for %d: %d\n", a->head->next->next->next->data,
		get_closest_node(b, a->head->next->next->next)->data);
	ft_printf(1, "A head index: %d\nClosest index: %d\n",
		deque_get_index(a, a->head->next->next->next->data),
		deque_get_index(b,
			get_closest_node(b, a->head->next->next->next)->data));
	return (ps_clear(a, b));
}

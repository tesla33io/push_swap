/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:42:56 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/12 20:46:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

#include <stdlib.h>

#include "../include/operations.h"

static void	a_small_check(t_deque *a)
{
	if (a->size == 2 && is_sorted(a))
		exit(ps_clear(a, NULL));
	if (a->size == 2 && !is_sorted(a))
	{
		do_swap(a, true, SA);
		exit(ps_clear(a, NULL));
	}
	if (is_sorted(a))
		exit(ps_clear(a, NULL));
}

int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;

	check_input(ac, av);
	a = parse_input(ac, av);
	a_small_check(a);
	b = malloc(sizeof(t_deque));
	b->head = NULL;
	b->size = 0;
	if (a->size == 3 && !is_sorted(a))
	{
		sort_three(a);
		exit (ps_clear(a, b));
	}
	prepare_b(a, b);
	fill_b(a, b);
	sort_three(a);
	fill_a(a, b);
	shift_a(a);
	return (ps_clear(a, b));
}

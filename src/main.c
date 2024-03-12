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

#include "../ft_printf/includes/ft_printf.h"

int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;

	a = parse_input(ac, av);
	b = malloc(sizeof(t_deque));
	b->head = NULL;
	b->size = 0;
	prepare_b(a, b);
	fill_b(a, b);
	sort_three(a);
	fill_a(a, b);
	shift_a(a);
	return (ps_clear(a, b));
}

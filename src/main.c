/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:55:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/29 15:16:35 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	t_deque			*a;
	t_deque			*b;

	a = parse_input(argc, argv);
	b = malloc(sizeof(t_deque));
	b->head = NULL;
	int arr[] = {10, 22, 90, 33, 21, 50, 41, 60};
	ft_printf(1, "Length of LIS is %d\n", lis(arr, 8));
	// fill_up_b(a, b);
	// sort_a(a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:12:33 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/21 14:48:41 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_deque	*parse_input(int argc, char **argv)
{
	int		i;
	int		value;
	t_deque	*deque;

	i = 0;
	deque = malloc(sizeof(t_deque));
	deque->head = NULL;
	while (++i < argc)
	{
		value = ft_atoi(argv[i]);
		deque_emplace_back(deque, value);
	}
	deque->size = i - 1;
	return (deque);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:47:01 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 18:48:32 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdlib.h>

#include "libft.h"

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

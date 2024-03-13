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

#include "../../include/ps.h"

#include <stdbool.h>
#include <stdlib.h>

/*
static void	parse_substr(char *str, t_deque *d)
{
	int		i;
	char	*n_start;
	bool	not_s;

	i = -1;
	not_s = false;
	while (str[++i])
	{
		if (str[i] >= 48 && str[i] <= 57 && !not_s)
		{
			n_start = &str[i];
			not_s = true;
		}
		else if (str[i] == ' ' && not_s)
		{
			deque_emplace_back(d, ft_atoi(n_start));
			not_s = false;
		}
	}
}
*/

t_deque	*parse_input(int argc, char **argv)
{
	int		i;
	int		value;
	t_deque	*deque;

	i = 0;
	deque = malloc(sizeof(t_deque));
	deque->head = NULL;
	deque->size = 0;
	while (++i < argc)
	{
		value = ft_atoi(argv[i]);
		deque_emplace_back(deque, value);
	}
	return (deque);
}			

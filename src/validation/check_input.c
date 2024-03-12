/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:55:54 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/12 21:55:56 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"
#include <iso646.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include "../../ft_printf/includes/ft_printf.h"

#define MAX_CAPACITY 1000

static void	print_error()
{
	ft_printf(2, "Error\n");
	exit(1);
}

static void	check_dupl(int ac, int64_t nums[MAX_CAPACITY])
{
	int64_t	i;
	int64_t	j;

	i = -1;
	while (++i < ac - 1)
	{
		j = i;
		if (nums[i] > INT_MAX || nums[i] < INT_MIN)
			print_error();
		while (++j < ac - 1 - i)
		{
			if (nums[j] == nums[i])
				print_error();
		}
	}
}

static void	check_substr(char *str, int64_t *idx, int64_t *nums)
{
	int		i;
	bool	not_s;
	char	*n_start;

	i = -1;
	not_s = false;
	while (str[++i])
	{
		if (str[i] <= 57 && str[i] >= 48 && !not_s)
		{
			n_start = &str[i];
			not_s = true;
			continue ;
		}
		else if (str[i] == ' ' && not_s)
		{
			nums[*idx++] = ft_atoi(n_start);
			not_s = false;
		}
	}
}

bool	c_in(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (true);
		str++;
	}
	return (false);
}

void	check_input(int ac, char **av)
{
	int64_t	tmp[MAX_CAPACITY];
	int64_t	i;

	if (ac == 1)
		exit(0);
	i = -1;
	while (++i < ac - 1)
	{
		if (c_in(' ', av[i + 1]))
			check_substr(av[i + 1], &i, tmp);
		tmp[i] = ft_atoi(av[i + 1]);
	}
	check_dupl(ac, tmp);
}


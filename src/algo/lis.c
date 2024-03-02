/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:28 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/02 17:36:16 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Longest Increasing Subsequence

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	lis(int arr[], int n)
{
	int	lis[n];
	int	i;
	int	j;
	int	max;

	i = 1;
	while (i < n)
	{
		lis[i] = 1;
		j = -1;
		while (++j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
		i++;
	}
	max = lis[0];
	i = 0;
	while (++i < n)
	{
		if (max < lis[i])
			max = lis[i];
	}
	return (max);
}

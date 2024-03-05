/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:36:09 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/05 17:39:29 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the absolute value of an integer.
 * 
 * This function takes an integer `val` as input and returns its absolute value. 
 * The absolute value of a number is its distance from zero, 
 * which is always non-negative.
 *
 * @param val The integer value for which to calculate the absolute value.
 *
 * @return The absolute value of the input `val`.
 */
int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:07:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/08 17:09:51 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

#include "libft.h"
#include "ft_printf.h"
#include "operations.h"

void	sort_three(t_deque *d)
{
	if (is_sorted(d) == false)
	{
		if (get_min_pos(d) == 1 && get_max_pos(d) == 0)
		{
			do_reverse_rotate(d, true, RRA);
			do_reverse_rotate(d, true, RRA);
		}
		else if (get_min_pos(d) == 2 && get_max_pos(d) == 1)
			do_reverse_rotate(d, true, RRA);
		else if (get_min_pos(d) == 2 && get_max_pos(d) == 0)
		{
			do_swap(d, true, SA);
			do_reverse_rotate(d, true, RRA);
		}
		else if (get_min_pos(d) == 0 && get_max_pos(d) == 1)
		{
			do_swap(d, true, SA);
			do_rotate(d, true, RA);
		}
		else if (get_min_pos(d) == 1 && get_max_pos(d) == 2)
			do_swap(d, true, SA);
	}
}

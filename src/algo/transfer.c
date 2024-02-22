/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:46:39 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/21 16:18:52 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
 * @brief  Transfer element form stack `a` to stack `b` based on the current
 *         position and right position in `b`
 * @note   
 * @param  *a: pointer to stack `a`
 * @param  *b: pointer to stack `b`
 * @param  iia: index of node in stakc `a`
 * @param  pib: position for node in stack `b`
 * @retval None
 */
void	transfer_to_b(t_deque *a, t_deque *b, int iia, int pib)
{
	int		i;

	(void)b;
	(void)pib;
	i = -1;
	while (++i < iia)
		do_rotate(a, true, RA);
	i = -1;
	while (b->head->data > a->head->data && ++i < (int) b->size)
		do_reverse_rotate(b, true, RRB);
	do_push(a, b, true, PB);
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:43:10 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 20:02:55 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

// Input handling

t_deque			*parse_input(int argc, char **argv);

// Sorting

void			prepare_b(t_deque *a, t_deque *b);
t_deque_node	*get_closest_node(t_deque *trgt, t_deque_node *node);

// Utils

void			deque_print(t_deque *deque);
int				deque_get_index(t_deque *d, t_deque_type val);
int				ft_abs(int val);

// Clear

int				ps_clear(t_deque *a, t_deque *b);

#endif
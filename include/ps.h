/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:43:10 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/08 17:13:20 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdbool.h>

# include "../libft/libft.h"

// Input handling

t_deque			*parse_input(int argc, char **argv);

// Sorting

void			prepare_b(t_deque *a, t_deque *b);
void			iterate_a(t_deque *a, t_deque *b);

void			sort_three(t_deque *d);

t_deque_node	*get_closest_node(t_deque *trgt, t_deque_node *node);
void			bring_node_top(t_deque *d, t_deque_node *node, char *op);
void			bring_node_back(t_deque *d, int index, char *op);
bool			is_sorted(t_deque *d);

// Utils

void			deque_print(t_deque *deque);
int				deque_get_index(t_deque *d, t_deque_node *node);
int				ft_abs(int val);
long int		stack_avg(t_deque *d);
size_t			get_min_pos(t_deque *d);
size_t			get_max_pos(t_deque *d);

// Clear

int				ps_clear(t_deque *a, t_deque *b);

#endif

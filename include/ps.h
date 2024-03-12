/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:43:10 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/12 21:05:04 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdbool.h>

# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

// Input handling

t_deque			*parse_input(int argc, char **argv);
void			check_input(int ac, char **av);

// Sorting

void			prepare_b(t_deque *a, t_deque *b);

void			sort_three(t_deque *d);

t_deque_node	*get_closest_node(t_deque *trgt, t_deque_node *node);
bool			is_sorted(t_deque *d);
void			fill_b(t_deque *a, t_deque *b);
void			fill_a(t_deque *a, t_deque *b);
void			shift_a(t_deque *a);

// Calculations

int				calc_rr_to_b(t_deque *a, t_deque *b, t_deque_node *node);
int				calc_rrr_to_b(t_deque *a, t_deque *b, t_deque_node *node);
int				calc_rrarb_to_b(t_deque *a, t_deque *b, t_deque_node *node);
int				calc_rarrb_to_b(t_deque *a, t_deque *b, t_deque_node *node);

int				calc_rr_to_a(t_deque *a, t_deque *b, t_deque_node *node);
int				calc_rrr_to_a(t_deque *a, t_deque *b, t_deque_node *node);
int				calc_rarrb_to_a(t_deque *a, t_deque *b, t_deque_node *node);
int				calc_rrarb_to_a(t_deque *a, t_deque *b, t_deque_node *node);

int				calc_rotate_ba(t_deque *a, t_deque *b);
int				calc_rotate_ab(t_deque *a, t_deque *b);

void			move_rr(t_deque *a, t_deque *b, t_deque_node *node, bool to_b);
void			move_rrr(t_deque *a, t_deque *b, t_deque_node *node,
					bool to_b);
void			move_rrarb(t_deque *a, t_deque *b, t_deque_node *node,
					bool to_b);
void			move_rarrb(t_deque *a, t_deque *b, t_deque_node *node,
					bool to_b);

// Utils

void			deque_print(t_deque *deque);
int				deque_get_index(t_deque *d, t_deque_node *node);
int				ft_abs(int val);
long int		stack_avg(t_deque *d);
size_t			get_min_pos(t_deque *d);
size_t			get_max_pos(t_deque *d);
bool			is_sorted(t_deque *d);
bool			c_in(char c, char *str);

// Clear

int				ps_clear(t_deque *a, t_deque *b);

#endif

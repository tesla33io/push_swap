/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:12:54 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/04 18:44:43 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stddef.h>

# define SA  "sa"
# define SB  "sb"
# define SS  "ss"
# define PA  "pa"
# define PB  "pb"
# define RA  "ra"
# define RB  "rb"
# define RR  "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

/* INPUT */

t_deque		*parse_input(int argc, char **argv);

/* OPERATIONS */

void		do_swap(t_deque *d, t_bool print, char *op);
void		do_ss(t_deque *a, t_deque *b, t_bool print);

void		do_push(t_deque *from, t_deque *to, t_bool print, char *op);

void		do_rotate(t_deque *d, t_bool print, char *op);
void		do_rr(t_deque *a, t_deque *b, t_bool print);

void		do_reverse_rotate(t_deque *d, t_bool print, char *op);
void		do_rrr(t_deque *a, t_deque *b, t_bool print);

/* ALGO STUFF */

t_bool		is_sorted(t_deque *b);
void		sort_b(t_deque *b);
void		sort_a(t_deque *a);

void		begin(t_deque *a, t_deque *b);
int			count_steps(t_deque *a, t_deque *b, int iia, t_deque_node *nodea);

void		fill_up_b(t_deque *a, t_deque *b);
void		push_back_to_a(t_deque *a, t_deque *b);
int			clsts_to_t(t_deque *trgt, int val);
void		transfer(t_deque *a, t_deque *b, t_deque_type val);

int			lis(int arr[], int n);

/* UTILS */

void		deque_print(t_deque *deque);
void		deque_insert(t_deque *d, int i, t_deque_type val);
long int	stack_avg(t_deque *d);
long int	new_avg(t_deque *d, long int oavg, int rval);
size_t		get_min_pos(t_deque *d);
size_t		get_max_pos(t_deque *d);
int			deque_get_index(t_deque *d, t_deque_type val);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:01:00 by astavrop          #+#    #+#             */
/*   Updated: 2024/03/07 19:09:49 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

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

# include <stdbool.h>

# include "libft.h"

void		do_push(t_deque *from, t_deque *to, bool print, char *op);
void		do_rotate(t_deque *d, bool print, char *op);
void		do_reverse_rotate(t_deque *d, bool print, char *op);
void		do_rr(t_deque *a, t_deque *b, bool print);
void		do_rrr(t_deque *a, t_deque *b, bool print);
void		do_swap(t_deque *d, bool print, char *op);
void		do_ss(t_deque *a, t_deque *b, bool print);

#endif
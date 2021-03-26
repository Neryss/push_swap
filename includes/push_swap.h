/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:43:15 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/26 12:30:12 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define DEBUG 0

typedef struct s_stack
{
	int	*tab;
	int	size;
}				t_stack;

typedef struct s_swapper
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_list	*instru;
}				t_swapper;

typedef struct s_smallest
{
	int	nb;
	int	index;
}				t_smallest;

typedef struct s_biggest
{
	int	nb;
	int	index;
}				t_biggest;

int			is_sorted(t_swapper *swapper);
int			is_b_rev_sorted(t_swapper *swapper);
void		swap_int(int *a, int *b);
void		minus_one_stack(t_stack *stack);
void		plus_one_stack(t_stack *stack);
void		close_program(int error);
void		get_moves(t_swapper *swapper);
void		execute_moves(t_swapper *swapper);
void		check_args(int argc, char **argv, t_swapper *swapper);
void		move_sa(t_swapper *swapper);
void		move_sb(t_swapper *swapper);
void		move_ss(t_swapper *swapper);
void		move_pa(t_swapper *swapper);
void		move_pb(t_swapper *swapper);
void		move_ra(t_swapper *swapper);
void		move_rb(t_swapper *swapper);
void		move_rr(t_swapper *swapper);
void		move_rra(t_swapper *swapper);
void		move_rrb(t_swapper *swapper);
void		move_rrr(t_swapper *swapper);
void		display_stacks(t_swapper *swapper);
void		display(t_swapper *swapper);

void		push_swap(t_swapper *swapper);
t_smallest	find_smallest_b(t_swapper *swapper);
t_biggest	find_biggest(t_stack stack);
void		six_to_hundreds(t_swapper *swapper);
int			find_median(t_swapper *swapper);
int			is_b_rev_sorted(t_swapper *swapper);
int			is_sorted(t_swapper *swapper);
void		do_move(t_swapper *swapper, char *move);

#endif

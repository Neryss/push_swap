/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:43:15 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/24 10:42:00 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define DEBUG 1

typedef struct s_stack
{
	int	*tab;
	int	size;
}				t_stack;

typedef struct s_swapper
{
	t_stack	stack_a;
	t_stack	stack_b;
}				t_swapper;

void	swap_int(int *a, int *b);
void	minus_one_stack(t_stack *stack);
void	plus_one_stack(t_stack *stack);
void	close_program(int error);
void	check_args(int argc, char **argv, t_swapper *swapper);
void	move_sa(t_swapper *swapper);
void	move_sb(t_swapper *swapper);
void	move_ss(t_swapper *swapper);
void	move_pa(t_swapper *swapper);
void	move_pb(t_swapper *swapper);
void	move_ra(t_swapper *swapper);
void	move_rb(t_swapper *swapper);
void	move_rra(t_swapper *swapper);
void	move_rrb(t_swapper *swapper);
void	move_rrr(t_swapper *swapper);
void	display_stacks(t_swapper *swapper);

#endif

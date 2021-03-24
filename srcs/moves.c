/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:00:08 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/24 10:34:21 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	move_sa(t_swapper *swapper)
{
	swap_int(&swapper->stack_a.tab[0], &swapper->stack_a.tab[1]);
}

void	move_sb(t_swapper *swapper)
{
	swap_int(&swapper->stack_b.tab[0], &swapper->stack_b.tab[1]);
}

void	move_ss(t_swapper *swapper)
{
	move_sa(swapper);
	move_sb(swapper);
}

void	plus_one_stack(t_stack *stack)
{
	int	i;

	stack->size += 1;
	i = stack->size;
	while (i > 0)
	{
		stack->tab[i] = stack->tab[i - 1];
		i--;
	}
}

void	minus_one_stack(t_stack *stack)
{
	int	i;

	stack->size -= 1;
	i = 0;
	if (stack->size == 0)
		return ;
	while (i < stack->size)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
}

void	move_pa(t_swapper *swapper)
{
	if (swapper->stack_b.size)
	{
		plus_one_stack(&swapper->stack_a);
		swapper->stack_a.tab[0] = swapper->stack_b.tab[0];
		minus_one_stack(&swapper->stack_b);
	}
}

void	move_pb(t_swapper *swapper)
{
	if (swapper->stack_a.size)
	{
		plus_one_stack(&swapper->stack_b);
		swapper->stack_b.tab[0] = swapper->stack_a.tab[0];
		minus_one_stack(&swapper->stack_a);
	}
}

void	move_ra(t_swapper *swapper)
{
	int	i;
	int	tmp;

	tmp = swapper->stack_a.tab[0];
	i = 0;
	while (i < swapper->stack_a.size)
	{
		swapper->stack_a.tab[i] = swapper->stack_a.tab[i + 1];
		i++;
	}
	swapper->stack_a.tab[swapper->stack_a.size - 1] = tmp;
}

void	move_rra(t_swapper *swapper)
{
	int	i;
	int	tmp;

	i = swapper->stack_a.size;
	tmp = swapper->stack_a.tab[swapper->stack_a.size - 1];
	printf("(%d)", tmp);
	while (i > 0)
	{
		swapper->stack_a.tab[i] = swapper->stack_a.tab[i - 1];
		i--;
	}
	swapper->stack_a.tab[0] = tmp;
}
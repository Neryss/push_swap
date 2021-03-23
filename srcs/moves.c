/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:00:08 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/23 16:36:06 by ckurt            ###   ########lyon.fr   */
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
	while (i < stack->size)
	{
		stack->tab[i] = stack->tab[i + 1];
		i++;
	}
}

void	move_pa(t_swapper *swapper)
{
	if (swapper->stack_b.tab)
	{
		plus_one_stack(&swapper->stack_a);
		swapper->stack_a.tab[0] = swapper->stack_b.tab[0];
		minus_one_stack(&swapper->stack_b);
	}
}

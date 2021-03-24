/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:39:27 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/24 10:40:12 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_sb(t_swapper *swapper)
{
	swap_int(&swapper->stack_b.tab[0], &swapper->stack_b.tab[1]);
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

void	move_rb(t_swapper *swapper)
{
	int	i;
	int	tmp;

	tmp = swapper->stack_b.tab[0];
	i = 0;
	while (i < swapper->stack_b.size)
	{
		swapper->stack_b.tab[i] = swapper->stack_b.tab[i + 1];
		i++;
	}
	swapper->stack_b.tab[swapper->stack_b.size - 1] = tmp;
}

void	move_rrb(t_swapper *swapper)
{
	int	i;
	int	tmp;

	i = swapper->stack_b.size;
	tmp = swapper->stack_b.tab[swapper->stack_b.size - 1];
	while (i > 0)
	{
		swapper->stack_b.tab[i] = swapper->stack_b.tab[i - 1];
		i--;
	}
	swapper->stack_b.tab[0] = tmp;
}
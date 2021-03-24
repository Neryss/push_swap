/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:40:25 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/24 14:09:04 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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

void	move_ss(t_swapper *swapper)
{
	move_sa(swapper);
	move_sb(swapper);
}

void	move_rr(t_swapper *swapper)
{
	move_ra(swapper);
	move_rb(swapper);
}

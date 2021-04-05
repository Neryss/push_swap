/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:32:43 by ckurt             #+#    #+#             */
/*   Updated: 2021/04/05 14:58:45 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_median(t_swapper *swapper)
{
	int	*array;
	int	i;
	int	median;

	i = 0;
	array = malloc(sizeof(int) * swapper->stack_a.size);
	if (!array)
		close_program(1);
	while (i < swapper->stack_a.size)
	{
		array[i] = swapper->stack_a.tab[i];
		i++;
	}
	sort_int_tab(array, swapper->stack_a.size);
	median = array[swapper->stack_a.size / 2];
	return (median);
}

t_smallest	find_smallest(t_swapper *swapper)
{
	t_smallest	smallest;
	int			i;

	smallest.nb = swapper->stack_a.tab[0];
	i = 0;
	while (i < swapper->stack_a.size)
	{
		if (swapper->stack_a.tab[i] < smallest.nb)
		{
			smallest.nb = swapper->stack_a.tab[i];
			smallest.index = i;
		}
		i++;
	}
	return (smallest);
}

int	which_way_rot(t_swapper *swapper, t_smallest smallest)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	i = swapper->stack_a.size - smallest.index;
	j = smallest.index;
	if (j < i)
		return (1);
	return (0);
}

void	do_rotate(t_swapper *swapper)
{
	t_smallest	smallest;

	smallest = find_smallest(swapper);
	if (swapper->stack_a.tab[0] == smallest.nb)
		return ;
	if (which_way_rot(swapper, smallest))
		while (swapper->stack_a.tab[0] != smallest.nb)
			do_move(swapper, "ra");
	else
		while (swapper->stack_a.tab[0] != smallest.nb)
			do_move(swapper, "rra");
}

void	do_sort_things(t_smallest *s_b, t_smallest *b_b
, t_swapper *swapper)
{
	if (s_b->dist < b_b->dist)
	{
		if (s_b->index < swapper->stack_b.size / 2)
		{
			while (swapper->stack_b.tab[0] != s_b->nb)
				do_move(swapper, "rb");
			do_move(swapper, "pa");
			do_move(swapper, "ra");
		}
		else
			while (swapper->stack_b.tab[0] != s_b->nb)
				do_move(swapper, "rrb");
	}
	else
	{
		if (b_b->index < swapper->stack_b.size / 2)
			while (swapper->stack_b.tab[0] != b_b->nb)
				do_move(swapper, "rb");
		else
			while (swapper->stack_b.tab[0] != b_b->nb)
				do_move(swapper, "rrb");
		do_move(swapper, "pa");
	}
}

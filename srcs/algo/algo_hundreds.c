/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundreds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:26 by ckurt             #+#    #+#             */
/*   Updated: 2021/04/05 14:55:43 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_q1(t_swapper *swapper, int which)
{
	int	*array;
	int	i;
	int	quartile;

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
	if (which == 0)
		quartile = array[swapper->stack_a.size / 4];
	else
		quartile = array[3 * (swapper->stack_a.size / 4)];
	return (quartile);
}

void	sort_quartile(t_swapper *swapper)
{
	t_smallest	s_b;
	t_smallest	b_b;

	while (swapper->stack_b.size)
	{
		s_b = find_smallest_b(swapper);
		s_b.dist = distance_to_top(swapper, &s_b);
		b_b = find_biggest(swapper->stack_b);
		b_b.dist = distance_to_top(swapper, &b_b);
		do_sort_things(&s_b, &b_b, swapper);
	}
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

void	hundreds_plus(t_swapper *swapper)
{
	push_q1(swapper);
	sort_quartile(swapper);
	push_q2(swapper);
	do_rotate(swapper);
	sort_quartile(swapper);
	do_rotate(swapper);
	push_q3(swapper);
	sort_quartile(swapper);
	push_q4(swapper);
	do_rotate(swapper);
	sort_quartile(swapper);
	do_rotate(swapper);
}

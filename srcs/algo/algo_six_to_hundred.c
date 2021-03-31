/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_six_to_hundred.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:51:59 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/31 11:08:21 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_rotate(t_swapper *swapper, int rotate)
{
	while (rotate)
	{
		do_move(swapper, "ra");
		rotate--;
	}
}

void	do_rrotate(t_swapper *swapper, int rotate)
{
	while (rotate)
	{
		do_move(swapper, "rra");
		rotate--;
	}
}

void	do_sort_things(t_smallest *s_b, t_smallest *b_b
, t_swapper *swapper, int *rotate)
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
		*rotate += 1;
		do_move(swapper, "pa");
	}
}

void	sort_medians(t_swapper *swapper, int side)
{
	t_smallest	s_b;
	t_smallest	b_b;
	int			rotate;

	if (side == 1)
		push_more_median(swapper);
	else
		push_less_median(swapper);
	rotate = 0;
	while (swapper->stack_b.size)
	{
		s_b = find_smallest_b(swapper);
		s_b.dist = distance_to_top(swapper, &s_b);
		b_b = find_biggest(swapper->stack_b);
		b_b.dist = distance_to_top(swapper, &b_b);
		do_sort_things(&s_b, &b_b, swapper, &rotate);
	}
	do_rotate(swapper, rotate);
}

void	six_to_hundreds(t_swapper *swapper)
{
	sort_medians(swapper, 0);
	sort_medians(swapper, 1);
}

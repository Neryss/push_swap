/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_six_to_hundred.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:51:59 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/30 14:58:10 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_less_median(t_swapper *swapper)
{
	int	median;
	int	count;

	median = find_median(swapper);
	count = swapper->stack_a.size / 2;
	while (count)
	{
		if (swapper->stack_a.tab[0] < median)
		{
			do_move(swapper, "pb");
			count--;
		}
		else
			do_move(swapper, "ra");
	}
}

void	push_more_median(t_swapper *swapper)
{
	int	median;
	int	count;

	median = find_median(swapper);
	count = swapper->stack_a.size - (swapper->stack_a.size / 2);
	while (count)
	{
		if (swapper->stack_a.tab[0] >= median)
		{
			do_move(swapper, "pb");
			count--;
		}
		else
			do_move(swapper, "ra");
	}
}

void	do_rotate(t_swapper *swapper, int rotate)
{
	while (rotate)
	{
		do_move(swapper, "ra");
		rotate--;
	}
}

int	distance_to_top(t_swapper *swapper, t_smallest *nb)
{
	int	i;

	i = nb->index;
	if (i > swapper->stack_b.size / 2)
	{
		while (i <= swapper->stack_b.size)
			i++;
	}
	return (i);
}

void	sort_more_median(t_swapper *swapper, int side)
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
		if (s_b.dist < b_b.dist)
		{
			if (s_b.index < swapper->stack_b.size / 2)
			{
				while (swapper->stack_b.tab[0] != s_b.nb)
					do_move(swapper, "rb");
				do_move(swapper, "pa");
				do_move(swapper, "ra");
			}
			else
			{
				while (swapper->stack_b.tab[0] != s_b.nb)
					do_move(swapper, "rrb");
			}
		}
		else
		{
			if (b_b.index < swapper->stack_b.size / 2)
			{
				while (swapper->stack_b.tab[0] != b_b.nb)
					do_move(swapper, "rb");
			}
			else
			{
				while (swapper->stack_b.tab[0] != b_b.nb)
					do_move(swapper, "rrb");
			}
			rotate++;
			do_move(swapper, "pa");
		}
	}
	do_rotate(swapper, rotate);
}

void	six_to_hundreds(t_swapper *swapper)
{
	sort_more_median(swapper, 0);
	sort_more_median(swapper, 1);
}

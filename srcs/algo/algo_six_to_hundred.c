/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_six_to_hundred.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:51:59 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/26 12:29:51 by ckurt            ###   ########lyon.fr   */
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
		if (swapper->stack_a.tab[0] > median)
		{
			do_move(swapper, "pb");
			count--;
		}
		else
			do_move(swapper, "ra");
	}
}

void	sort_more_median(t_swapper *swapper)
{
	
}

void	sort_less_median(t_swapper *swapper)
{
	t_smallest	s_b;
	t_biggest	b_b;

	push_less_median(swapper);
	while (swapper->stack_b.size)
	{
		s_b = find_smallest_b(swapper);
		b_b = find_biggest(swapper->stack_b);
		if (s_b.index < b_b.index)
		{
			while (s_b.index > 0)
			{
				do_move(swapper, "rb");
				s_b.index--;
			}
			do_move(swapper, "pa");
		}
		else
		{
			while (b_b.index < swapper->stack_b.size + 1)
			{
				do_move(swapper, "rrb");
				b_b.index++;
			}
			do_move(swapper, "pa");
			do_move(swapper, "ra");
		}
	}
}


void	six_to_hundreds(t_swapper *swapper)
{
	sort_less_median(swapper);
}

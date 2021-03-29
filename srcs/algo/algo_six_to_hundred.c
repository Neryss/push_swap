/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_six_to_hundred.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:51:59 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/29 10:25:47 by ckurt            ###   ########lyon.fr   */
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

void	sort_more_median(t_swapper *swapper)
{
	t_smallest	s_b;
	t_biggest	b_b;
	int			rotate;

	push_more_median(swapper);
	rotate = 0;
	while (swapper->stack_b.size)
	{
		s_b = find_smallest_b(swapper);
		b_b = find_biggest(swapper->stack_b);
		//display_stacks(swapper);
		//printf("smallest | %d | id %d\n", s_b.nb, s_b.index);
		//printf("biggest  | %d | id %d\n", b_b.nb, b_b.index);
		if (s_b.index <= b_b.index)
		{
			while (s_b.index > 0)
			{
				do_move(swapper, "rb");
				s_b.index--;
			}
			do_move(swapper, "pa");
			do_move(swapper, "ra");
		}
		// TODO : ERROR HERE
		else
		{
			if (b_b.index < swapper->stack_b.size / 2)
			{
				while (b_b.index > 0)
				{
					do_move(swapper, "rb");
					b_b.index--;
				}
			}
			else
			{
				while (swapper->stack_b.tab[0] != b_b.nb)
				{
					//printf("%d %d\n", swapper->stack_b.tab[0], b_b.nb);
					do_move(swapper, "rrb");
					//b_b.index++;
				}
			}
			rotate++;
			do_move(swapper, "pa");
		}
		//display_stacks(swapper);
	}
	while (rotate)
	{
		do_move(swapper, "ra");
		rotate--;
	}
	//display_stacks(swapper);
}

void	test(t_swapper *swapper)
{
	t_smallest	s_b;
	t_biggest	b_b;

	while (swapper->stack_b.size)
	{
		s_b = find_smallest_b(swapper);
		b_b = find_biggest(swapper->stack_b);
	}
}

void	sort_less_median(t_swapper *swapper)
{
	t_smallest	s_b;
	t_biggest	b_b;
	int			rotate;

	push_less_median(swapper);
	rotate = 0;
	while (swapper->stack_b.size)
	{
		s_b = find_smallest_b(swapper);
		b_b = find_biggest(swapper->stack_b);
		//display_stacks(swapper);
		if (s_b.index <= b_b.index)
		{
			while (s_b.index > 0)
			{
				do_move(swapper, "rb");
				s_b.index--;
			}
			do_move(swapper, "pa");
			do_move(swapper, "ra");
			rotate++;
		}
		else
		{
			if (b_b.index <= (swapper->stack_b.size / 2))
			{
				while (b_b.index > 0)
				{
					do_move(swapper, "rb");
					b_b.index--;
				}
			}
			else
			{
				while (b_b.index < swapper->stack_b.size)
				{
					do_move(swapper, "rrb");
					b_b.index++;
				}
			}
			do_move(swapper, "pa");
		}
	}
	while (rotate > 0)
	{
		do_move(swapper, "rra");
		rotate--;
	}
	// display_stacks(swapper);
}


void	six_to_hundreds(t_swapper *swapper)
{
	sort_less_median(swapper);
	//display_stacks(swapper);
	sort_more_median(swapper);
	//display_stacks(swapper);
	// do_move(swapper, "sa");
}

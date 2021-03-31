/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundreds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:26 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/31 11:21:08 by ckurt            ###   ########lyon.fr   */
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
		quartile = array[(swapper->stack_a.size /4) * 3];
	return (quartile);
}

void	push_quartile(t_swapper *swapper, int which)
{
	int	count;
	int quartile;
	if (which == 0)
		quartile = find_q1(swapper, 0);
	else
		quartile = find_q1(swapper, 1);
	count = swapper->stack_a.size / 4;
	if (which == 0 || which == 1)
	{
		while (count)
		{
			if (swapper->stack_a.tab[0] < quartile)
			{
				do_move(swapper, "pb");
				count--;
			}
			else
				do_move(swapper, "ra");
		}
	}
	else
	{
		while (count)
		{
			if (swapper->stack_a.tab[0] >= quartile)
			{
				do_move(swapper, "pb");
				count--;
			}
			else
				do_move(swapper, "ra");
		}
	}
}

void	sort_quartile(t_swapper *swapper)
{
	t_smallest	s_b;
	t_smallest	b_b;
	int			rotate;

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

void	push_quartiles(t_swapper *swapper)
{
	push_quartile(swapper, 0);
	sort_quartile(swapper);
	push_less_median(swapper);
	sort_medians(swapper, 0);
	push_quartile(swapper, 1);
	sort_quartile(swapper);
	push_quartile(swapper, 3);
	sort_quartile(swapper);
	display(swapper);
	while (1)
		;
	// do_rrotate(swapper, swapper->stack_a.size / 4);
}


void	hundreds_plus(t_swapper *swapper)
{
	push_quartiles(swapper);
	display(swapper);
}

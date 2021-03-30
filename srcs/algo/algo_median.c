/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:02:37 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/30 17:03:29 by ckurt            ###   ########lyon.fr   */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quartiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:00:03 by ckurt             #+#    #+#             */
/*   Updated: 2021/04/05 16:31:26 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_q1(t_swapper *swapper)
{
	int	count;
	int	quartile;
	int	i;

	i = 0;
	quartile = find_q1(swapper, 0);
	count = swapper->stack_a.size / 4;
	while (count)
	{
		if (swapper->stack_a.tab[0] < quartile)
		{
			do_move(swapper, "pb");
			count--;
		}
		else
		{
			do_move(swapper, "ra");
			i++;
			if (i > swapper->stack_a.size)
				break ;
		}
	}
}

void	push_q2(t_swapper *swapper)
{
	t_pusher	pusher;

	pusher.quartile = find_q1(swapper, 0);
	pusher.median = find_median(swapper);
	pusher.i = 0;
	pusher.j = 0;
	while (pusher.j < swapper->stack_a.size / 2)
	{
		if (swapper->stack_a.tab[0] >= pusher.quartile
			&& swapper->stack_a.tab[0] < pusher.median)
		{
			do_move(swapper, "pb");
			pusher.j++;
		}
		else
		{
			do_move(swapper, "ra");
			pusher.i++;
			if (pusher.i > swapper->stack_a.size)
				break ;
		}
	}
}

void	push_q3(t_swapper *swapper)
{
	t_pusher	pusher;
	int			count;

	pusher.quartile = find_q1(swapper, 1);
	pusher.median = find_median(swapper);
	count = swapper->stack_a.size / 4;
	pusher.i = 0;
	pusher.j = 0;
	while (pusher.j < count * 3)
	{
		if (swapper->stack_a.tab[0] >= pusher.median
			&& swapper->stack_a.tab[0] < pusher.quartile)
		{
			do_move(swapper, "pb");
			pusher.j++;
		}
		else
		{
			do_move(swapper, "ra");
			pusher.i++;
			if (pusher.i >= swapper->stack_a.size)
				break ;
		}
	}
}

void	push_q4(t_swapper *swapper)
{
	t_pusher	pusher;
	t_smallest	bigger;

	pusher.quartile = find_q1(swapper, 1);
	bigger = find_biggest(swapper->stack_a);
	pusher.i = 0;
	pusher.j = 0;
	while (pusher.j < swapper->stack_a.size)
	{
		if (swapper->stack_a.tab[0] >= pusher.quartile
			&& swapper->stack_a.tab[0] <= bigger.nb)
		{
			do_move(swapper, "pb");
			pusher.j++;
		}
		else
		{
			do_move(swapper, "ra");
			pusher.i++;
			if (pusher.i > swapper->stack_a.size)
				break ;
		}
	}
}

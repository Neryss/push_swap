/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quartiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:00:03 by ckurt             #+#    #+#             */
/*   Updated: 2021/04/01 13:22:55 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_q1(t_swapper *swapper)
{
	int	count;
	int	quartile;

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
			do_move(swapper, "ra");
	}
}

void	push_q2(t_swapper *swapper)
{
	int	count;
	int	quartile;
	int	median;

	quartile = find_q1(swapper, 0);
	median = find_median(swapper);
	count = swapper->stack_a.size / 4;
	// if (count + quartile != swapper->stack_a.size / 2)
	// 		count = swapper->stack_a.size / 2 - quartile;
	printf("median : %d\nquartile %d\ncount : %d\n", median, quartile, count);
	while (count)
	{
		if (swapper->stack_a.tab[0] >= quartile && swapper->stack_a.tab[0] < median)
		{
			do_move(swapper, "pb");
			count--;
		}
		else
			do_move(swapper, "ra");
	}
}

void	push_q3(t_swapper *swapper)
{
	int	quartile;
	int	median;
	int	count;

	quartile = find_q1(swapper, 1);
	median = find_median(swapper);
	count = swapper->stack_a.size / 4;
	// if (count + quartile + 1 != swapper->stack_a.size)
	// 	count = swapper->stack_a.size - quartile - 1;
	printf("median : %d\nquartile %d\ncount : %d\n", median, quartile, count);
	while (count)
	{
		if (swapper->stack_a.tab[0] >= median && swapper->stack_a.tab[0] < quartile)
		{
			do_move(swapper, "pb");
			count--;
		}
		else
			do_move(swapper, "ra");
	}
}

void	push_q4(t_swapper *swapper)
{
	int	quartile;
	int	count;
	int	size;

	quartile = find_q1(swapper, 1);
	size = swapper->stack_a.size;
	count = swapper->stack_a.size / 4;
	printf("quartile %d\ncount : %d\nsize : %d\n", quartile, count, swapper->stack_a.size);
	// if (count + quartile + 1 != swapper->stack_a.size)
	// 		count = swapper->stack_a.size - quartile - 3;
	// display(swapper);
	// while (1)
	// 	;
	while (count)
	{
		// printf("count during : %d\n", count);
		if (swapper->stack_a.tab[0] >= quartile && swapper->stack_a.tab[0] <= size)
		{
			do_move(swapper, "pb");
			count--;
		}
		else
			do_move(swapper, "ra");
	}
}

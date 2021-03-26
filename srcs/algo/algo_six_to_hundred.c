/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_six_to_hundred.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:51:59 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/26 11:56:41 by ckurt            ###   ########lyon.fr   */
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
	ft_sort_int_tab(array, swapper->stack_a.size);
	median = array[swapper->stack_a.size / 2];
	printf("median is (%d)\n", median);
	return (median);
}

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

void	six_to_hundreds(t_swapper *swapper)
{
	push_less_median(swapper);
}

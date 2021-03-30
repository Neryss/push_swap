/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:32:43 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/30 15:04:21 by ckurt            ###   ########lyon.fr   */
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
	sort_int_tab(array, swapper->stack_a.size);
	median = array[swapper->stack_a.size / 2];
	return (median);
}

t_smallest	find_smallest(t_swapper *swapper)
{
	t_smallest	smallest;
	int			i;

	smallest.nb = swapper->stack_a.tab[0];
	i = 0;
	while (i < swapper->stack_a.size)
	{
		if (swapper->stack_a.tab[i] < smallest.nb)
		{
			smallest.nb = swapper->stack_a.tab[i];
			smallest.index = i;
		}
		i++;
	}
	return (smallest);
}

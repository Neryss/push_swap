/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:15:08 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/26 12:47:26 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_swapper *swapper)
{
	int	i;

	i = 0;
	while (i < swapper->stack_a.size - 1)
	{
		if (swapper->stack_a.tab[i] > swapper->stack_a.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_b_rev_sorted(t_swapper *swapper)
{
	int	i;

	i = 0;
	while (i < swapper->stack_b.size - 1)
	{
		if (swapper->stack_b.tab[i] < swapper->stack_b.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_smallest	find_smallest_b(t_swapper *swapper)
{
	t_smallest	smallest;
	int			i;

	smallest.nb = swapper->stack_b.tab[0];
	smallest.index = 0;
	i = 0;
	while (i < swapper->stack_b.size)
	{
		if (swapper->stack_b.tab[i] < smallest.nb)
		{
			smallest.nb = swapper->stack_b.tab[i];
			smallest.index = i;
		}
		i++;
	}
	return (smallest);
}

t_biggest	find_biggest(t_stack stack)
{
	t_biggest	biggest;
	int			i;

	biggest.nb = stack.tab[0];
	biggest.index = 0;
	i = 0;
	while (i < stack.size)
	{
		if (stack.tab[i] > biggest.nb)
		{
			biggest.nb = stack.tab[i];
			biggest.index = i;
		}
		i++;
	}
	return (biggest);
}

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap_int(&tab[i], &tab[i + 1]);
				swap = 1;
			}
			i++;
		}
	}
}
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
	if (DEBUG)
		printf("median is (%d)\n", median);
	return (median);
}

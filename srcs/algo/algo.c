/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:36:24 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/26 11:43:57 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	three_nb(t_swapper *swapper)
{
	if ((swapper->stack_a.tab[0] > swapper->stack_a.tab[1])
		&& (swapper->stack_a.tab[0] < swapper->stack_a.tab[2]))
		do_move(swapper, "sa");
	else if (swapper->stack_a.tab[0] > swapper->stack_a.tab[2])
		do_move(swapper, "ra");
	else if (swapper->stack_a.tab[0] < swapper->stack_a.tab[2])
		do_move(swapper, "rra");
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

void	sort_a2(t_swapper *swapper)
{
	t_smallest	smallest;

	smallest = find_smallest(swapper);
	while (swapper->stack_a.tab[0] != smallest.nb)
	{
		if (smallest.index > swapper->stack_a.size / 2)
			do_move(swapper, "rra");
		else
			do_move(swapper, "ra");
	}
	do_move(swapper, "pb");
	smallest = find_smallest(swapper);
	while (swapper->stack_a.tab[0] != smallest.nb)
	{
		if (smallest.index > swapper->stack_a.size / 2)
			do_move(swapper, "rra");
		else
			do_move(swapper, "ra");
	}
}

void	five_nb(t_swapper *swapper)
{
	sort_a2(swapper);
	do_move(swapper, "pb");
	while (!is_sorted(swapper))
	{
		if (swapper->stack_a.size == 3)
			three_nb(swapper);
		else if (swapper->stack_a.size == 2)
			do_move(swapper, "sa");
	}
	while (!is_b_rev_sorted(swapper))
		do_move(swapper, "rb");
	do_move(swapper, "pa");
	do_move(swapper, "pa");
}

int		find_median(t_swapper *swapper)
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

void	six_to_hundreds(t_swapper *swapper)
{
	int	median;

	median = find_median(swapper);
	while ()
}

void	push_swap(t_swapper *swapper)
{
	if (swapper->stack_a.size == 2)
		do_move(swapper, "sa");
	else if (swapper->stack_a.size == 3)
		three_nb(swapper);
	else if (swapper->stack_a.size == 5 || swapper->stack_a.size == 4)
		five_nb(swapper);
	else if (swapper->stack_a.size > 5 && swapper->stack_a.size <= 100)
	if (!is_sorted(swapper))
		push_swap(swapper);
}

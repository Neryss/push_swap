/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:46:31 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/29 11:50:05 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	small_algos(t_swapper *swapper)
{
	if (swapper->stack_a.size == 2)
		do_move(swapper, "sa");
	else if (swapper->stack_a.size == 3)
		three_nb(swapper);
	else if (swapper->stack_a.size == 5 || swapper->stack_a.size == 4)
		five_nb(swapper);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundreds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:26 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/30 17:36:07 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_quartile(t_swapper *swapper)
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
	quartile = array[swapper->stack_a.size / 4];
	return (quartile);
}

void	push_less_quartile(t_swapper *swapper)
{
	int	quartile;
	int	count;

	quartile = find_quartile(swapper);
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

void	hundreds_plus(t_swapper *swapper)
{
	push_less_quartile(swapper);
}

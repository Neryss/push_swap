/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:15:08 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/26 10:15:18 by ckurt            ###   ########lyon.fr   */
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

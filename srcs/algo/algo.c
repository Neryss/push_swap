/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:36:24 by ckurt             #+#    #+#             */
/*   Updated: 2021/04/01 10:35:25 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(t_swapper *swapper)
{
	small_algos(swapper);
	if (swapper->stack_a.size > 5 && swapper->stack_a.size <= 100)
		six_to_hundreds(swapper);
	else if (swapper->stack_a.size > 100)
		hundreds_plus(swapper);
	if (!is_sorted(swapper))
		push_swap(swapper);
}

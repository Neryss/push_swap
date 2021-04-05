/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundreds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:20:26 by ckurt             #+#    #+#             */
/*   Updated: 2021/04/05 14:57:17 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_q1(t_swapper *swapper, int which)
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
	if (which == 0)
		quartile = array[swapper->stack_a.size / 4];
	else
		quartile = array[3 * (swapper->stack_a.size / 4)];
	return (quartile);
}

void	sort_quartile(t_swapper *swapper)
{
	t_smallest	s_b;
	t_smallest	b_b;

	while (swapper->stack_b.size)
	{
		s_b = find_smallest_b(swapper);
		s_b.dist = distance_to_top(swapper, &s_b);
		b_b = find_biggest(swapper->stack_b);
		b_b.dist = distance_to_top(swapper, &b_b);
		do_sort_things(&s_b, &b_b, swapper);
	}
}

void	hundreds_plus(t_swapper *swapper)
{
	push_q1(swapper);
	sort_quartile(swapper);
	push_q2(swapper);
	do_rotate(swapper);
	sort_quartile(swapper);
	do_rotate(swapper);
	push_q3(swapper);
	sort_quartile(swapper);
	push_q4(swapper);
	do_rotate(swapper);
	sort_quartile(swapper);
	do_rotate(swapper);
}

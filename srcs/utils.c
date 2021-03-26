/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:58:44 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/26 10:10:00 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_stacks(t_swapper *swapper)
{
	int	i;

	i = 0;
	printf("A############A\n");
	printf("stack a size : %d\n", swapper->stack_a.size);
	while (i < swapper->stack_a.size)
		printf("[%d]\n", swapper->stack_a.tab[i++]);
	i = 0;
	printf("B############B\n");
	printf("stack b size : %d\n", swapper->stack_b.size);
	while (i < swapper->stack_b.size)
	{
		printf("[%d](%d)\n", swapper->stack_b.tab[i], i);
		i++;
	}
}

void	display(t_swapper *swapper)
{
	int	i;
	int	min;

	if (swapper->stack_a.size < swapper->stack_b.size)
		min = swapper->stack_b.size;
	else
		min = swapper->stack_a.size;
	i = 0;
	printf("|----------------------------------------------------|\n");
	printf("|id    |stack a               |stack b               |\n");
	printf("|      |size : %-15d |size : %-15d |\n", swapper->stack_a.size,
		swapper->stack_b.size);
	printf("|----------------------------------------------------|\n");
	while (i < min)
	{
		printf("|%-6d|%-22d|%-22d|\n", i, swapper->stack_a.tab[i],
			swapper->stack_b.tab[i]);
		i++;
	}
	printf("|----------------------------------------------------|\n");
}

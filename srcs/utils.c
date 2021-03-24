/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:58:44 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/24 10:59:04 by ckurt            ###   ########lyon.fr   */
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
		printf("[%d]\n", swapper->stack_b.tab[i++]);
}

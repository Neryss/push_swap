/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:29 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/30 16:15:47 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	check_sorted(t_swapper *swapper)
{
	int	i;

	i = 0;
	while (i < swapper->stack_a.size - 1)
	{
		if (swapper->stack_a.tab[i] > swapper->stack_a.tab[i + 1])
		{
			printf("KO\n");
			close_program(0);
		}
		i++;
	}
	display(swapper);
	printf("OK\n");
	while (1)
		;
}

int	main(int argc, char **argv)
{
	t_swapper	swapper;

	check_args(argc, argv, &swapper);
	// display(&swapper);
	get_moves(&swapper);
	execute_moves(&swapper);
	check_sorted(&swapper);
	// printf("----------------------\n\n");
	close_program(0);
}

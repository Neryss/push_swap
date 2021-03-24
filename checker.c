/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:29 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/24 16:39:29 by ckurt            ###   ########lyon.fr   */
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
	printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_swapper	swapper;

	check_args(argc, argv, &swapper);
	get_moves(&swapper);
	if (DEBUG)
		display_stacks(&swapper);
	execute_moves(&swapper);
	if (DEBUG)
		display_stacks(&swapper);
	check_sorted(&swapper);
	close_program(0);
}

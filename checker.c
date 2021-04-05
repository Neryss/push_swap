/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:29 by ckurt             #+#    #+#             */
/*   Updated: 2021/04/05 10:54:36 by ckurt            ###   ########lyon.fr   */
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
			ft_putstr("KO\n");
			close_program(0);
		}
		i++;
	}
	ft_putstr("OK\n");
}

int	main(int argc, char **argv)
{
	t_swapper	swapper;

	if (argc == 1)
		return (0);
	check_args(argc, argv, &swapper);
	get_moves(&swapper);
	check_sorted(&swapper);
	close_program(0);
}

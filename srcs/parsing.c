/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:24 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/24 12:21:51 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_stacks(char **argv, t_swapper *swapper)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < swapper->stack_a.size + 1)
		swapper->stack_a.tab[j++] = ft_atoi(argv[i++]);
}

void	init_stacks(int argc, char **argv, t_swapper *swapper)
{
	swapper->instru = NULL;
	swapper->stack_a.size = argc - 1;
	swapper->stack_a.tab = malloc(sizeof(int) * swapper->stack_a.size);
	if (!swapper->stack_a.tab)
		close_program(1);
	swapper->stack_b.size = 0;
	swapper->stack_b.tab = malloc(sizeof(int) * swapper->stack_b.size);
	if (!swapper->stack_b.tab)
		close_program(1);
	fill_stacks(argv, swapper);
}

void	check_args(int argc, char **argv, t_swapper *swapper)
{
	int	i;

	i = 1;
	if (argc <= 1)
		close_program(1);
	while (i < argc)
	{
		if (!ft_islinenum(argv[i]))
			close_program(1);
		i++;
	}
	init_stacks(argc, argv, swapper);
}

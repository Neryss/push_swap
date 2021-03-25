/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:24 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/25 14:20:17 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_dupes(t_swapper *swapper, int nb, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (swapper->stack_a.tab[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

void	fill_stacks(char **argv, t_swapper *swapper)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < swapper->stack_a.size + 1)
	{
		if ((argv[i][0] == '-' || argv[i][0] == '+') && ft_strlen(argv[i]) == 1)
			close_program(1);
		if ((argv[i][0] == '-' || argv[i][0] == '+')
			&& (argv[i][1] == '-' || argv[i][1] == '+'))
			close_program(1);
		swapper->stack_a.tab[j] = ft_atoi(argv[i]);
		if (check_dupes(swapper, swapper->stack_a.tab[j], j))
			close_program(1);
		i++;
		j++;
	}
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

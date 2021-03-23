/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:24 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/23 14:45:09 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	close_program(char *error)
{
	if (!error)
		exit(0);
	printf("Error\n%s\n", error);
	exit(0);
}

void	fill_stacks(char **argv, t_swapper *swapper)
{
	int	i;

	i = 1;
	while (i < swapper->stack_a.size + 1)
	{
		swapper->stack_a.tab[i] = ft_atoi(argv[i]);
		i++;
	}
}

void	init_stacks(int argc, char **argv, t_swapper *swapper)
{
	swapper->stack_a.size = argc - 1;
	swapper->stack_a.tab = malloc(sizeof(int) * swapper->stack_a.size);
	if (!swapper->stack_a.tab)
		close_program("Malloc failed during tab init");
	swapper->stack_b.size = swapper->stack_a.size;
	swapper->stack_b.tab = malloc(sizeof(int) * swapper->stack_b.size);
	if (!swapper->stack_b.tab)
		close_program("Malloc failed during tab init");
	fill_stacks(argv, swapper);
}

void	check_args(int argc, char **argv, t_swapper *swapper)
{
	int	i;

	i = 1;
	if (argc <= 1)
		close_program("Invalid number of arguments");
	while(i < argc)
	{
		if (!ft_islinenum(argv[i]))
			close_program("Wrong arguments format");
		i++;
	}

}
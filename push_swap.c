/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:34 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/24 16:00:38 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	is_sorted(t_swapper *swapper)
{
	int	i;

	i = 0;
	while (i < swapper->stack_a.size - 1)
	{
		if (swapper->stack_a.tab[i] > swapper->stack_a.tab[i + 1])
			close_program(0);
	}
}

void	print_instru(t_swapper *swapper)
{
	t_list *new;

	new = swapper->instru;
	while (new)
	{
		printf("%s\n", new->content);
		new = new->next;
	}
}

int	main(int argc, char **argv)
{
	t_swapper	swapper;

	printf("salut2");
	check_args(argc, argv, &swapper);
	is_sorted(&swapper);
	push_swap(&swapper);
	print_instru(&swapper);
	close_program(0);
}

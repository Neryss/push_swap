/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:34 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/25 11:15:04 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

	check_args(argc, argv, &swapper);
	if (is_sorted(&swapper))
		close_program(0);
	push_swap(&swapper);
	print_instru(&swapper);
	close_program(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:34 by ckurt             #+#    #+#             */
/*   Updated: 2021/04/01 14:14:24 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_swapper	swapper;

	check_args(argc, argv, &swapper);
	if (is_sorted(&swapper))
		close_program(0);
	push_swap(&swapper);
	close_program(0);
}

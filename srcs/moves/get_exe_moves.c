/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:22:36 by ckurt             #+#    #+#             */
/*   Updated: 2021/04/05 10:57:09 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_moves(t_swapper *swapper)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = ft_gnl(0, &line);
		if (ret == -1)
			close_program(1);
		if (ret == 1)
			execute_moves(swapper, line);
		free(line);
	}
}

static void	some_moves(t_swapper *swapper, char *move)
{
	if (!ft_strcmp(move, "rb"))
		move_rb(swapper);
	else if (!ft_strcmp(move, "rr"))
		move_rr(swapper);
	else if (!ft_strcmp(move, "rra"))
		move_rra(swapper);
	else if (!ft_strcmp(move, "rrb"))
		move_rrb(swapper);
	else if (!ft_strcmp(move, "rrr"))
		move_rrr(swapper);
	else if (!ft_strlen(move))
		close_program(1);
	else
		close_program(1);
}

void	execute_moves(t_swapper *swapper, char *move)
{
	if (!ft_strcmp(move, "sa"))
		move_sa(swapper);
	else if (!ft_strcmp(move, "sb"))
		move_sb(swapper);
	else if (!ft_strcmp(move, "ss"))
		move_ss(swapper);
	else if (!ft_strcmp(move, "pa"))
		move_pa(swapper);
	else if (!ft_strcmp(move, "pb"))
		move_pb(swapper);
	else if (!ft_strcmp(move, "ra"))
		move_ra(swapper);
	else
		some_moves(swapper, move);
}

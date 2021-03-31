/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:16:43 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/31 13:21:16 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	do_move_part1(t_swapper *swapper, char *move)
{
	if (!ft_strcmp(move, "sa"))
	{
		move_sa(swapper);
		ft_putendl("sa");
	}
	else if (!ft_strcmp(move, "sb"))
	{
		move_sb(swapper);
		ft_putendl("sb");
	}
	else if (!ft_strcmp(move, "ss"))
	{
		move_ss(swapper);
		ft_putendl("ss");
	}
	else if (!ft_strcmp(move, "pa"))
	{
		move_pa(swapper);
		ft_putendl("pa");
	}
	else if (!ft_strcmp(move, "pb"))
	{
		move_pb(swapper);
		ft_putendl("pb");
	}
}

static void	do_move_part2(t_swapper *swapper, char *move)
{
	if (!ft_strcmp(move, "ra"))
	{
		move_ra(swapper);
		ft_putendl("ra");
	}
	else if (!ft_strcmp(move, "rb"))
	{
		move_rb(swapper);
		ft_putendl("rb");
	}
	else if (!ft_strcmp(move, "rr"))
	{
		move_rr(swapper);
		ft_putendl("rr");
	}
	else if (!ft_strcmp(move, "rra"))
	{
		move_rra(swapper);
		ft_putendl("rra");
	}
	else if (!ft_strcmp(move, "rrb"))
	{
		move_rrb(swapper);
		ft_putendl("rrb");
	}
}

//TODO : might be problematic later

void	do_move(t_swapper *swapper, char *move)
{
	do_move_part1(swapper, move);
	do_move_part2(swapper, move);
	if (!ft_strcmp(move, "rrr"))
	{
		move_rrr(swapper);
		ft_putendl("rrr");
	}
}

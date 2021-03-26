/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:16:43 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/26 10:17:16 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	do_move_part1(t_swapper *swapper, char *move)
{
	if (!ft_strcmp(move, "sa"))
	{
		move_sa(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("sa")));
	}
	else if (!ft_strcmp(move, "sb"))
	{
		move_sb(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("sb")));
	}
	else if (!ft_strcmp(move, "ss"))
	{
		move_ss(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("ss")));
	}
	else if (!ft_strcmp(move, "pa"))
	{
		move_pa(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("pa")));
	}
	else if (!ft_strcmp(move, "pb"))
	{
		move_pb(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("pb")));
	}
}

static void	do_move_part2(t_swapper *swapper, char *move)
{
	if (!ft_strcmp(move, "ra"))
	{
		move_ra(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("ra")));
	}
	else if (!ft_strcmp(move, "rb"))
	{
		move_rb(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("rb")));
	}
	else if (!ft_strcmp(move, "rr"))
	{
		move_rr(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("rr")));
	}
	else if (!ft_strcmp(move, "rra"))
	{
		move_rra(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("rra")));
	}
	else if (!ft_strcmp(move, "rrb"))
	{
		move_rrb(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("rrb")));
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
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("rrr")));
	}
}

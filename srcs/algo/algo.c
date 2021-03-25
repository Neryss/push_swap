/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:36:24 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/25 13:08:22 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_swapper *swapper)
{
	int	i;

	i = 0;
	while (i < swapper->stack_a.size - 1)
	{
		if (swapper->stack_a.tab[i] > swapper->stack_a.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	do_move(t_swapper *swapper, char *move)
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
	else if (!ft_strcmp(move, "ra"))
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
	else if (!ft_strcmp(move, "rrr"))
	{
		move_rrr(swapper);
		ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup("rrr")));
	}
}

void	three_nb(t_swapper *swapper)
{
	// display_stacks(swapper);
	if ((swapper->stack_a.tab[0] > swapper->stack_a.tab[1])
		&& (swapper->stack_a.tab[0] < swapper->stack_a.tab[2]))
		do_move(swapper, "sa");
	else if (swapper->stack_a.tab[0] > swapper->stack_a.tab[2])
		do_move(swapper, "ra");
	else if (swapper->stack_a.tab[0] < swapper->stack_a.tab[2])
		do_move(swapper, "rra");
}

void	five_nb(t_swapper *swapper)
{
	do_move(swapper, "pb");
	do_move(swapper, "pb");
	three_nb(swapper);
	do_move(swapper, "pa");
	while (!is_sorted(swapper))
		three_nb(swapper);
}

void	push_swap(t_swapper *swapper)
{
	// display_stacks(swapper);
	if (swapper->stack_a.size == 2)
		do_move(swapper, "sa");
	else if (swapper->stack_a.size == 3)
		three_nb(swapper);
	else if (swapper->stack_a.size == 5)
		five_nb(swapper);
	if (!is_sorted(swapper))
		push_swap(swapper);
}

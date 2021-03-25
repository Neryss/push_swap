/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:36:24 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/25 16:39:36 by ckurt            ###   ########lyon.fr   */
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

int	is_b_rev_sorted(t_swapper *swapper)
{
	int	i;

	i = 0;
	while (i < swapper->stack_b.size - 1)
	{
		if (swapper->stack_b.tab[i] < swapper->stack_b.tab[i + 1])
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

t_smallest	find_smallest(t_swapper *swapper)
{
	t_smallest	smallest;
	int	i;

	smallest.nb = swapper->stack_a.tab[0];
	i = 0;
	while (i < swapper->stack_a.size)
	{
		if (swapper->stack_a.tab[i] < smallest.nb)
		{
			smallest.nb = swapper->stack_a.tab[i];
			smallest.index = i;
		}
		i++;
	}
	return (smallest);
}

void	five_nb(t_swapper *swapper)
{
	t_smallest	smallest;

	smallest = find_smallest(swapper);
	while (swapper->stack_a.tab[0] != smallest.nb)
	{
		if (smallest.index > swapper->stack_a.size / 2)
			do_move(swapper, "rra");
		else
			do_move(swapper, "ra");
	}
	do_move(swapper, "pb");
	smallest = find_smallest(swapper);
	while (swapper->stack_a.tab[0] != smallest.nb)
	{
		if (smallest.index > swapper->stack_a.size / 2)
			do_move(swapper, "rra");
		else
			do_move(swapper, "ra");
	}
	do_move(swapper, "pb");
	// display_stacks(swapper);
	while (!is_sorted(swapper))
	{
		if (swapper->stack_a.size == 3)
			three_nb(swapper);
		else if (swapper->stack_a.size == 2)
			do_move(swapper, "sa");
	}
	while (!is_b_rev_sorted(swapper))
	{
		printf("SORTING B\n");
		do_move(swapper, "rb");
	}
	display_stacks(swapper);
	do_move(swapper, "pa");
	printf("HHHHHHHHHHHHHHH\n");
	display_stacks(swapper);
	printf("DDDDDDDDDDDDDDD\n");
	do_move(swapper, "pa");
	display_stacks(swapper);
	while (1)
		;
}

void	push_swap(t_swapper *swapper)
{
	// display_stacks(swapper);
	if (swapper->stack_a.size == 2)
		do_move(swapper, "sa");
	else if (swapper->stack_a.size == 3)
		three_nb(swapper);
	else if (swapper->stack_a.size == 5 || swapper->stack_a.size == 4)
		five_nb(swapper);
	if (!is_sorted(swapper))
		push_swap(swapper);
	// display_stacks(swapper);
}

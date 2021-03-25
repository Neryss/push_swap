/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exe_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:22:36 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/25 14:31:46 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_moves(t_swapper *swapper)
{
	t_list	*lst;
	char	*line;
	int		ret;

	lst = NULL;
	ret = 1;
	while (ret)
	{
		ret = ft_gnl(0, &line);
		if (ret == -1)
			close_program(1);
		if (ret == 0)
		{
			free(line);
			return ;
		}
		if (*line)
		{
			ft_lstadd_back(&swapper->instru, ft_lstnew(ft_strdup(line)));
			free(line);
		}
	}
}

static void	some_moves(t_swapper *swapper, t_list *new)
{
	if (!ft_strcmp(new->content, "rb"))
		move_rb(swapper);
	else if (!ft_strcmp(new->content, "rr"))
		move_rr(swapper);
	else if (!ft_strcmp(new->content, "rra"))
		move_rra(swapper);
	else if (!ft_strcmp(new->content, "rrb"))
		move_rrb(swapper);
	else if (!ft_strcmp(new->content, "rrr"))
		move_rrr(swapper);
	else
	{
		printf("fk");
		close_program(1);
	}
}

void	execute_moves(t_swapper *swapper)
{
	t_list	*new;

	new = swapper->instru;
	while (new)
	{
		if (!ft_strcmp(new->content, "sa"))
			move_sa(swapper);
		else if (!ft_strcmp(new->content, "sb"))
			move_sb(swapper);
		else if (!ft_strcmp(new->content, "ss"))
			move_ss(swapper);
		else if (!ft_strcmp(new->content, "pa"))
			move_pa(swapper);
		else if (!ft_strcmp(new->content, "pb"))
			move_pb(swapper);
		else if (!ft_strcmp(new->content, "ra"))
			move_ra(swapper);
		else
			some_moves(swapper, new);
		if (DEBUG)
			display_stacks(swapper);
		new = new->next;
	}
}

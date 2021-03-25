/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:57:04 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/25 10:24:51 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	close_program(int error)
{
	if (error)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

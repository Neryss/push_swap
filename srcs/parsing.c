/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:35:24 by ckurt             #+#    #+#             */
/*   Updated: 2021/03/22 15:22:38 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	close(char *error)
{
	if (!error)
		exit(0);
	printf("Error\n%s\n", error);
	exit(0);
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 2)
		close("Invalid number of arguments");
	while(i < argc)
	{
		if (!ft_islinenum(argv[i]))
			close("Wrong arguments format");
		i++;
	}
}
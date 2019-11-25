/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:24:47 by pvictor           #+#    #+#             */
/*   Updated: 2019/11/25 16:09:20 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		print_check_1(char **prev, char *next)
{
	if ((ft_strcmp(*prev, "sa") == 0 && ft_strcmp(next, "sb") == 0)
		|| (ft_strcmp(*prev, "sb") == 0 && ft_strcmp(next, "sa") == 0))
		return (0);
	else
		return (1);
}

static int		print_check_2(char **prev, char *next)
{
	if ((ft_strcmp(*prev, "sa") == 0 && ft_strcmp(next, "sa") == 0)
		|| (ft_strcmp(*prev, "sb") == 0 && ft_strcmp(next, "sb") == 0)
		|| (ft_strcmp(*prev, "ra") == 0 && ft_strcmp(next, "rra") == 0)
		|| (ft_strcmp(*prev, "rb") == 0 && ft_strcmp(next, "rrb") == 0)
		|| (ft_strcmp(*prev, "rra") == 0 && ft_strcmp(next, "ra") == 0)
		|| (ft_strcmp(*prev, "rrb") == 0 && ft_strcmp(next, "rb") == 0)
		|| (ft_strcmp(*prev, "pa") == 0 && ft_strcmp(next, "pb") == 0)
		|| (ft_strcmp(*prev, "pb") == 0 && ft_strcmp(next, "pa") == 0))
		return (0);
	else
		return (1);
}

void			print_action(char **prev, char *next)
{
	if (print_check_1(prev, next) == 0)
	{
		ft_putendl("ss");
		*prev = "\0\0\0\0";
	}
	else if ((ft_strcmp(*prev, "ra") == 0 && ft_strcmp(next, "rb") == 0)
		|| (ft_strcmp(*prev, "rb") == 0 && ft_strcmp(next, "ra") == 0))
	{
		ft_putendl("rr");
		*prev = "\0\0\0\0";
	}
	else if ((ft_strcmp(*prev, "rra") == 0 && ft_strcmp(next, "rrb") == 0)
		|| (ft_strcmp(*prev, "rrb") == 0 && ft_strcmp(next, "rra") == 0))
	{
		ft_putendl("rrr");
		*prev = "\0\0\0\0";
	}
	else if (print_check_2(prev, next) == 1)
	{
		if (ft_strcmp(*prev, "\0\0\0\0") != 0)
			ft_putendl(*prev);
		*prev = next;
	}
	else
		*prev = "\0\0\0\0";
}

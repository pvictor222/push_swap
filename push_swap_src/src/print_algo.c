/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:24:47 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 18:37:54 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		cancel_action(char **prev, char *next)
{
	if ((ft_strcmp(*prev, "sa") == 0 && ft_strcmp(next, "sa") == 0)
		|| (ft_strcmp(*prev, "sb") == 0 && ft_strcmp(next, "sb") == 0)
		|| (ft_strcmp(*prev, "ra") == 0 && ft_strcmp(next, "rra") == 0)
		|| (ft_strcmp(*prev, "rb") == 0 && ft_strcmp(next, "rrb") == 0)
		|| (ft_strcmp(*prev, "rra") == 0 && ft_strcmp(next, "ra") == 0)
		|| (ft_strcmp(*prev, "rrb") == 0 && ft_strcmp(next, "rb") == 0)
		|| (ft_strcmp(*prev, "pa") == 0 && ft_strcmp(next, "pb") == 0)
		|| (ft_strcmp(*prev, "pb") == 0 && ft_strcmp(next, "pa") == 0))
		return (1);
	else
		return (0);
}

static int		combine_swap(char **prev, char *next)
{
	if ((ft_strcmp(*prev, "sa") == 0 && ft_strcmp(next, "sb") == 0)
		|| (ft_strcmp(*prev, "sb") == 0 && ft_strcmp(next, "sa") == 0))
		return (1);
	else
		return (0);
}

void			print_action(char **prev, char *next)
{
	if (combine_swap(prev, next) == 1)
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
	else if (!(cancel_action(prev, next) == 1))
	{
		if (ft_strcmp(*prev, "\0\0\0\0") != 0)
			ft_putendl(*prev);
		*prev = next;
	}
	else
		*prev = "\0\0\0\0";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:49:15 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 18:59:11 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		min_0(t_list_ps **pile_a, t_list_ps **pile_b, int i,
				char **prev)
{
	i++;
	rev_b(pile_a, pile_b, prev);
	push_a(pile_a, pile_b, prev);
	rotate_a(pile_a, pile_b, prev);
	return (i);
}

static int		pos_last(t_list_ps **pile_a, t_list_ps **pile_b, int i,
				char **prev)
{
	i++;
	rev_b(pile_a, pile_b, prev);
	push_a(pile_a, pile_b, prev);
	return (i);
}

static int		min_1(t_list_ps **pile_a, t_list_ps **pile_b, int i,
				char **prev)
{
	i++;
	push_a(pile_a, pile_b, prev);
	rotate_a(pile_a, pile_b, prev);
	return (i);
}

static int		pos_0(t_list_ps **pile_a, t_list_ps **pile_b, int i,
				char **prev)
{
	i++;
	push_a(pile_a, pile_b, prev);
	return (i);
}

void			empty_b(t_list_ps **pile_a, t_list_ps **pile_b, int pos,
				char **prev)
{
	int			size;
	int			min;
	int			i;

	i = 0;
	size = nb_node(*pile_b);
	while (i < size && *pile_b)
	{
		min = find_max_pos(pile_b, &pos, 0);
		if (pos == 0)
			i = pos_0(pile_a, pile_b, i, prev);
		else if (min == 1)
			i = min_1(pile_a, pile_b, i, prev);
		else if (pos == nb_node(*pile_b) - 1)
			i = pos_last(pile_a, pile_b, i, prev);
		else if (min == 0)
			i = min_0(pile_a, pile_b, i, prev);
		else if (pos < nb_node(*pile_b) / 2)
			rotate_b(pile_a, pile_b, prev);
		else
			rev_b(pile_a, pile_b, prev);
	}
}

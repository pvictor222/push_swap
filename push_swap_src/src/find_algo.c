/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:24:47 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 18:37:54 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				nb_node(t_list_ps *pile_a)
{
	int			i;
	t_list_ps	*temp;

	i = 0;
	temp = pile_a;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void			sort_two(t_list_ps **pile_a, t_list_ps **pile_b)
{
	if (ft_check_sort_a(pile_a) != 1)
	{
		ft_sa(pile_a, pile_b);
		ft_putendl("sa");
	}
}

/*
**	pivots = [
**	[0]	pivot_a = future pivot of pile_a,
**	[1]	pivot_b = future pivot of pile_b,
**	[2]	is_set_a = 0 if not defined yet, then 1,
**	[3]	is_set_b = 0 if not defined yet, then 1
**	]
*/

void			find_algo(t_list_ps **pile_a, t_list_ps **pile_b)
{
	char		*prev;
	int			*pivots;

	if (!(prev = (char*)malloc(sizeof(char) * 4))
		|| !(pivots = (int*)malloc(sizeof(int) * 4)))
		return ;
	prev = "\0\0\0\0";
	pivots[0] = 0;
	pivots[1] = 0;
	pivots[2] = 0;
	pivots[3] = 0;
	if (!*pile_a || !(*pile_a)->next || ft_check_sort(pile_a, pile_b) == 1)
		return ;
	else if (nb_node(*pile_a) < 3)
		sort_three(pile_a, pile_b);
	else if (nb_node(*pile_a) <= 12)
		sort_small(pile_a, pile_b, &prev);
	else if (nb_node(*pile_a) <= 250)
		sort_default(pile_a, pile_b, &prev);
	else
		sort_big(pile_a, pile_b, &prev);
}

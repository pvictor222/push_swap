/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:57:53 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 18:50:04 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push_below(t_list_ps **pile_a, t_list_ps **pile_b,
				int *tab, char **prev)
{
	int			size;
	int			i;

	i = 0;
	size = nb_node(*pile_a);
	while (i < size && *pile_a)
	{
		if ((*pile_a)->content <= tab[0])
			push_b(pile_a, pile_b, prev);
		else if ((*pile_a)->content <= tab[1])
		{
			push_b(pile_a, pile_b, prev);
			rotate_b(pile_a, pile_b, prev);
		}
		else
			rotate_a(pile_a, pile_b, prev);
		i++;
	}
}

void			empty_last_a(t_list_ps **pile_a, t_list_ps **pile_b,
				char **prev)
{
	int			pos;

	pos = 0;
	while (nb_node(*pile_a) > 3)
	{
		find_min(pile_a, &pos);
		if (pos == 0)
			push_b(pile_a, pile_b, prev);
		else if (pos < nb_node(*pile_a) / 2)
			rotate_a(pile_a, pile_b, prev);
		else
			rev_a(pile_a, pile_b, prev);
	}
}

static void		empty_a(t_list_ps **pile_a, t_list_ps **pile_b,
				char **prev)
{
	int			tab[2];

	tab[0] = find_q1(*pile_a, nb_node(*pile_a));
	tab[1] = find_mediane(*pile_a, nb_node(*pile_a));
	push_below(pile_a, pile_b, tab, prev);
	tab[0] = find_mediane(*pile_a, nb_node(*pile_a));
	tab[1] = find_max(pile_a);
	push_below(pile_a, pile_b, tab, prev);
}

void			sort_default(t_list_ps **pile_a, t_list_ps **pile_b,
				char **prev)
{
	while (ft_check_sort(pile_a, pile_b) != 1)
	{
		if (ft_check_sort(&((*pile_a)->next->next), pile_b) == 1
				&& (*pile_a)->content < (*pile_a)->next->next->content
				&& (*pile_a)->next->content < (*pile_a)->next->next->content)
		{
			sort_two(pile_a, pile_b, prev);
			return ;
		}
		empty_a(pile_a, pile_b, prev);
		sort_three(pile_a, pile_b, prev);
		empty_b(pile_a, pile_b, 0, prev);
		while (ft_check_sort(pile_a, pile_b) != 1)
			rev_a(pile_a, pile_b, prev);
	}
	ft_putendl(*prev);
}

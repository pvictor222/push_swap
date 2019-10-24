/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:22:05 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 12:39:12 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		empty_b_small(t_list_ps **pile_a, t_list_ps **pile_b)
{
	t_list_ps	*temp;

	temp = *pile_b;
	while (temp)
	{
		temp = temp->next;
		ft_pa(pile_a, pile_b);
		ft_putendl("pa");
	}
}

void			sort_small(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	// int			pos;

	// pos = 0;
	while (ft_check_sort(pile_a, pile_b) != 1)
	{
		if (ft_check_sort(&((*pile_a)->next->next), pile_b) == 1
				&& (*pile_a)->content < (*pile_a)->next->next->content
				&& (*pile_a)->next->content < (*pile_a)->next->next->content)
		{
			sort_two(pile_a, pile_b);
			return ;
		}
		while (nb_node(*pile_a) > 3)
			empty_last_a(pile_a, pile_b, prev);
		sort_three(pile_a, pile_b);
		empty_b_small(pile_a, pile_b);
	}
}

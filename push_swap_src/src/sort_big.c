/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 10:57:52 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 12:21:59 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_big(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	while (ft_check_sort(pile_a, pile_b) != 1)
	{
		if (ft_check_sort(&((*pile_a)->next->next), pile_b) == 1
				&& (*pile_a)->content < (*pile_a)->next->next->content
				&& (*pile_a)->next->content < (*pile_a)->next->next->content)
		{
			sort_two(pile_a, pile_b);
			return ;
		}
		empty_a_big(pile_a, pile_b, prev);
		sort_three(pile_a, pile_b);
		empty_b(pile_a, pile_b, 0, prev);
		while (ft_check_sort(pile_a, pile_b) != 1)
			rev_a(pile_a, pile_b, prev);
	}
	ft_putendl(*prev);
}

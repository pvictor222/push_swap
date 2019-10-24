/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:21:55 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/21 17:13:59 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Cases (in sort_three_cases.c):
**	0. {1,2,3} --> nothing to be done
**	1. {3,2,1} --> sa + rra
**	2. {3,1,2} --> ra
**	3. {2,1,3} --> sa
**	4. {1,3,2} --> rra + sa
**	5. {2,3,1} --> rra
*/

void			sort_three(t_list_ps **pile_a, t_list_ps **pile_b)
{
	if (ft_check_sort_a(pile_a) == 1)
		return ;
	else if (nb_node(*pile_a) == 2)
		sort_two(pile_a, pile_b);
	else
	{
		if ((*pile_a)->content > (*pile_a)->next->content)
		{
			if ((*pile_a)->next->content > (*pile_a)->next->next->content)
				case_1(pile_a, pile_b);
			else if ((*pile_a)->content > (*pile_a)->next->next->content)
				case_2(pile_a, pile_b);
			else
				case_3(pile_a, pile_b);
		}
		else if ((*pile_a)->content < (*pile_a)->next->next->content)
			case_4(pile_a, pile_b);
		else
			case_5(pile_a, pile_b);
	}
}

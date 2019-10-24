/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:17:04 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/21 18:18:08 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_a(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_pa(pile_a, pile_b);
	print_action(prev, "pa");
}

void		rotate_a(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_ra(pile_a, pile_b);
	print_action(prev, "ra");
}

void		rev_a(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_rra(pile_a, pile_b);
	print_action(prev, "rra");
}

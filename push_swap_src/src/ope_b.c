/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:19:30 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/21 18:21:15 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_b(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_pb(pile_a, pile_b);
	print_action(prev, "pb");
}

void		rotate_b(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_rb(pile_a, pile_b);
	print_action(prev, "rb");
}

void		rev_b(t_list_ps **pile_a, t_list_ps **pile_b, char **prev)
{
	ft_rrb(pile_a, pile_b);
	print_action(prev, "rrb");
}

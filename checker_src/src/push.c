/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:54:50 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/17 18:06:06 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		push_piles(t_list_ps **dest, t_list_ps **src)
{
	t_list_ps	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	ft_lstadd_ps(dest, temp);
}

void			ft_pa(t_list_ps **pile_a, t_list_ps **pile_b)
{
	(void)pile_b;
	push_piles(pile_a, pile_b);
}

void			ft_pb(t_list_ps **pile_a, t_list_ps **pile_b)
{
	(void)pile_a;
	push_piles(pile_b, pile_a);
}

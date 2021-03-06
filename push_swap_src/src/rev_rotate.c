/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:18:26 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/17 18:13:17 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		rev_pile(t_list_ps **pile)
{
	t_list_ps	*temp;
	t_list_ps	*buf;

	if (!(*pile) || !(*pile)->next)
		return ;
	temp = *pile;
	buf = *pile;
	while (temp->next)
		temp = temp->next;
	while (buf->next->next)
		buf = buf->next;
	temp->next = *pile;
	*pile = temp;
	buf->next = NULL;
}

void		ft_rra(t_list_ps **pile_a, t_list_ps **pile_b)
{
	(void)pile_b;
	rev_pile(pile_a);
}

void		ft_rrb(t_list_ps **pile_a, t_list_ps **pile_b)
{
	(void)pile_a;
	rev_pile(pile_b);
}

void		ft_rrr(t_list_ps **pile_a, t_list_ps **pile_b)
{
	rev_pile(pile_a);
	rev_pile(pile_b);
}

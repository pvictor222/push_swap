/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:58:27 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/17 18:11:44 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			rotate_pile(t_list_ps **pile)
{
	t_list_ps	*temp;
	t_list_ps	*buf;

	if (!(*pile) || !(*pile)->next)
		return ;
	temp = *pile;
	buf = *pile;
	while (temp->next)
		temp = temp->next;
	*pile = (*pile)->next;
	temp->next = buf;
	buf->next = NULL;
}

void			ft_ra(t_list_ps **pile_a, t_list_ps **pile_b)
{
	(void)pile_b;
	rotate_pile(pile_a);
}

void			ft_rb(t_list_ps **pile_a, t_list_ps **pile_b)
{
	(void)pile_a;
	rotate_pile(pile_b);
}

void			ft_rr(t_list_ps **pile_a, t_list_ps **pile_b)
{
	rotate_pile(pile_a);
	rotate_pile(pile_b);
}

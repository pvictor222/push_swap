/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:11:39 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/12 18:57:51 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		swap_pile(t_list_ps **pile)
{
	t_list_ps	*temp;
	t_list_ps	*head;

	head = (*pile)->next;
	temp = *pile;
	temp->next = head->next;
	head->next = temp;
	*pile = head;
}

void			ft_sa(t_list_ps **pile_a, t_list_ps **pile_b)
{
	(void)pile_b;
	if (*pile_a && (*pile_a)->next)
		swap_pile(pile_a);
}

void			ft_sb(t_list_ps **pile_a, t_list_ps **pile_b)
{
	(void)pile_a;
	if (*pile_b && (*pile_b)->next)
		swap_pile(pile_b);
}

void			ft_ss(t_list_ps **pile_a, t_list_ps **pile_b)
{
	if (*pile_a && (*pile_a)->next)
		swap_pile(pile_a);
	if (*pile_b && (*pile_b)->next)
		swap_pile(pile_b);
}

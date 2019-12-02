/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:58:28 by pvictor           #+#    #+#             */
/*   Updated: 2019/11/25 17:58:29 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				free_pile(t_list_ps **pile)
{
	t_list_ps		*temp;

	if (*pile)
	{
		temp = *pile;
		while (temp != NULL)
		{
			*pile = temp;
			temp = temp->next;
			free(*pile);
			*pile = NULL;
		}
	}
}

void				free_piles(t_list_ps **pile_a, t_list_ps **pile_b)
{
	free_pile(pile_a);
	free_pile(pile_b);
}
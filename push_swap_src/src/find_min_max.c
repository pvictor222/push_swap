/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvictor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:13:12 by pvictor           #+#    #+#             */
/*   Updated: 2019/04/22 18:37:52 by pvictor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				find_max(t_list_ps **pile_a)
{
	t_list_ps	*temp;
	int			max;

	temp = *pile_a;
	max = temp->content;
	while (temp)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return (max);
}

int				find_max_pos(t_list_ps **pile_a, int *pos, int i)
{
	t_list_ps	*temp;
	int			max;
	int			min;
	int			last;

	temp = *pile_a;
	max = temp->content;
	min = temp->content;
	*pos = 0;
	while (temp)
	{
		if (temp->content > max)
		{
			max = temp->content;
			*pos = i;
		}
		if (temp->content < min)
			min = temp->content;
		i++;
		last = temp->content;
		temp = temp->next;
	}
	if (min == last)
		return (0);
	return (min == (*pile_a)->content ? 1 : -1);
}

void			find_min(t_list_ps **pile_a, int *pos)
{
	t_list_ps	*temp;
	int			i;
	int			min;

	temp = *pile_a;
	min = temp->content;
	*pos = 0;
	i = 0;
	while (temp)
	{
		if (temp->content < min)
		{
			min = temp->content;
			*pos = i;
		}
		i++;
		temp = temp->next;
	}
}
